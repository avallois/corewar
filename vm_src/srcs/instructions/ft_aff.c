/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:07:37 by cjumelin          #+#    #+#             */
/*   Updated: 2018/10/01 10:03:02 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_aff(t_process *proc, t_data *d)
{
	ft_printf("Le joueur \033[1;31%i: %s\033[0m affiche %c !\n",
							d->p[proc->player_nbr].id,
							d->p[proc->player_nbr].info.prog_name,
							proc->reg[proc->args.values[0] - 1] % 256);
	proc->carry = (!(proc->reg[proc->args.values[0] - 1] % 256)) ? 1 : 0;
}
