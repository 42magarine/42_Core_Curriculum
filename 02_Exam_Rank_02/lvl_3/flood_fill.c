/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:36:31 by mott              #+#    #+#             */
/*   Updated: 2023/12/13 16:28:44 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : flood_fill
// Expected files   : flood_fill.c
// Allowed functions: -
// --------------------------------------------------------------------------------

// Write a function that takes a char ** as a 2-dimensional array of char, a
// t_point as the dimensions of this array and a t_point as the starting point.

// Starting from the given 'begin' t_point, this function fills an entire zone
// by replacing characters inside with the character 'F'. A zone is an group of
// the same character delimitated horizontally and vertically by other characters
// or the array boundry.

// The flood_fill function won't fill diagonally.

// The flood_fill function will be prototyped like this:
//   void  flood_fill(char **tab, t_point size, t_point begin);

// The t_point structure is prototyped like this: (put it in flood_fill.c)

//   typedef struct  s_point
//   {
//     int           x;
//     int           y;
//   }               t_point;

// Example:

// $> cat test.c
// #include <stdlib.h>
// #include <stdio.h>

// char** make_area(char** zone, t_point size)
// {
// 	char** new;

// 	new = malloc(sizeof(char*) * size.y);
// 	for (int i = 0; i < size.y; ++i)
// 	{
// 		new[i] = malloc(size.x + 1);
// 		for (int j = 0; j < size.x; ++j)
// 			new[i][j] = zone[i][j];
// 		new[i][size.x] = '\0';
// 	}

// 	return new;
// }

// int main(void)
// {
// 	t_point size = {8, 5};
// 	char *zone[] = {
// 		"11111111",
// 		"10001001",
// 		"10010001",
// 		"10110001",
// 		"11100001",
// 	};

// 	char**  area = make_area(zone, size);
// 	for (int i = 0; i < size.y; ++i)
// 		printf("%s\n", area[i]);
// 	printf("\n");

// 	t_point begin = {7, 4};
// 	flood_fill(area, size, begin);
// 	for (int i = 0; i < size.y; ++i)
// 		printf("%s\n", area[i]);
// 	return (0);
// }

// $> gcc flood_fill.c test.c -o test; ./test
// 11111111
// 10001001
// 10010001
// 10110001
// 11100001

// FFFFFFFF
// F000F00F
// F00F000F
// F0FF000F
// FFF0000F
// $>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

void	fill_zone(char **tab, t_point size, t_point current, char target)
{
	if (current.x < 0 || current.y < 0 || current.x >= size.x || current.y >= size.y || tab[current.y][current.x] != target)
		return ;
	tab[current.y][current.x] = 'F';
	fill_zone(tab, size, (t_point){current.x + 1, current.y}, target);
	fill_zone(tab, size, (t_point){current.x - 1, current.y}, target);
	fill_zone(tab, size, (t_point){current.x, current.y + 1}, target);
	fill_zone(tab, size, (t_point){current.x, current.y - 1}, target);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	if (tab == 0 || size.x <= 0 || size.y <= 0 || begin.x < 0 || begin.y < 0 || begin.x >= size.x || begin.y >= size.y)
		return ;
	fill_zone(tab, size, begin, tab[begin.y][begin.x]);
}

// #include <stdlib.h>
// #include <stdio.h>

// int	main(void)
// {
// 	t_point	size = {12, 12};
// 	t_point	begin = {0, 0};
// 	char	*zone[] = {
// 		"xooooooooooo",
// 		"xooooxxxxxxo",
// 		"xooooxoxxoxo",
// 		"xooooxxxxxxo",
// 		"xxxxxxoooooo",
// 		"oooooxoooooo",
// 		"oooooxoooooo",
// 		"oxoooxoxxxxx",
// 		"oxoooxxxoooo",
// 		"xxxxxxxxoooo",
// 		"xoooooooooxo",
// 		"xooooooooooo",
// 	};
// 	char	**area = malloc(sizeof(char *) * size.y);
// 	for (int i = 0; i < size.y; i++)
// 	{
// 		area[i] = malloc(size.x + 1);
// 		for (int j = 0; j < size.x; j++)
// 			area[i][j] = zone[i][j];
// 		area[i][size.x] = '\0';
// 	}
// 	flood_fill(area, size, begin);
// 	for (int i = 0; i < size.y; i++)
// 		printf("%s\n", area[i]);
// 	for (int i = 0; i < size.y; i++)
// 		free(area[i]);
// 	free(area);
// 	return (0);
// }
