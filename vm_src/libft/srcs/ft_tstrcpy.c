/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 19:35:58 by cjumelin          #+#    #+#             */
/*   Updated: 2018/04/12 19:36:16 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tstrcpy(char **tstr, size_t size)
{
	char	**cpy;
	char	**tmp;

	cpy = NULL;
	if (!(cpy = (char**)malloc(sizeof(char*) * size)))
		return (cpy);
	tmp = cpy;
	while (size)
	{
		*tmp = ft_strdup(*tstr);
		++tmp;
		++tstr;
		--size;
	}
	return (cpy);
}
