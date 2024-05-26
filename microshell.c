/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:27:36 by mott              #+#    #+#             */
/*   Updated: 2024/05/26 17:31:44 by mott             ###   ########.fr       */
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

#include <stdlib.h>		// malloc, free, exit
#include <unistd.h>		// write, close, fork, chdir, execve, dup, dup2, pipe
#include <sys/wait.h>	// waitpid
#include <signal.h>		// signal, kill
#include <string.h>		// strcmp, strncmp

typedef enum e_error
{
	FATAL,
	EXECVE,
	CD1,
	CD2
}	t_error;

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	if (str == NULL)
		return ;
	while (*str != '\0')
		ft_putchar_fd(*str++, fd);
}

void	ft_error(int error, char *str)
{
	if (error == FATAL)
		ft_putstr_fd("error: fatal\n", STDERR_FILENO);
	else if (error == EXECVE)
	{
		ft_putstr_fd("error: cannot execute ", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
	}
	else if (error == CD1)
		ft_putstr_fd("error: cd: bad arguments\n", STDERR_FILENO);
	else if (error == CD2)
	{
		ft_putstr_fd("error: cd: cannot change directory to ", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
	}
	exit(EXIT_FAILURE);
}

void	executor(char **argv, char **envp)
{
	if (execve(argv[0], argv, envp) == -1)
		ft_error(EXECVE, argv[1]);
}

void	print_argv(int argc, char **argv)
{
	int	i;

	i = 0;
	ft_putstr_fd("------------\n", STDOUT_FILENO);
	while (++i < argc)
	{
		ft_putstr_fd(argv[i], STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
	ft_putstr_fd("------------\n", STDOUT_FILENO);
}

int	main(int argc, char **argv, char **envp)
{
	int	i;

	print_argv(argc, argv);
	i = 0;
	while (++i < argc)
	{
		if (strcmp(argv[i], ";") == 0)
			i++;
		executor(&argv[i], envp);
	}
	return (EXIT_SUCCESS);
}
