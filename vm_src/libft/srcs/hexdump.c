/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 09:33:03 by pba               #+#    #+#             */
/*   Updated: 2018/07/10 15:05:23 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				hex_dump(int len, unsigned char *buff, unsigned char *pc)
{
	int				i;

	i = 0;
	while (i < len)
	{
		if (i % 16 == 0)
		{
			if (i != 0)
				printf("%s\n", buff);
			printf(" %04x ", i);
		}
		printf(" %02x", pc[i]);
		if ((pc[i] < 0x20) || (pc[i] > 0x7e))
			buff[i % 16] = '.';
		else
			buff[i % 16] = pc[i];
		buff[(i % 16) + 1] = '\0';
		++i;
	}
	while (i % 16 != 0)
	{
		ft_putstr("   ");
		++i;
	}
	printf("  %s\n", buff);
}
