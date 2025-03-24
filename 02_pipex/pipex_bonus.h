/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:23:23 by mott              #+#    #+#             */
/*   Updated: 2024/01/23 15:15:13 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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

// pipex_bonus.c
int		main(int argc, char **argv, char **envp);
void	ft_setup_frist_command(char **argv, char **envp, int i);
void	ft_setup_next_command(char **argv, char **envp, int i);
void	ft_setup_last_command(char **argv, char **envp, int i);
void	ft_execute_program(char *argv, char **envp);

// pipex_utils_bonus.c
int		ft_open_file(char **argv, int i);
char	**ft_parse_envp(char **envp);
char	*ft_find_cmd(char *cmd, char **pathv);
void	ft_error(char *str, int error);
void	ft_free_strs(char **strs);

// pipex_heredoc_bonus.c
int		ft_here_doc_there(char *argv);
int		ft_handle_here_doc(char *limiter);

#endif

// << is used to provide input directly within the command or script
// >> is used to append the output to an existing file.

// < file1 cmd1 | ... | cmdn > file2
// < file1 sort | uniq -c | sort -r | head -3 > file2
// < file1 sleep 3 | sleep 3 | sleep 3 > file2

// ./pipex_bonus file1 cmd1 ... cmdn file2
// ./pipex_bonus file1 sort "uniq -c" "sort -r" "head -3" file2
// ./pipex_bonus file1 "sleep 3" "sleep 3" "sleep 3" file2

// cmd1 << LIMITER | cmd2 >> file2
// cat << END | cat >> file_out

// ./pipex_bonus here_doc LIMITER cmd1 cmd2 file2
// ./pipex_bonus here_doc END cat cat file2
// ./pipex_bonus here_doc stop "tr A-Z a-z" nl cat file2

// filename here_doc LIMITER cmd1 cmd2 file2
// 0        1        2       3    4    5
// argc >= 6

// https://www.rozmichelle.com/pipes-forks-dups/
