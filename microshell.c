/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:27:36 by mott              #+#    #+#             */
/*   Updated: 2024/05/28 14:53:29 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : microshell
// Expected files   : microshell.c
// Allowed functions: malloc, free, write, close, fork, waitpid, signal, kill,
// exit, chdir, execve, dup, dup2, pipe, strcmp, strncmp
// -----------------------------------------------------------------------------

// Write a program that will behave like executing a shell command

// - The command line to execute will be the arguments of this program

// - Executable's path will be absolute or relative but your program must not
//   build a path (from the PATH variable for example)

// - You must implement "|" and ";" like in bash
//   - we will never try a "|" immediately followed or preceded by nothing
//     or "|" or ";"

// - Your program must implement the built-in command cd only with a path as
//   argument (no '-' or without parameters)
//   - if cd has the wrong number of argument your program should print in
//     STDERR "error: cd: bad arguments" followed by a '\n'
//   - if cd failed your program should print in STDERR "error: cd: cannot
//     change directory to path_to_change" followed by a '\n' with
//     path_to_change replaced by the argument to cd
//   - a cd command will never be immediately followed or preceded by a "|"

// - You don't need to manage any type of wildcards (*, ~ etc...)

// - You don't need to manage environment variables ($BLA ...)

// - If a system call, except execve and chdir, returns an error your program
//   should immediatly print "error: fatal" in STDERR followed by a '\n' and the
//   program should exit

// - If execve failed you should print "error: cannot execute
//   executable_that_failed" in STDERR followed by a '\n' with
//   executable_that_failed replaced with the path of the failed executable
//   (It should be the first argument of execve)

// - Your program should be able to manage more than hundreds of "|" even if we
//   limit the number of "open files" to less than 30.

// for example this should work:
// $>./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my
// microshell
// microshell
// i love my microshell
// $>

// Hints:
// Don't forget to pass the environment variable to execve

// Hints:
// Do not leak file descriptors!

#include <stdlib.h>		// exit
#include <unistd.h>		// write, close, fork, chdir, execve, dup2, pipe
#include <sys/wait.h>	// waitpid
#include <string.h>		// strcmp

void	ft_putstr_stderr(char *str)
{
	while (*str != '\0')
		write(STDERR_FILENO, str++, 1);
}

void	ft_exit(void)
{
	ft_putstr_stderr("error: fatal\n");
	exit(EXIT_FAILURE);
}

void	ft_exec_cd(int argc, char **argv)
{
	if (argc != 2)
		ft_putstr_stderr("error: cd: bad arguments\n");
	else if (chdir(argv[1]) == -1)
	{
		ft_putstr_stderr("error: cd: cannot change directory to ");
		ft_putstr_stderr(argv[1]);
		ft_putstr_stderr("\n");
	}
}

void	ft_execute(int argc, char **argv, char **envp)
{
	argv[argc] = NULL;
	if (execve(argv[0], argv, envp) == -1)
	{
		ft_putstr_stderr("error: cannot execute ");
		ft_putstr_stderr(argv[0]);
		ft_putstr_stderr("\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_exec_cmd(int argc, char **argv, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_exit();
	else if (pid == 0)
		ft_execute(argc, argv, envp);
	waitpid(pid, NULL, 0);
}

void	ft_exec_pipe(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		ft_exit();
	pid = fork();
	if (pid == -1)
		ft_exit();
	else if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		ft_execute(argc, argv, envp);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	waitpid(pid, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int	start;
	int	stop;

	start = 0;
	while (++start < argc)
	{
		stop = start;
		while (stop < argc && strcmp(argv[stop], ";") != 0 && strcmp(argv[stop], "|") != 0)
			stop++;
		if (strcmp(argv[start], "cd") == 0)
			ft_exec_cd(stop - start, &argv[start]);
		else if (start < stop && (stop == argc || strcmp(argv[stop], ";") == 0))
			ft_exec_cmd(stop - start, &argv[start], envp);
		else if (start < stop && strcmp(argv[stop], "|") == 0)
			ft_exec_pipe(stop - start, &argv[start], envp);
		start = stop;
	}
	return (EXIT_SUCCESS);
}
