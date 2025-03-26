/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarray_dup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:30:40 by fwahl             #+#    #+#             */
/*   Updated: 2024/06/18 18:41:50 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_strarray_dup(char **array)
{
	char	**dup_array;
	size_t	len;
	size_t	i;

	if (!array)
		return (NULL);
	len = ft_strarray_len(array);
	dup_array = ft_calloc(1, (len + 1) * sizeof(char *));
	if (!dup_array)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup_array[i] = ft_strdup(array[i]);
		if (!dup_array[i])
		{
			ft_free_strarray(dup_array);
			return (NULL);
		}
		i++;
	}
	return (dup_array);
}
