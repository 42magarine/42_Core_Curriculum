/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:26:57 by mott              #+#    #+#             */
/*   Updated: 2024/04/07 20:32:41 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*create_absolute_path(char *pathname)
{
	struct stat	statbuf;

	stat(pathname, &statbuf);
	if (S_ISDIR(statbuf.st_mode) == true)
	{
		ft_perror(pathname, "is a directory");
		exit(126);
	}
	if (access(pathname, X_OK) == -1)
	{
		ft_perror(pathname, strerror(errno));
		if (errno == 13)
			exit(126);
		else
			exit(127);
	}
	return (pathname);
}

char	*create_relative_path(char *command, t_env *env)
{
	char	**path;
	char	*pathname;

	path = split_path(command, env);
	pathname = find_pathname(path);
	free_char_array(path);
	if (pathname == NULL)
	{
		ft_perror(command, "command not found");
		exit(127);
	}
	return (pathname);
}

char	**split_path(char *command, t_env *env)
{
	char	**path;
	char	*temp;
	int		i;

	while (env != NULL)
	{
		if (ft_strcmp(env->key, "PATH") == 0)
			temp = env->value;
		env = env->next;
	}
	path = ft_split(temp, ':');
	i = 0;
	while (path[i] != NULL)
	{
		temp = path[i];
		path[i] = ft_strjoin(temp, "/");
		free(temp);
		temp = path[i];
		path[i] = ft_strjoin(temp, command);
		free(temp);
		i++;
	}
	return (path);
}

char	*find_pathname(char **path)
{
	int	i;

	i = 0;
	while (path[i] != NULL)
	{
		if (access(path[i], X_OK) == 0)
			return (ft_strdup(path[i]));
		i++;
	}
	return (NULL);
}
