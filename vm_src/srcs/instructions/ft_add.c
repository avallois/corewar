/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:07:37 by cjumelin          #+#    #+#             */
/*   Updated: 2018/10/01 10:02:39 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_add(t_process *proc, t_data *d)
{
	(void)d;
	proc->reg[proc->args.values[2] - 1] =
	proc->reg[proc->args.values[1] - 1] + proc->reg[proc->args.values[0] - 1];
	proc->carry = (proc->reg[proc->args.values[2] - 1] == 0) ? 1 : 0;
}
