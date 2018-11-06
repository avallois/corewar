/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 20:46:42 by cjumelin          #+#    #+#             */
/*   Updated: 2018/10/01 10:58:18 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	print_byte(unsigned char nb)
{
	static char		*hex = "0123456789abcdef";
	unsigned char	half;

	half = (nb & 0xF0) >> 4;
	ft_putchar(hex[half]);
	half = nb & 0xF;
	ft_putchar(hex[half]);
}

void		dump_cycle(t_data *d)
{
	int		byte;

	byte = -1;
	ft_putchar('\n');
	while (++byte < MEM_SIZE)
	{
		if (!(byte % COL_DUMP))
			ft_printf("\n0x%.4x : ", byte);
		print_byte(d->game_area[byte]);
		ft_putchar(' ');
	}
	ft_putchar('\n');
	free_vm(d);
	exit(0);
}
