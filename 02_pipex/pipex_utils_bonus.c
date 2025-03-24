/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:00:59 by mott              #+#    #+#             */
/*   Updated: 2024/01/23 15:40:28 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// opens input or output file or set here_doc
int	ft_open_file(char **argv, int i)
{
	int	fd_file;

	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		if (i == 3)
			fd_file = ft_handle_here_doc(argv[2]);
		else
			fd_file = open(argv[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		if (i == 2)
			fd_file = open(argv[1], O_RDONLY);
		else
			fd_file = open(argv[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (fd_file == -1)
		ft_error("open", ERR_SYSTEM);
	return (fd_file);
}

// searches for PATH in envp and spilts it into substings
char	**ft_parse_envp(char **envp)
{
	char	**pathv;
	int		i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			pathv = ft_split(envp[i] + 5, ':');
			if (pathv == NULL)
				ft_error("malloc", ERR_SYSTEM);
			return (pathv);
		}
		i++;
	}
	return (NULL);
}

// prepares the command-sting and checks if it exists and can be executed
char	*ft_find_cmd(char *cmd, char **pathv)
{
	char	*path;
	char	*temp;
	int		i;

	i = 0;
	while (pathv[i] != NULL)
	{
		temp = ft_strjoin(pathv[i], "/");
		if (temp == NULL)
			ft_error("malloc", ERR_SYSTEM);
		path = ft_strjoin(temp, cmd);
		if (path == NULL)
			ft_error("malloc", ERR_SYSTEM);
		free(temp);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

// writes error message and terminates the program
void	ft_error(char *str, int error)
{
	if (error == ERR_SYSTEM)
	{
		perror(str);
		exit(EXIT_FAILURE);
	}
	if (error == ERR_USER)
	{
		ft_putstr_fd(str, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

// frees memory
void	ft_free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
		free(strs[i++]);
	free(strs);
}
