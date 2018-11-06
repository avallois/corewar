/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_indirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 09:45:30 by cjumelin          #+#    #+#             */
/*   Updated: 2018/10/01 09:45:41 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	put_int32_at_idx(t_data *d, int idx, int value)
{
	t_byte_code	b;
	int			i;

	ft_bzero((void *)&b, sizeof(t_byte_code));
	b.i = big_endian(value);
	i = 0;
	while (i < INT_SIZE)
	{
		d->game_area[(idx + i + MEM_SIZE) % MEM_SIZE] = b.s[i];
		++i;
	}
}

int		get_int32_at_idx(t_data *d, int idx)
{
	t_byte_code	b;
	int			i;

	ft_bzero((void *)&b, sizeof(t_byte_code));
	i = 0;
	while (i < INT_SIZE)
	{
		b.s[i] = d->game_area[(idx + i + MEM_SIZE) % MEM_SIZE];
		++i;
	}
	return (big_endian(b.i));
}

int16_t	get_int16_at_idx(t_data *d, int idx)
{
	t_byte16	b;
	int16_t		i;
	char		swp;

	ft_bzero((void *)&b, sizeof(t_byte16));
	i = 0;
	while (i < INT16_SIZE)
	{
		b.s[i] = d->game_area[(idx + i + MEM_SIZE) % MEM_SIZE];
		++i;
	}
	swp = b.s[0];
	b.s[0] = b.s[1];
	b.s[1] = swp;
	return (b.i);
}
