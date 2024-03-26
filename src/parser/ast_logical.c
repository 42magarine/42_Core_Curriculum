/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_logical.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:17:27 by fwahl             #+#    #+#             */
/*   Updated: 2024/03/26 21:05:48 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	is_logical(t_type type)
{
	return(type == AND || type == OR);
}

t_ast	*ast_logical(t_token **token, t_ast *left)
{
	t_ast	*node;
	t_ast	*logical;

	node = left;
	while (*token != NULL && is_logical((*token)->type))
	{
		logical = new_ast_node(*token);
		logical->left = node;
		advance_and_free_token(token);
		if (*token != NULL && (*token)->type == PARENTHESIS_L)
			logical->right = ast_parenthesis(token);
		if (*token != NULL && (*token)->type == COMMAND)
		{
			logical->right = new_ast_node(*token);
			while (*token != NULL && (*token)-> type == COMMAND)
				advance_and_free_token(token);
		}
		// else handle syntax error
		node = logical;
		if (*token == NULL || !is_logical((*token)->type))
			break ;
	}
	return (node);
}
