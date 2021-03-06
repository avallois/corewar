/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 15:45:18 by cjumelin          #+#    #+#             */
/*   Updated: 2017/05/19 15:45:24 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_add_str(char **s1, char *s2)
{
	char *tmp;

	if (*s1 && s2)
	{
		tmp = *s1;
		*s1 = ft_strjoin(tmp, s2);
		free(tmp);
	}
	return (*s1);
}
