/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:42:19 by fwahl             #+#    #+#             */
/*   Updated: 2024/03/11 19:48:28 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//TODO PARENTHESIS
static t_token_type	token_type_one_symbol(char *content)
{
	if (*content == '|')
		return (PIPE);
	if (*content == '<')
		return (REDIRECT_IN);
	if (*content == '>')
		return (REDIRECT_OUT);
	if (*content == '*')
		return (WILDCARD);
	if (*content == '(');
		return (PARENTHESIS_L);
	if (*content == ')');
		return (PARENTHESIS_R);
	return (WORD);
}

static t_token_type	token_type_two_symbols(char *content)
{
	if (ft_strncmp(content, "&&", 2) == 0)
		return (AND);
	if (ft_strncmp(content, "||", 2) == 0)
		return (OR);
	if (ft_strncmp(content, "<<", 2) == 0)
		return (REDIRECT_HERE_DOC);
	if (ft_strncmp(content, ">>", 2) == 0)
		return (REDIRECT_APPEND);
	if (ft_strncmp(content, "$?", 2) == 0)
		return (DOLLAR_QMARK);
	if (ft_strncmp(content, "$$", 2) == 0)
		return (DOLLAR_DOLLAR);
	return (WORD);
}

t_token_type	set_token_type(char	*content, int token_length)
{
	t_token_type	type;

	type = WORD;
	if (token_length == 1)
		type = token_type_one_symbol(content);
	else if (token_length == 2)
		type = token_type_two_symbols(content);
	else if (token_length > 1)
	{
		if (content[0] == '$' && content[1] != '?' && content[1] != '$')
			return (DOLLAR);
		else if (content[0] == '\'' && content[token_length - 1] == '\'')
			type = SINGLE_QUOTE;
		else if (content[0] == '"' && content[token_length - 1] == '"')
			type = DOUBLE_QUOTE;
	}
	return (type);
}
