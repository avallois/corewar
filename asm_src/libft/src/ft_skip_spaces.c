/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:34:06 by plamusse          #+#    #+#             */
/*   Updated: 2018/08/28 17:37:14 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int			ft_skip_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] && skip_space(str[i]))
		i++;
	return (i);
}
