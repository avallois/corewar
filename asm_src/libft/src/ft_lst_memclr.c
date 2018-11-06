/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_memclr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:45:40 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/14 13:24:23 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			ft_lst_memclr(void *content, size_t content_size)
{
	if (!content)
		return ;
	ft_memset(content, 0, content_size);
	ft_memdel((void**)&content);
}
