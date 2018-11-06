/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 09:52:49 by cjumelin          #+#    #+#             */
/*   Updated: 2018/10/01 09:52:55 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	get_cycle_to_dump(t_data *d)
{
	char	*str;

	str = *(++d->settings.argv);
	if (str)
	{
		if (ft_isdigit_str(str))
		{
			d->settings.dump = ft_atoi(str);
			if (d->settings.dump <= 0 || !(*(++d->settings.argv)))
				handle_error(d, ERR_USAGE);
		}
		else
			handle_error(d, ERR_USAGE);
	}
	else
		handle_error(d, ERR_USAGE);
}

static void	check_flags(t_data *d)
{
	if (ft_strcmp(*d->settings.argv, "-dump") == 0)
		get_cycle_to_dump(d);
}

static void	check_nbr_arguments(t_data *d, int argc, char *argv[])
{
	if (argc == MIN_ARGS || argc > MAX_ARGS || !(d->settings.argv = ++argv))
		handle_error(d, ERR_USAGE);
}

static void	init_data_struct(t_data **pointer, t_data *heap)
{
	ft_bzero((void*)heap, sizeof(t_data));
	*pointer = heap;
	if (!(heap->game_area = malloc(MEM_SIZE)))
		handle_error(heap, ERR_MALLOC);
	ft_bzero((void*)heap->game_area, MEM_SIZE);
}

int			main(int argc, char *argv[])
{
	t_data	*d;
	t_data	q;

	d = NULL;
	init_data_struct(&d, &q);
	check_nbr_arguments(d, argc, argv);
	check_flags(d);
	parse_players(d);
	charge_players(d);
	run_processes(d);
	free_vm(d);
	return (0);
}
