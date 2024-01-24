/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:47:31 by mott              #+#    #+#             */
/*   Updated: 2024/01/23 15:30:47 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>

# ifndef ERR_SYSTEM
#  define ERR_SYSTEM 0
# endif

# ifndef ERR_USER
#  define ERR_USER 1
# endif

// pipex.c
int		main(int argc, char **argv, char **envp);
void	ft_setup_first_command(char **argv, char **envp, int i);
void	ft_setup_last_command(char **argv, char **envp, int i);
void	ft_execute_program(char *argv, char **envp);

// pipex_utils.c
int		ft_open_file(char **argv, int i);
char	**ft_parse_envp(char **envp);
char	*ft_find_cmd(char *cmd, char **pathv);
void	ft_error(char *str, int error);
void	ft_free_strs(char **strs);

#endif

// open <fcntl.h > - open and possibly create a file
// close <unistd.h> - close a file descriptor
// read <unistd.h> - read from a file descriptor
// write <unistd.h> - write to a file descriptor
// malloc, free <stdlib.h> - allocate and free dynamic memory
// perror <stdio.h> - print a system error message
// strerror <string.h> - return string describing error number
// access <unistd.h> - check user's permissions for a file
// dup, dup2 <unistd.h> - duplicate a file descriptor
// execve <unistd.h> - execute program
// exit <stdlib.h> - cause normal process termination
// fork <unistd.h> - create a child process
// pipe <unistd.h> - create pipe
// unlink <unistd.h> - delete a name and possibly the file it refers to
// wait, waitpid <sys/wait.h> - wait for process to change state

// < is used to redirect the content of a file into a command as input
// > is used to create or overwrite a file with the output of a command.
// useful shell commands: which <cmd>, env

// < file1 cmd1 | cmd2 > file2
// < file1 sort | grep ea > file2
// < Makefile tr A-Z a-z | nl > file2

// ./pipex file1 cmd1 cmd2 file2
// ./pipex file1 sort "grep ea" file2
// ./pipex Makefile "tr A-Z a-z" nl file2

// filename file1 cmd1 cmd2 file2
// 0        1     2    3    4
// argc = 5
