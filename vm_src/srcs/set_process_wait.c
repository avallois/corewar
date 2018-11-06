/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_process_wait.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:54:28 by cjumelin          #+#    #+#             */
/*   Updated: 2018/10/01 16:55:23 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	set_process_wait(t_data *d, t_process *proc)
{
	proc->pc %= MEM_SIZE;
	if (d->game_area[proc->pc] <= 16 && d->game_area[proc->pc] >= 1)
		proc->wait = g_op_tab[d->game_area[proc->pc] - 1].nb_cycles;
	else
		proc->wait = 1;
}
