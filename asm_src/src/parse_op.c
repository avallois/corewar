/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 15:55:36 by plamusse          #+#    #+#             */
/*   Updated: 2018/10/01 16:21:26 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	get_current_op_on_op_tab(t_asm *env, char **line)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < OP_TAB_SIZE - 1)
	{
		if (ft_strnequ(
					g_op_tab[i].name
					, *line
					, (len = ft_strlen(g_op_tab[i].name))))
		{
			ft_memcpy((void*)&env->parser.current_op.op_tab,
					(void*)&g_op_tab[i],
					sizeof(t_op));
			*line += len;
			return ;
		}
		++i;
	}
	handle_error(env, ERROR_OP_NAME);
}

void		parse_op(t_asm *env, char **line)
{
	t_instr	*current_op;

	get_current_op_on_op_tab(env, line);
	current_op = &env->parser.current_op;
	current_op->address = env->treat.prog_size;
	current_op->size = 1;
	if (current_op->op_tab.ocp)
		current_op->size = 2;
	else
		current_op->size = 1;
}
