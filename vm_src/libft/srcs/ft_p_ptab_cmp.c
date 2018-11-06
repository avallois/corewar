/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_ptab_cmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:33:22 by cjumelin          #+#    #+#             */
/*   Updated: 2018/04/11 03:29:44 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_p_ptab_cmp(void *p, void **ptab, size_t tab_size)
{
	while (tab_size)
	{
		if (p == *ptab)
			return (*ptab);
		++ptab;
		--tab_size;
	}
	return (NULL);
}
