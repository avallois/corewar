/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tstr_ncmp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:52:05 by cjumelin          #+#    #+#             */
/*   Updated: 2018/04/13 17:55:54 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_tstr_cmp(char **s, char **ts, size_t size)
{
	while (--size)
	{
		if (!ft_strcmp(*s, ts[size]))
			return (1);
		++(*ts);
	}
	if (!ft_strcmp(*s, ts[size]))
		return (1);
	return (0);
}
