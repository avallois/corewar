/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 16:15:50 by plamusse          #+#    #+#             */
/*   Updated: 2018/10/01 13:51:52 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	put_value(char *champ, t_param *param, int *i_champ)
{
	int		size;
	int		i;

	i = 0;
	size = param->size;
	while (size--)
		champ[*i_champ + size] = param->value.val_tab[i++];
}

static void	put_params(
		char *champ, t_instr *instr, t_param *param, int *i_champ)
{
	int		i_param;

	i_param = 0;
	while (i_param < instr->op_tab.nb_param)
	{
		param = &instr->param[i_param++];
		put_value(champ, param, i_champ);
		*i_champ += param->size;
	}
}

static void	translate_to_bytecode(t_asm *env)
{
	t_list	*op_list;
	t_instr	*instr;
	char	*champ;
	int		i;

	env->treat.champ = (char*)malloc(sizeof(char) * (env->treat.prog_size + 1));
	if (!env->treat.champ)
		handle_error(env, ERROR_MALLOC);
	champ = env->treat.champ;
	op_list = env->treat.op_list;
	i = 0;
	while (op_list)
	{
		instr = ((t_instr*)(op_list->content));
		champ[i++] = instr->op_tab.op_code;
		if (instr->ocp)
			champ[i++] = instr->ocp;
		put_params(champ, instr, instr->param, &i);
		op_list = op_list->next;
	}
}

void		treat_file(t_asm *env)
{
	translate_to_bytecode(env);
	write_cor(env);
}
