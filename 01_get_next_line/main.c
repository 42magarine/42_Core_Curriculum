/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:40:35 by mott              #+#    #+#             */
/*   Updated: 2023/11/17 13:55:05 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		n;
	char	*next_line;

	fd = open("./test.txt", O_RDONLY);
	n = 0;
	do
	{
		next_line = get_next_line(fd);
		printf("line[%02d]: %s", n, next_line);
		free(next_line);
		n++;
	} while (next_line != NULL);
	close(fd);
	printf("\n");
	return (0);
}

// system("leaks a.out");

// STDIN_FILENO		0	/* standard input file descriptor */
// STDOUT_FILENO	1	/* standard output file descriptor */
// STDERR_FILENO	2	/* standard error file descriptor */

// O_RDONLY		open for reading only
// O_WRONLY		open for writing only
// O_RDWR		open for reading and writing

// docker run -ti -v $(PWD):/memory-test memory-test bash -c "cd /memory-test; cc -g -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c && valgrind --leak-check=yes ./a.out"
// docker run							Starts a new Docker container
// -ti									Opens an interactive terminal
// -v /host/path:/container/path		This option mounts the /host/part/ on your host machine to the /container/path inside the Docker container
// memory-test							The name of the Docker image you're running
// bash-c ""							Execute a command in the Bash shell
// -c ""								This option tells Bash to read and execute commands from the following string
