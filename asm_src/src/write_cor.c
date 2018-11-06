/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_cor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 12:57:12 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/14 15:17:41 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	get_file_dst_name(t_asm *env)
{
	int		src_len;
	int		ext_len;

	ext_len = ft_strlen(DST_EXTENSION);
	src_len = ft_strlen(env->file.src_name) - ft_strlen(SRC_EXTENSION);
	env->file.dst_name = (char*)malloc(sizeof(char) * (src_len + ext_len + 1));
	ft_memset(env->file.dst_name, 0, src_len + ext_len);
	ft_memcpy(env->file.dst_name, env->file.src_name, src_len);
	ft_strlcat(env->file.dst_name, DST_EXTENSION, src_len + ext_len + 1);
}

void		write_cor(t_asm *env)
{
	int		fd;

	get_file_dst_name(env);
	fd = open(
			env->file.dst_name
			, O_WRONLY | O_CREAT | O_TRUNC
			, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
		handle_error(env, ERROR_CREAT_FILE);
	write(fd, (void*)&env->parser.header, sizeof(t_header));
	write(fd, env->treat.champ, env->treat.prog_size);
	close(fd);
}
