/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_processus_managing.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 09:51:59 by cjumelin          #+#    #+#             */
/*   Updated: 2018/10/01 13:41:24 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	add_new_link(t_data *d, t_process *new_link)
{
	if (d->proc.first)
	{
		new_link->n = d->proc.first;
		new_link->p = d->proc.last;
		new_link->n->p = new_link;
	}
	else
	{
		new_link->n = new_link;
		new_link->p = new_link;
		d->proc.last = new_link;
	}
	d->proc.first = new_link;
	d->proc.last->n = new_link;
	d->proc.nbr_link++;
}

void		ft_add_proc_head_list(t_data *d, t_players *player, int i)
{
	t_process	*new_link;
	int			first_op;

	if (!(new_link = (t_process *)malloc(sizeof(t_process))))
		handle_error(d, ERR_MALLOC);
	ft_bzero((void*)new_link, sizeof(t_process));
	ft_bzero((void*)&new_link->reg, sizeof(int) * REG_NUMBER);
	new_link->player_nbr = i;
	new_link->reg[0] = player->id;
	new_link->carry = 0;
	new_link->pc = player->start;
	first_op = d->game_area[player->start];
	if (first_op <= 0x10 && first_op >= 1)
		new_link->wait = g_op_tab[first_op - 1].nb_cycles;
	else
		new_link->wait = 1;
	add_new_link(d, new_link);
}
