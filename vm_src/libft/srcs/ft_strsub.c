/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:11:39 by cjumelin          #+#    #+#             */
/*   Updated: 2017/10/12 21:42:55 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*tronc;
	unsigned int	i;

	i = 0;
	if (len == 0)
		return ((tronc = NULL));
	if (s)
	{
		if (!(tronc = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (len > 0)
		{
			tronc[i] = s[start];
			start++;
			i++;
			len--;
		}
		tronc[i] = '\0';
		return (tronc);
	}
	return (0);
}
