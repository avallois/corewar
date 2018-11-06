/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 00:14:31 by cjumelin          #+#    #+#             */
/*   Updated: 2017/10/13 02:09:06 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_read(t_gnl *d, t_list_fd *l, t_list_fd *first)
{
	int			r;
	t_list_fd	*tmp;

	ft_bzero(d->buf, BUFF_SIZE + 1);
	r = read(d->fd, d->buf, BUFF_SIZE);
	if (r != -1)
		d->buf[r] = '\0';
	tmp = first;
	if (r == 0)
	{
		if (tmp != l && l->next)
		{
			while (tmp->next != l)
				tmp = tmp->next;
			tmp = l->next;
		}
		free(l);
	}
	return (r);
}

void		buf_have_rc(char *ptr, t_gnl *d)
{
	char	*tmp;

	if ((*d->line))
	{
		tmp = (*d->line);
		(*d->line) = ft_strjoin(tmp, ptr);
		if (tmp)
		{
			free(tmp);
			tmp = NULL;
		}
	}
	else
		(*d->line) = ft_strdup(ptr);
}

int			ft_join(t_gnl *d, t_list_fd *l, t_list_fd *first)
{
	char	*ptr;
	char	*end;

	while ((end = ft_strchr(d->buf, '\n')) == NULL)
	{
		buf_have_rc(d->buf, d);
		if ((d->rt = ft_read(d, l, first)) < 1)
			return (d->rt || ft_strlen((*d->line)) != 0);
	}
	ptr = ft_strsub(d->buf, 0, (int)(end - d->buf));
	if (ptr != NULL)
	{
		buf_have_rc(ptr, d);
		free(ptr);
	}
	ft_strcpy(d->buf, end + 1);
	return (d->rt);
}

t_list_fd	*add_or_match_fd(t_list_fd **first, int fd)
{
	t_list_fd	*new;

	if (!*first)
	{
		if ((new = (t_list_fd *)malloc(sizeof(*new))) == NULL)
			return ((void*)0);
		ft_memset(new->buf, 0, BUFF_SIZE + 1);
		new->fd = fd;
		new->next = NULL;
		return ((*first = new));
	}
	new = *first;
	while (new->fd != fd && new->next != NULL)
		new = new->next;
	if (new->fd == fd)
		return (new);
	if (new->next == NULL)
	{
		if ((new->next = (t_list_fd *)malloc(sizeof(*new->next))) == NULL)
			return ((void *)0);
		ft_memset(new->next->buf, 0, BUFF_SIZE + 1);
		new->next->fd = fd;
		new->next->next = NULL;
	}
	return (new->next);
}

int			get_next_line(int const fd, char **line)
{
	static t_list_fd		*first = NULL;
	t_list_fd				*l;
	t_gnl					f;
	t_gnl					*d;

	d = &f;
	d->line = line;
	d->fd = fd;
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	if ((l = add_or_match_fd(&first, d->fd)) == NULL)
		return (-1);
	d->rt = 1;
	d->buf = l->buf;
	if (((*d->line) = malloc(1)) == NULL)
		return (-1);
	(*d->line)[0] = 0;
	if (d->buf[0] == '\0')
		if ((d->rt = ft_read(d, l, first)) < 1)
			return (d->rt);
	d->rt = ft_join(d, l, first);
	if (d->rt > 1)
		d->rt = 1;
	return (d->rt);
}
