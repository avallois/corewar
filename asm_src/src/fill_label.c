/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_label.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 13:42:48 by plamusse          #+#    #+#             */
/*   Updated: 2018/10/01 13:51:21 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	fill_label_value(t_asm *env, t_instr *cur, t_param *param)
{
	t_list		*label_list;
	t_label		*match;

	label_list = env->treat.label_list;
	while (label_list)
	{
		match = ((t_label*)(label_list->content));
		if (match->name)
		{
			if (ft_strequ(param->label, match->name))
			{
				param->value.val = match->address - cur->address;
				return ;
			}
		}
		label_list = label_list->next;
	}
	handle_error(env, ERROR_LABEL);
}

void		fill_label(t_asm *env)
{
	t_list		*op_list;
	t_instr		*cur;
	t_param		*param;
	int			i;

	op_list = env->treat.op_list;
	while (op_list)
	{
		cur = ((t_instr*)(op_list->content));
		i = 0;
		while (i < cur->op_tab.nb_param)
		{
			param = &cur->param[i];
			if (param->label)
				fill_label_value(env, cur, param);
			i++;
		}
		op_list = op_list->next;
	}
}
