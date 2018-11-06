/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:35:36 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/13 20:20:12 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	check_prefix(t_asm *env, t_parser *parser, int *i)
{
	int		len;

	len = 0;
	if (ft_strnequ(parser->line + *i
				, PREFIX_NAME
				, (len = ft_strlen(PREFIX_NAME)))
			&& parser->head_help.type != NAME_TYPE)
	{
		parser->head_help.type = NAME_TYPE;
		parser->head_help.len_max = PROG_NAME_LENGTH;
		parser->head_help.cur_str = parser->header.prog_name;
	}
	else if (ft_strnequ(parser->line + *i
				, PREFIX_COMMENT
				, (len = ft_strlen(PREFIX_COMMENT)))
			&& parser->head_help.type != COMMENT_TYPE)
	{
		parser->head_help.type = COMMENT_TYPE;
		parser->head_help.len_max = COMMENT_LENGTH;
		parser->head_help.cur_str = parser->header.comment;
	}
	else
		handle_error(env, ERROR_HEADER);
	*i += len;
}

static void	check_first_line(t_asm *env, t_parser *parser, int *i)
{
	*i += ft_skip_spaces(parser->line);
	check_prefix(env, parser, i);
	*i += ft_skip_spaces(parser->line + *i);
	if (parser->line[(*i)++] != QUOTE_CHAR)
		handle_error(env, ERROR_HEADER);
}

static void	check_last_line(t_asm *env, int i, int *first)
{
	i += ft_skip_spaces(env->parser.line + i);
	if ((env->parser.line[i] == '\0' || env->parser.line[i] == COMMENT_CHAR))
	{
		env->parser.step++;
		ft_memset((void*)&env->parser.head_help, 0, sizeof(t_head_help));
		*first = 0;
	}
	else
		handle_error(env, ERROR_HEADER);
}

void		parse_header(t_asm *env)
{
	static int	first = 0;
	int			i;
	char		cur;
	t_head_help	*head_help;
	t_header	*header;

	i = 0;
	if (first == 0)
	{
		check_first_line(env, &env->parser, &i);
		first = 1;
	}
	head_help = &(env->parser.head_help);
	header = &(env->parser.header);
	while ((cur = env->parser.line[i++])
		&& cur != QUOTE_CHAR
		&& head_help->i <= head_help->len_max)
		head_help->cur_str[head_help->i++] = cur;
	if (head_help->i > head_help->len_max)
		handle_error(env, ERROR_HEADER);
	(cur == '"') ? check_last_line(env, i++, &first)
			: (head_help->cur_str[head_help->i++] = '\n');
}
