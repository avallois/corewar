/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 12:09:37 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/15 15:19:23 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

/*
**    VALUE ========================================================
*/
# define ARG -2
# define SUCCESS 0
# define OP_TAB_SIZE 17

/*
**    STRING ========================================================
*/

# define SKIP_ASM_CHAR " \t\n"
# define SPACES_TABS " \t"
# define PREFIX_NAME ".name"
# define NAME_TYPE		1
# define PREFIX_COMMENT ".comment"
# define COMMENT_TYPE	2
# define SRC_EXTENSION ".s"
# define DST_EXTENSION ".cor"

/*
**    ERROR ========================================================
*/

# define ERROR				-1
# define ERROR_MALLOC		-2
# define ERROR_ARG			-3
# define ERROR_FD			-4
# define ERROR_FILE_NAME	-5
# define ERROR_USAGE		-6
# define ERROR_NOPROG		-7
# define ERROR_HEADER		-9
# define ERROR_OP_NAME		-10
# define ERROR_PARAM		-11
# define ERROR_REG			-12
# define ERROR_LABEL		-13
# define ERROR_CREAT_FILE	-14
# define ERROR_EOF			-15
# define ERROR_PARSING		-16

/*
**    INCLUDE ========================================================
*/

# include "op.h"
# include "libft.h"
# include "struct.h"
# include "function.h"

extern t_op g_op_tab[17];

#endif
