/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_processes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 09:58:49 by cjumelin          #+#    #+#             */
/*   Updated: 2018/10/01 15:53:51 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			run_instruction(t_data *d, t_process *proc)
{
	int		opcode;
	t_op	*op;
	int		ret;

	proc->start_pc = proc->pc;
	opcode = d->game_area[proc->pc];
	if (opcode <= 16 && opcode >= 1)
	{
		ft_memset((void*)&proc->args, 0, sizeof(t_args));
		op = &g_op_tab[opcode - 1];
		ret = SUCCESS;
		if (op->has_ocp)
		{
			if ((ret = handle_arguments(d, proc, op)) == KILL)
				return (KILL);
		}
		if (ret == SUCCESS)
			(g_function[opcode])(proc, d);
	}
	else
		proc->pc = ++proc->pc % MEM_SIZE;
	set_process_wait(d, proc);
	return (SUCCESS);
}

void		run_cycle(t_data *d)
{
	int			i;
	t_process	*proc;

	i = 0;
	proc = d->proc.first;
	while (i++ < d->run.nprocesses)
	{
		proc->wait--;
		if (proc->wait <= 0)
		{
			if (run_instruction(d, proc) == KILL)
				kill_proc(d, &proc);
			else
				proc = proc->n;
		}
		else
		{
			proc = proc->n;
		}
	}
}

void		check_players_lives(t_data *d)
{
	int			i;
	t_process	*proc;

	d->run.checks++;
	i = 0;
	proc = d->proc.first;
	while (i < d->run.nprocesses && proc)
	{
		if (!proc->live_current_period)
			kill_proc(d, &proc);
		else
			proc->live_current_period = 0;
		if (d->run.nprocesses > 0)
			proc = proc->n;
		i++;
	}
	if (d->run.live >= NBR_LIVE || d->run.checks == MAX_CHECKS)
	{
		d->run.cycle_to_die -= CYCLE_DELTA;
		d->run.checks = 0;
	}
	d->run.live = 0;
	d->run.n_cycle_since_last_cycle_to_die = 0;
}

void		init_run(t_data *d)
{
	d->run.cycles = 1;
	d->run.n_cycle_since_last_cycle_to_die = 1;
	d->run.nprocesses = d->settings.nbr_players;
	d->run.cycle_to_die = CYCLE_TO_DIE;
	d->run.last_to_be_alive = d->proc.first->player_nbr;
}

void		run_processes(t_data *d)
{
	t_run	*r;

	init_run(d);
	r = &(d->run);
	while (TRUE)
	{
		if (r->n_cycle_since_last_cycle_to_die % r->cycle_to_die == 0)
			check_players_lives(d);
		if (!(r->nprocesses > 0 && r->cycle_to_die > 0))
			return (display_winner(d, r));
		run_cycle(d);
		if (d->settings.dump == r->cycles)
			dump_cycle(d);
		++r->cycles;
		++r->n_cycle_since_last_cycle_to_die;
	}
}
