/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:07:37 by cjumelin          #+#    #+#             */
/*   Updated: 2018/10/01 10:05:24 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	add_life_to_player(t_data *d, int value)
{
	int			i;
	int			i_player;
	t_players	*player;

	i = 0;
	player = NULL;
	while (i < d->settings.nbr_players)
	{
		if (value == d->p[i].id)
		{
			player = &d->p[i];
			i_player = i;
		}
		i++;
	}
	if (player)
	{
		++player->live;
		++d->run.live;
		d->run.last_to_be_alive = i_player;
	}
}

void		ft_live(t_process *proc, t_data *d)
{
	int		value;

	proc->pc = (proc->pc + OPCODE_BYTE) % MEM_SIZE;
	value = get_int32_at_idx(d, proc->pc);
	add_life_to_player(d, value);
	++proc->live_current_period;
	proc->pc = (proc->pc + INT_SIZE) % MEM_SIZE;
}
