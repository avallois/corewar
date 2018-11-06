/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:58:02 by cjumelin          #+#    #+#             */
/*   Updated: 2018/10/01 16:26:51 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	display_winner(t_data *d, t_run *r)
{
	ft_printf("Contestant %i, \"%s\", has won !\n",
			d->p[r->last_to_be_alive].id,
			d->p[r->last_to_be_alive].info.prog_name);
}
