/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_heredoc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:35:04 by mott              #+#    #+#             */
/*   Updated: 2024/03/26 19:59:08 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// checks if here_doc is used
int	ft_here_doc_there(char *argv)
{
	if (argv != NULL && ft_strncmp(argv, "here_doc", 9) == 0)
		return (1);
	else
		return (0);
}

// reads the input with gnl until LIMITER and sends it to the first pipe
int	ft_handle_here_doc(char *limiter)
{
	int		fd_pipe[2];
	char	*line;

	if (pipe(fd_pipe) == -1)
		ft_error("pipe", ERR_SYSTEM);
	limiter = ft_strjoin(limiter, "\n");
	if (limiter == NULL)
		ft_error("malloc", ERR_SYSTEM);
	while (42)
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			free(line);
			free(limiter);
			break ;
		}
		ft_putstr_fd(line, fd_pipe[1]);
		free(line);
	}
	close(fd_pipe[1]);
	return (fd_pipe[0]);
}
