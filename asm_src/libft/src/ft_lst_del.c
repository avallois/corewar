/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 11:26:24 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/14 13:22:27 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_del(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*elem;
	t_list	*tmp;

	elem = *alst;
	while (elem)
	{
		tmp = elem;
		del(elem->content, elem->content_size);
		elem->content_size = 0;
		elem = elem->next;
		ft_memdel((void**)&tmp);
	}
	*alst = NULL;
}
