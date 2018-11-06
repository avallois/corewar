/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 09:46:30 by cjumelin          #+#    #+#             */
/*   Updated: 2018/10/01 09:46:48 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	kill_proc(t_data *d, t_process **l)
{
	t_process	*to_delete;

	to_delete = *l;
	if ((*l) == d->proc.first)
		d->proc.first = (*l)->n;
	else if ((*l) == d->proc.last)
		d->proc.last = (*l)->p;
	(*l)->n->p = (*l)->p;
	(*l)->p->n = (*l)->n;
	(*l) = (*l)->n;
	ft_memdel((void*)&to_delete);
	--d->run.nprocesses;
}
