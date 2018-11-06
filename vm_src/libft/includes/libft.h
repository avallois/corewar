/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 21:57:51 by cjumelin          #+#    #+#             */
/*   Updated: 2018/10/01 16:14:47 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# define BUFF_SIZE 100
# define NBFD 1111

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_point
{
	int			size;
	int			signe;
	long		nbr;
	char		*dst;
}				t_point;

typedef struct	s_base
{
	long					size;
	unsigned long long		nbr;
	char					*dst;
}				t_base;

typedef struct	s_list_fd
{
	int					fd;
	struct s_list_fd	*next;
	char				buf[BUFF_SIZE + 1];
}				t_list_fd;

typedef struct	s_lst
{
	int				fd;
	char			*temp;
	char			*cara;
	struct s_lst	*next;
	struct s_lst	*deb;
}				t_lst;

typedef struct	s_lst_str
{
	char				*s;
	struct s_lst_str	*n;
}				t_lst_str;

typedef struct	s_gnl
{
	char	**line;
	char	*buf;
	int		rt;
	int		fd;
}				t_gnl;

void			hex_dump(int c, unsigned char *p, unsigned char *s);
char			**ft_tstrcpy(char **tstr, size_t size);
int				ft_str_tstr_cmp(char **s, char **ts, size_t size);
void			*ft_p_ptab_cmp(void *p, void **ptab, size_t tab_size);
int				ft_add_p_to_ptab(void *p, void **ptab, size_t tab_size);
int				free_n_gnl(int const fd, char **line);
int				get_next_line(int fd, char **line);
char			*ft_add_str(char **s1, char *s2);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
ssize_t			ft_abs(ssize_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strndup(const char *s, int n);
char			*ft_strdup(const char *s);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalnum(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isdigit_str(char *str);
int				ft_isprint(int c);
void			ft_putstr_fd(char const *s, int fd);
void			*ft_memalloc(size_t size);
void			ft_putchar(char c);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_free_s1(char *s1, char *s2);
char			*ft_itoa(int n);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_puchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *n);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
