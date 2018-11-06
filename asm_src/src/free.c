/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 15:30:13 by plamusse          #+#    #+#             */
/*   Updated: 2018/10/01 18:05:15 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	free_label_list(t_asm *env)
{
	t_list	*label_list;
	t_label	*label;

	label_list = env->treat.label_list;
	while (label_list)
	{
		label = (t_label*)label_list->content;
		ft_memdel((void**)&(label->name));
		label_list = label_list->next;
	}
	ft_lst_del(&(env->treat.label_list), &ft_lst_memclr);
}

static void	free_op_list(t_asm *env)
{
	t_list	*op_list;
	t_instr	*instr;
	t_param	*param;
	int		i;

	op_list = env->treat.op_list;
	while (op_list)
	{
		instr = (t_instr*)op_list->content;
		i = 0;
		while (i < instr->op_tab.nb_param)
		{
			param = &instr->param[i];
			ft_memdel((void**)&(param->label));
			i++;
		}
		op_list = op_list->next;
	}
	ft_lst_del(&(env->treat.op_list), &ft_lst_memclr);
}

static void	free_gnl(t_asm *env)
{
	ft_memdel((void**)&(env->parser.line));
	if (env->file.ret > 0)
	{
		while ((env->file.ret =
					get_next_line(env->file.fd, &(env->parser.line))) > 0)
			ft_memdel((void**)&(env->parser.line));
		if (env->file.ret < 0)
			handle_error(env, ERROR_FD);
	}
}

void		free_asm(t_asm *env)
{
	free_gnl(env);
	ft_memdel((void**)&(env->treat.champ));
	ft_memdel((void**)&(env->file.dst_name));
	free_op_list(env);
	free_label_list(env);
}
