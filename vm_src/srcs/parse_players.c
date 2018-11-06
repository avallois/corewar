/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 09:53:12 by cjumelin          #+#    #+#             */
/*   Updated: 2018/10/01 09:58:28 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		check_attributed_nbr(t_data *d, char *argv[], int i_player)
{
	int		n;
	int		i;
	char	*str;

	str = *argv;
	if (!str || !ft_isdigit_str(str))
		handle_error(d, ERR_USAGE);
	n = ft_atoi(str);
	if (n >= -4 && n <= -1)
		handle_error(d, ERR_PLAYR_NBR);
	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (i != i_player && n == d->p[i].id)
			handle_error(d, ERR_SAME_NBR);
		i++;
	}
	d->p[i_player].id = n;
	d->settings.argv++;
}

static void		init_players_id(t_data *d)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (i < MAX_PLAYERS)
		d->p[i++].id = j--;
}

void			parse_players(t_data *d)
{
	int		i;

	init_players_id(d);
	i = 0;
	while (*d->settings.argv && i < MAX_PLAYERS)
	{
		if (ft_strcmp(*d->settings.argv, "-n") == 0)
			check_attributed_nbr(d, ++d->settings.argv, i);
		d->p[i].path = *(d->settings.argv++);
		i++;
	}
	d->settings.nbr_players = i;
	if (*d->settings.argv)
		handle_error(d, ERR_MAX_PLAYER);
}
