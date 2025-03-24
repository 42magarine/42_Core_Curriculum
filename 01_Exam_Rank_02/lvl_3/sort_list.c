/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:36:55 by mott              #+#    #+#             */
/*   Updated: 2024/01/09 15:49:05 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : sort_list
// Expected files   : sort_list.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write the following functions:

// t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

// This function must sort the list given as a parameter, using the function
// pointer cmp to select the order to apply, and returns a pointer to the
// first element of the sorted list.

// Duplications must remain.

// Inputs will always be consistent.

// You must use the type t_list described in the file list.h
// that is provided to you. You must include that file
// (#include "list.h"), but you must not turn it in. We will use our own
// to compile your assignment.

// Functions passed as cmp will always return a value different from
// 0 if a and b are in the right order, 0 otherwise.

// For example, the following function used as cmp will sort the list
// in ascending order:

// int ascending(int a, int b)
// {
// 	return (a <= b);
// }

#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*current;
	t_list	*next;
	int		temp;

	current = lst;
	while (current != (void*)0)
	{
		next = current->next;
		while (next != (void*)0)
		{
			if (cmp(current->data, next->data) == 0)
			{
				temp = current->data;
				current->data = next->data;
				next->data = temp;
			}
			next = next->next;
		}
		current = current->next;
	}
	return (lst);
}

// bubble sort algorithm

// #include <stdio.h>
// #include <stdlib.h>

// int	ascending(int a, int b)
// {
// 	return (a <= b);
// }

// t_list	*ft_new_element(int data)
// {
// 	t_list	*node;

// 	node = (t_list *)malloc(sizeof(t_list));
// 	if (node == NULL)
// 		return (NULL);
// 	node->data = data;
// 	node->next = NULL;
// 	return (node);
// }

// int	main(void)
// {
// 	t_list	*test_list;
// 	t_list	*print_list;

// 	test_list = ft_new_element(42);
// 	test_list->next = ft_new_element(0);
// 	test_list->next->next = ft_new_element(8);
// 	test_list->next->next->next = ft_new_element(-8);
// 	test_list->next->next->next->next = ft_new_element(42);
// 	test_list->next->next->next->next->next = ft_new_element(64);
// 	test_list->next->next->next->next->next->next = ft_new_element(1024);
// 	test_list->next->next->next->next->next->next->next = ft_new_element(-512);
// 	print_list = test_list;
// 	while (print_list != NULL)
// 	{
// 		printf(" %d", print_list->data);
// 		print_list = print_list->next;
// 	}
// 	printf("\n");
// 	sort_list(test_list, ascending);
// 	print_list = test_list;
// 	while (print_list != NULL)
// 	{
// 		printf(" %d", print_list->data);
// 		print_list = print_list->next;
// 	}
// 	printf("\n");
// 	return (0);
// }
