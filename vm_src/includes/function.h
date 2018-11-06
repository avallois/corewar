/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 20:27:06 by cjumelin          #+#    #+#             */
/*   Updated: 2018/10/01 16:02:28 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

/*
**	PARSE_PLAYERS
*/

void		parse_players(t_data *d);
void		charge_players(t_data *d);

/*
**	RUN_PROCESSES
*/

void		run_processes(t_data *d);
int			catch_arg_value(t_process *proc, t_op *op, char *cur_byte);
int			check_arg(char ocp, t_op *op, t_process *proc);

/*
**	BYTE
*/

int32_t		big_endian(int32_t little);

/*
**	LISTS
*/

void		ft_add_proc_head_list(t_data *d, t_players *player, int i);

/*
**	ERROR
*/

void		handle_error(t_data *d, int err_code);

/*
**	FREE
*/

void		free_vm(t_data *d);

/*
**	INSTRUCTIONS HELPERS
*/

void		get_ind_value(char *area, t_process *p, int *adrs);
int			valide_idx_reg(int idx);
void		set_next_instruction(t_data *d, t_process *player);
void		kill_proc(t_data *d, t_process **l);
int			handle_arguments(t_data *d, t_process *proc, t_op *op);
int16_t		get_int16_at_idx(t_data *d, int idx);
int			get_int32_at_idx(t_data *d, int idx);
void		put_int32_at_idx(t_data *d, int idx, int value);
void		set_process_wait(t_data *d, t_process *proc);

/*
**	INSTRUCTIONS
*/

void		ft_live(t_process *p, t_data *d);
void		ft_add(t_process *p, t_data *d);
void		ft_aff(t_process *p, t_data *d);
void		ft_and(t_process *p, t_data *d);
void		ft_fork(t_process *p, t_data *d);
void		ft_ld(t_process *p, t_data *d);
void		ft_ldi(t_process *p, t_data *d);
void		ft_lfork(t_process *p, t_data *d);
void		ft_lld(t_process *p, t_data *d);
void		ft_lldi(t_process *p, t_data *d);
void		ft_or(t_process *p, t_data *d);
void		ft_st(t_process *p, t_data *d);
void		ft_sti(t_process *p, t_data *d);
void		ft_sub(t_process *p, t_data *d);
void		ft_xor(t_process *p, t_data *d);
void		ft_zjump(t_process *p, t_data *d);

/*
**	DISPLAY
*/

void		dump_cycle(t_data *d);
void		display_winner(t_data *d, t_run *r);

static void (*g_function[17])() =
{
	NULL,
	ft_live,
	ft_ld,
	ft_st,
	ft_add,
	ft_sub,
	ft_and,
	ft_or,
	ft_xor,
	ft_zjump,
	ft_ldi,
	ft_sti,
	ft_fork,
	ft_lld,
	ft_lldi,
	ft_lfork,
	ft_aff
};

#endif
