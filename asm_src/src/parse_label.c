/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 12:46:41 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/14 15:41:18 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	is_good_label(char *string)
{
	while (check_char_into_str(LABEL_CHARS, *string) == TRUE)
		++string;
	if (*string == LABEL_CHAR)
		return (TRUE);
	else
		return (FALSE);
}

static void	set_label(t_asm *env, char **line, t_label *label)
{
	size_t	ret;
	int		err;
	char	*label_name;

	ret = ft_strclen(*line, ':');
	ft_memset((void*)label, 0, sizeof(t_label));
	label_name = label->name;
	err = ft_dup_memory((void **)&(label->name)
			, *line
			, ret + 1);
	if (err == ERROR)
		handle_error(env, ERROR_MALLOC);
	label->name[ret++] = '\0';
	label->address = env->treat.prog_size;
	*line += ret;
}

void		parse_label(t_asm *env, char **line)
{
	t_label	label;
	t_list	*new;

	asm_skip_spaces(line, SPACES_TABS);
	if (is_good_label(*line) == TRUE)
	{
		set_label(env, line, &label);
		new = ft_lstnew((void*)&label, sizeof(t_instr));
		ft_lst_push_back(&env->treat.label_list, new);
		asm_skip_spaces(line, SPACES_TABS);
	}
}
