/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:54:21 by mott              #+#    #+#             */
/*   Updated: 2024/01/09 20:22:25 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : ft_list_remove_if
// Expected files   : ft_list_remove_if.c
// Allowed functions: free
// --------------------------------------------------------------------------------

// Write a function called ft_list_remove_if that removes from the
// passed list any element the data of which is "equal" to the reference data.

// It will be declared as follows :

// void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

// cmp takes two void* and returns 0 when both parameters are equal.

// You have to use the ft_list.h file, which will contain:

// $>cat ft_list.h
// typedef struct      s_list
// {
//     struct s_list   *next;
//     void            *data;
// }                   t_list;
// $>

#include <stdlib.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*previous;
	t_list	*current;

	previous = NULL;
	current = *begin_list;
	while (current != NULL)
	{
		if (cmp(current->data, data_ref) == 0)
		{
			if (previous == NULL)
				*begin_list = current->next;
			else
				previous->next = current->next;
			free(current);
		}
		else
			previous = current;
		current = current->next;
	}
}

#include <unistd.h>

void	ft_putchar(int c)
{
	write(STDOUT_FILENO, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
		ft_putchar(*str++);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

t_list	*ft_new_element(void *data)
{
	t_list	*node;

	node = (t_list*)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list != (void*)0)
	{
		f(begin_list->data);
		begin_list = begin_list->next;
	}
}

int	main(void)
{
	t_list	*test_list;

	test_list = ft_new_element("Follow ");
	test_list->next = ft_new_element("the ");
	test_list->next->next = ft_new_element("white ");
	test_list->next->next->next = ft_new_element("rabbit.");
	ft_list_foreach(test_list, (void *)ft_putstr);
	ft_putchar('\n');
	ft_list_remove_if(&test_list, "the ", ft_strcmp);
	ft_list_foreach(test_list, (void *)ft_putstr);
	ft_putchar('\n');
	return (0);
}
