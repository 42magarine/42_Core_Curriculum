/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 23:39:23 by fwahl             #+#    #+#             */
/*   Updated: 2024/03/19 21:29:43 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	builtin_unset(char **argv, t_env **env)
{
	t_env	*current;
	t_env	*prev;
	int		i;

	i = 0;
	while (argv[++i] != NULL)
	{
		current = *env;
		prev = NULL;
		while (current != NULL)
		{
			if (ft_strcmp(current->key, argv[i]) == 0)
			{
				if (prev == NULL)
					*env = current->next;
				else
					prev->next = current->next;
				free_env_node(current);
			}
			prev = current;
			current = current->next;
		}
	}
	return (true);
}
