/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:01:22 by plamusse          #+#    #+#             */
/*   Updated: 2018/10/01 13:46:55 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "asm.h"

typedef struct	s_op
{
	char	*name;
	int		nb_param;
	int		param[3];
	int		op_code;
	int		cycle;
	char	*desciption;
	int		ocp;
	int		direct_size;
}				t_op;

typedef struct	s_label
{
	char	*name;
	int		address;
}				t_label;

typedef struct	s_treat
{
	char	*champ;
	int		prog_size;
	t_list	*op_list;
	t_list	*label_list;
}				t_treat;

typedef union	u_value
{
	int32_t	val;
	char	val_tab[4];
}				t_value;

typedef struct	s_param
{
	int32_t			address;
	int32_t			size;
	t_value			value;
	char			*label;
	unsigned char	type;
}				t_param;

typedef struct	s_instr
{
	int32_t			address;
	unsigned char	ocp;
	int32_t			size;
	t_param			param[3];
	t_op			op_tab;
}				t_instr;

typedef struct	s_index
{
	int	line;
	int	character;
}				t_index;

typedef struct	s_head_help
{
	int		type;
	int		i;
	int		size;
	int		len_max;
	char	*cur_str;
}				t_head_help;

typedef struct	s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}				t_header;

typedef struct	s_parser
{
	t_header	header;
	t_head_help	head_help;
	char		*line;
	t_index		index;
	int			step;
	t_instr		current_op;
}				t_parser;

typedef struct	s_file
{
	int		fd;
	int		ret;
	char	*src_name;
	char	*dst_name;
}				t_file;

typedef struct	s_asm
{
	t_file		file;
	t_parser	parser;
	t_treat		treat;
}				t_asm;

#endif
