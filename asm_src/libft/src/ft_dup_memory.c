/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/09/20 05:29:02 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dup_memory(void **dest, const void *src, size_t size)
{
	void		*mem;
	static int	ret;

	if (src == NULL)
		return (ERROR);
	mem = malloc(size == 0 ? 1 : size);
	if (mem == NULL)
	{
		ret = ERROR;
		*dest = NULL;
	}
	else
	{
		ret = SUCCESS;
		ft_memcpy(mem, src, size);
		*dest = mem;
	}
	return (ret);
}
