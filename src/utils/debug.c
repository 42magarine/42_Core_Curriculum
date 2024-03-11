/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:24:11 by mott              #+#    #+#             */
/*   Updated: 2024/03/11 17:26:11 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	token_print(t_token *tokens)
{
	int	i;

	i = 0;
	while (tokens != NULL)
	{
		ft_printf("token[%d]: %s - %p\n", i, tokens->content, tokens->content);
		i++;
		tokens = tokens->next;
	}
}

void	print_char_array(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		ft_printf("str[%d]: %s\n", i, str[i]);
		i++;
	}
}
