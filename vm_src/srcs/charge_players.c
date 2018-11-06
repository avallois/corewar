/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charge_players.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 20:41:36 by cjumelin          #+#    #+#             */
/*   Updated: 2018/10/01 16:04:30 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		charge_player_to_arena(t_data *d, t_players *player, int i_player)
{
	char	*start;
	int		prog_size;
	int		ret;

	player->start = (MEM_SIZE / d->settings.nbr_players) * i_player;
	start = d->game_area + player->start;
	prog_size = player->info.prog_size;
	ret = read(player->fd, start, prog_size);
	if (ret != prog_size || ret == 0)
		handle_error(d, ERR_PROG_SIZE);
	player->is_alive = 1;
}

static void	check_header(t_data *d, t_players *player, int ret, int fd)
{
	if (ret != COMMENT_LENGTH
			|| player->info.magic != COREWAR_EXEC_MAGIC
			|| player->info.prog_size > CHAMP_MAX_SIZE
			|| lseek(fd, INT_SIZE, SEEK_CUR) < 0)
		handle_error(d, ERR_HEADER);
}

void		charge_header(t_data *d, t_players *player)
{
	t_byte_code		u;
	int				fd;
	int				ret;

	fd = player->fd;
	u.i = 0;
	ret = read(fd, u.s, INT_SIZE);
	if (ret == INT_SIZE)
	{
		player->info.magic = big_endian(u.i);
		ret = read(fd, player->info.prog_name, PROG_NAME_LENGTH);
		if (ret == PROG_NAME_LENGTH)
		{
			if (lseek(fd, INT_SIZE, SEEK_CUR) < 0)
				handle_error(d, ERR_HEADER);
			ret = read(fd, u.s, INT_SIZE);
			if (ret == INT_SIZE)
			{
				player->info.prog_size = big_endian(u.i);
				ret = read(fd, player->info.comment, COMMENT_LENGTH);
			}
		}
	}
	check_header(d, player, ret, fd);
}

void		charge_players(t_data *d)
{
	int			i;
	t_players	*player;

	i = 0;
	while (i < d->settings.nbr_players)
	{
		player = &d->p[i];
		if ((player->fd = open(player->path, O_RDONLY)) < 0)
			handle_error(d, ERR_OPEN);
		charge_header(d, player);
		charge_player_to_arena(d, player, i);
		ft_add_proc_head_list(d, player, i);
		i++;
	}
}
