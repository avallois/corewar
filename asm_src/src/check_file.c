/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 10:38:10 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/15 15:33:48 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	check_extension(t_asm *env, char *file_name)
{
	if (!(file_name) || ft_strcmp(file_name + ft_strlen(file_name) - 2, ".s"))
		handle_error(env, ERROR_FILE_NAME);
}

static void	get_file_descriptor(t_asm *env, char *file_name)
{
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == ERROR)
		handle_error(env, ERROR_FD);
	env->file.fd = fd;
}

static void	check_eof(t_asm *env)
{
	off_t	old_offset;
	off_t	end_offset;
	int		fd;
	char	c;
	int		ret;

	c = 0;
	fd = env->file.fd;
	old_offset = lseek(fd, 0, SEEK_CUR);
	end_offset = lseek(fd, -1, SEEK_END);
	ret = read(fd, &c, 1);
	if (c != '\n')
		handle_error(env, ERROR_EOF);
	if (old_offset < 0 || end_offset < 0 || ret < 0)
		handle_error(env, ERROR_FD);
	else
		lseek(fd, old_offset, SEEK_SET);
}

void		check_file(t_asm *env)
{
	char	*file_name;

	file_name = env->file.src_name;
	get_file_descriptor(env, file_name);
	check_extension(env, file_name);
	check_eof(env);
}
