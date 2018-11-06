/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_p_to_tpab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:20:26 by cjumelin          #+#    #+#             */
/*   Updated: 2018/04/11 05:11:47 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_add_p_to_ptab(void *p, void **ptab, size_t tab_size)
{
	void	**ptr;

	ptr = ptab;
	while (tab_size && *ptr)
	{
		++ptr;
		--tab_size;
	}
	if (tab_size > 0)
		return ((*ptr = p) ? 1 : 1);
	return (0);
}
