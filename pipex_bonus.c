/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:23:03 by mott              #+#    #+#             */
/*   Updated: 2024/01/23 16:35:42 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// user input should be:
// ./pipex_bonus file1 cmd1 ... cmdn file2
// ./pipex_bonus here_doc LIMITER cmd1 ... cmdn file2
int	main(int argc, char **argv, char **envp)
{
	int		here_doc;
	int		i;

	here_doc = ft_here_doc_there(argv[1]);
	if (argc < 5 + here_doc)
		ft_error("not enough arguments!\n", ERR_USER);
	i = 2 + here_doc;
	ft_setup_frist_command(argv, envp, i++);
	while (i < argc - 2)
		ft_setup_next_command(argv, envp, i++);
	ft_setup_last_command(argv, envp, i);
	return (0);
}

// creates a pipe, a child process with fork, opens the input file
// and redirects input and output with dup2
void	ft_setup_frist_command(char **argv, char **envp, int i)
{
	int		fd_file;
	int		fd_pipe[2];
	pid_t	pid;

	if (pipe(fd_pipe) == -1)
		ft_error("pipe", ERR_SYSTEM);
	pid = fork();
	if (pid == -1)
		ft_error("fork", ERR_SYSTEM);
	else if (pid == 0)
	{
		close(fd_pipe[0]);
		fd_file = ft_open_file(argv, i);
		if (dup2(fd_file, STDIN_FILENO) == -1)
			ft_error("dup2", ERR_SYSTEM);
		close(fd_file);
		if (dup2(fd_pipe[1], STDOUT_FILENO) == -1)
			ft_error("dup2", ERR_SYSTEM);
		close(fd_pipe[1]);
		ft_execute_program(argv[i], envp);
	}
	close(fd_pipe[1]);
	if (dup2(fd_pipe[0], STDIN_FILENO) == -1)
		ft_error("dup2", ERR_SYSTEM);
	close(fd_pipe[0]);
}

// creates a pipe, a child porcess with fork
// and redirects input and output with dup2
void	ft_setup_next_command(char **argv, char **envp, int i)
{
	int		fd_pipe[2];
	pid_t	pid;

	if (pipe(fd_pipe) == -1)
		ft_error("pipe", ERR_SYSTEM);
	pid = fork();
	if (pid == -1)
		ft_error("fork", ERR_SYSTEM);
	else if (pid == 0)
	{
		close(fd_pipe[0]);
		if (dup2(fd_pipe[1], STDOUT_FILENO) == -1)
			ft_error("dup2", ERR_SYSTEM);
		close(fd_pipe[1]);
		ft_execute_program(argv[i], envp);
	}
	close(fd_pipe[1]);
	if (dup2(fd_pipe[0], STDIN_FILENO) == -1)
		ft_error("dup2", ERR_SYSTEM);
	close(fd_pipe[0]);
}

// creates a child process with fork, opens or creates the output file
// and redirects input and output with dup2
void	ft_setup_last_command(char **argv, char **envp, int i)
{
	int		fd_file;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_error("fork", ERR_SYSTEM);
	else if (pid == 0)
	{
		fd_file = ft_open_file(argv, i);
		if (dup2(fd_file, STDOUT_FILENO) == -1)
			ft_error("dup2", ERR_SYSTEM);
		close(fd_file);
		ft_execute_program(argv[i], envp);
	}
	waitpid(pid, NULL, 0);
}

// creates the arguments for execve and executes it
void	ft_execute_program(char *argv, char **envp)
{
	char	**cmdv;
	char	**pathv;
	char	*path;

	cmdv = ft_split(argv, ' ');
	if (cmdv == NULL)
		ft_error("malloc", ERR_SYSTEM);
	pathv = ft_parse_envp(envp);
	if (pathv == NULL)
		ft_error("no PATH found!\n", ERR_USER);
	path = ft_find_cmd(cmdv[0], pathv);
	ft_free_strs(pathv);
	if (path == NULL)
	{
		ft_free_strs(cmdv);
		ft_error("command not found!\n", ERR_USER);
	}
	if (execve(path, cmdv, envp) == -1)
		ft_error("execve", ERR_SYSTEM);
}
