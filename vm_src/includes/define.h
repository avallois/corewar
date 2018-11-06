/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 20:21:35 by cjumelin          #+#    #+#             */
/*   Updated: 2018/10/01 15:42:52 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/*
**	RETURN VALUES
*/

# define TRUE				1
# define FALSE				0
# define SUCCESS 			1
# define FAIL				0
# define KILL				-2

/*
**	BITWISE
*/

# define INT_SIZE 			4
# define INT16_SIZE 		2
# define OPCODE_BYTE 		1
# define MASK_2_BITS		0x3

/*
**	PARSING
*/

# define MIN_ARGS 			1
# define MAX_ARGS 			15

/*
**	ERRORS
*/

# define ERR_MALLOC			-1
# define ERR_NULL			-3
# define ERR_OPEN			-2
# define ERR_USAGE			1
# define ERR_SAME_NBR		2
# define ERR_PLAYR_NBR		3
# define ERR_MAX_PLAYER		4
# define ERR_HEADER			5
# define ERR_OCP			6
# define ERR_DIGIT			7
# define ERR_PROG_SIZE		8
# define ERR_OP				9
# define DEBUG				250

/*
**	DISPLAY INDENTATIONS
*/

# define INDENT_TOP			1
# define INDENT_LEFT		3
# define INDENT_ROWS		3
# define TAB				4
# define COL_DUMP			32

#endif
