/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 13:37:21 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/20 05:34:54 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>

/*
**		DEFINE
*/

# define ERROR			-1
# define SUCCESS		0
# define TRUE			1
# define FALSE			0
# define GNL_BUFF_SIZE	32

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

/*
**		STRING
*/

int					check_char_into_str(char *str, char c);
void				ft_putendl_fd(char const *s, int fd);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
ssize_t				ft_strclen(char *s, char c);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnew(size_t size);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_skip_spaces(char *str);
int					get_next_line(int const fd, char **line);
long long			ft_atoll(const char *str);
int					ft_isdigit(int c);
int					ft_isspace(int c);

/*
**		LIST
*/

void				ft_lst_del(t_list **alst, void (*del)(void *, size_t));
void				ft_lst_memclr(void *content, size_t content_size);
t_list				*ft_lst_push_back(t_list **alst, t_list *new);
t_list				*ft_lstnew(void const *content, size_t content_size);

/*
**		MEMORY
*/

void				ft_memdel(void **ap);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*print_memory(void *addr, unsigned long size);
int					ft_dup_memory(void **dest, const void *src, size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memalloc(size_t size);

#endif
