/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:32:21 by mott              #+#    #+#             */
/*   Updated: 2024/04/19 21:42:58 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	count_heredoc(t_ast *ast)
{
	int	i;
	int	heredoc;

	i = 0;
	heredoc = 0;
	while (ast->cmd->redir[i] != NULL)
	{
		if (ast->cmd->redir[i]->type == REDIR_HEREDOC)
			heredoc++;
		i++;
	}
	return (heredoc);
}

int	exec_here_doc(t_mini *mini, char *limiter)
{
	int		fd[2];
	char	*line;

	limiter = ft_strjoin(limiter, "\n");
	ft_pipe(fd);
	while (true)
	{
		ft_putstr_fd(PROMPT_MULTI_LINE, mini->fd_stdout);
		line = get_next_line(mini->fd_stdin);
		if (ft_strcmp(line, limiter) == 0)
			break ;
		ft_putstr_fd(line, fd[1]);
		free(line);
	}
	get_next_line(-1);
	free(line);
	free(limiter);
	close(fd[1]);
	return (fd[0]);
}
