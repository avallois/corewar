/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 14:44:26 by plamusse          #+#    #+#             */
/*   Updated: 2018/10/01 13:51:07 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	label_len(char *label)
{
	int		ret;

	ret = 0;
	while (check_char_into_str(LABEL_CHARS, *label) == TRUE)
	{
		label++;
		ret++;
	}
	return (ret);
}

static void	parse_param_label(t_asm *env, char **line, t_param *param)
{
	int		len;

	++(*line);
	len = label_len(*line);
	param->label = (char*)malloc(sizeof(char) * (len + 1));
	if (!param->label)
		handle_error(env, ERROR_MALLOC);
	param->label[len] = '\0';
	ft_memcpy(param->label, *line, len);
	*line += len;
}

static void	parse_param_value(t_asm *env, char **line, t_param *param, int type)
{
	long long	value;

	value = ft_atoll(*line);
	if ((type & T_REG) && (value < 0 || value > REG_NUMBER))
		handle_error(env, ERROR_REG);
	param->value.val = value;
	if (**line == '-')
		++(*line);
	while (ft_isdigit(**line))
		(*line)++;
}

static void	fill_param_size(t_asm *env, t_param *param, int type)
{
	if ((type & T_REG))
		param->size = 1;
	else if ((type & T_IND))
		param->size = 2;
	else
	{
		if (env->parser.current_op.op_tab.direct_size)
			param->size = 2;
		else
			param->size = 4;
	}
}

void		fill_param(t_asm *env, char **line, t_param *param, int type)
{
	if ((type & T_REG) || (type & T_DIR))
		++(*line);
	if (**line == LABEL_CHAR && ((type & T_DIR) || (type & T_IND)))
		parse_param_label(env, line, param);
	else
		parse_param_value(env, line, param, type);
	fill_param_size(env, param, type);
	param->address = env->treat.prog_size + env->parser.current_op.size;
	env->parser.current_op.size += param->size;
}
