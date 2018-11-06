/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 09:29:02 by cjumelin          #+#    #+#             */
/*   Updated: 2018/10/01 09:35:06 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	del_lst_proc(t_data *d)
{
	int			i;
	t_process	*proc;
	t_process	*tmp;

	i = -1;
	proc = d->proc.first;
	while (++i < d->run.nprocesses)
	{
		tmp = proc;
		proc = proc->n;
		ft_memdel((void*)&tmp);
	}
}

void		free_vm(t_data *d)
{
	ft_memdel((void**)&d->game_area);
	del_lst_proc(d);
}
