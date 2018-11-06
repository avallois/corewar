/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 20:32:26 by cjumelin          #+#    #+#             */
/*   Updated: 2018/10/01 15:57:42 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/*
**	INSTRUCTIONS
*/

typedef struct		s_op
{
	char			*name;
	int				nb_args;
	t_arg_type		arg_types[MAX_ARGS_NUMBER];
	int				opcode;
	int				nb_cycles;
	char			*description;
	int				has_ocp;
	int				dir_is_2_bytes;
}					t_op;

/*
**	RUNNING PROCESSES
*/

typedef struct		s_args
{
	int		values[3];
	int		type[4];
}					t_args;

typedef struct		s_process
{
	int							live_current_period;
	int							player_nbr;
	int							reg[REG_NUMBER];
	int							carry;
	uint16_t					pc;
	int							start_pc;
	int							wait;
	t_args						args;
	struct s_process			*p;
	struct s_process			*n;
}					t_process;

typedef struct		s_run
{
	int							nprocesses;
	int							last_to_be_alive;
	unsigned int				cycles;
	int							cycle_to_die;
	unsigned int				n_cycle_since_last_cycle_to_die;
	unsigned int				live;
	int							checks;
}					t_run;

typedef struct		s_process_lst
{
	struct s_process			*first;
	struct s_process			*count;
	struct s_process			*last;
	int							nbr_link;
}					t_process_lst;

/*
**	PLAYERS
*/

typedef struct		s_players
{
	char						*path;
	int							fd;
	int							id;
	int							live;
	int							is_alive;
	t_header					info;
	int							start;
}					t_players;

/*
**	SETTINGS
*/

typedef struct		s_game_settings
{
	char						**argv;
	int							nbr_players;
	unsigned int				dump;
}					t_game_settings;

/*
**	ENVIRONNEMENT
*/

typedef struct		s_data
{
	t_game_settings				settings;
	t_run						run;
	t_process_lst				proc;
	t_players					p[4];
	char						*game_area;
}					t_data;

/*
**	UNIONS
*/

typedef union		u_byte_code
{
	char	s[4];
	int		i;
}					t_byte_code;

typedef union		u_byte16
{
	char	s[2];
	int16_t	i;
}					t_byte16;

static t_op			g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

#endif
