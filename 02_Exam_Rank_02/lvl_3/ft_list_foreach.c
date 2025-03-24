/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:53:27 by mott              #+#    #+#             */
/*   Updated: 2024/01/09 18:45:14 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : ft_list_foreach
// Expected files   : ft_list_foreach.c, ft_list.h
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that takes a list and a function pointer, and applies this
// function to each element of the list.

// It must be declared as follows:

// void    ft_list_foreach(t_list *begin_list, void (*f)(void *));

// The function pointed to by f will be used as follows:

// (*f)(list_ptr->data);

// You must use the following structure, and turn it in as a file called
// ft_list.h:

// typedef struct    s_list
// {
//     struct s_list *next;
//     void          *data;
// }                 t_list;

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list != (void*)0)
	{
		f(begin_list->data);
		begin_list = begin_list->next;
	}
}

// #include <unistd.h>
// #include <stdlib.h>

// void	ft_putchar(int c)
// {
// 	write(STDOUT_FILENO, &c, 1);
// }

// void	ft_putstr(char *str)
// {
// 	while (*str != '\0')
// 		ft_putchar(*str++);
// }

// t_list	*ft_new_element(void *data)
// {
// 	t_list	*node;

// 	node = (t_list*)malloc(sizeof(t_list));
// 	if (node == NULL)
// 		return (NULL);
// 	node->data = data;
// 	node->next = NULL;
// 	return (node);
// }

// int	main(void)
// {
// 	t_list	*test_list;

// 	test_list = ft_new_element("Follow ");
// 	test_list->next = ft_new_element("the ");
// 	test_list->next->next = ft_new_element("white ");
// 	test_list->next->next->next = ft_new_element("rabbit.");
// 	ft_list_foreach(test_list, (void *)ft_putstr);
// 	ft_putchar('\n');
// 	return (0);
// }
