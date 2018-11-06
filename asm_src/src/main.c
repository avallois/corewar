/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 13:49:15 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/20 05:35:48 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int argc, char *argv[])
{
	t_asm	*env;
	t_asm	tmp;

	env = &tmp;
	init_asm(env);
	if (argc != 2 || !(env->file.src_name = *(++argv)))
		handle_error(env, ERROR_ARG);
	check_file(env);
	parse_file(env);
	treat_file(env);
	ft_putendl_fd("Writing output program to cor file", 1);
	free_asm(env);
	return (0);
}
