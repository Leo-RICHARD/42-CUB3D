/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 09:25:17 by lrichard          #+#    #+#             */
/*   Updated: 2021/09/19 15:40:10 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "fcntl.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				arglen(char type, int vard, unsigned int varx, char *vars);
int				gnl(int fd, char **line, int *ret);
float			vnorm(float *v);
float			*vadd(float **v, float *v2);
float			*vrotate(float **v, float angle);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_tablen(char **tab);
size_t			ft_strlen(const char *s);
size_t			ft_strlenc(char *s, char c);
int				intlen(int vard);
int				tablen(char **tab);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isesc(char c);
int				ft_abs(int nb);
float			absf(float nb);
int				ft_isprime(int nb);
int				ft_nextprime(int nb);
long long		ft_factorial(int nb);
long long		ft_power(int nb, int power);
float			sq(float nb);
int				ft_sqrt(int nb);
void			ft_sort_itab(int tab, int size);
void			ft_sort_strtab(char **tab);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strcase(char *mode, char *str);
char			*ft_strcchr(char *str, char c, int occ);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strcmp(char *s1, char *s2);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
int				ft_strcpy(char *dest, char *src);
char			*ft_strncpy(char *dest, char *src, int len);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
char			*ft_strcat(char *dest, char *src);
char			*ft_strncat(char *dest, char *src, int len);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strstr(char *s1, char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t len);
int				ft_checkbase(char *base, int blen);
int				ft_atoi(const char *nptr);
int				atoi_base(char *str, char *base);
char			*ft_itoa(int n);
char			*itoa_base(int n, char *base);
void			*nmalloc(void **var, int size);
void			*nmallloc(void ***var, int size);
void			*nealloc(void **var, int sizesupp);
void			*nealloc_abs(void **var, int size);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char *set);
char			*ft_convbase(char *input, char *ibase, char *obase);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			printc(char c);
void			prints(char *str);
void			prints_np(char *str);
void			printn(int nb);
void			printu(unsigned int nb);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*lstnew(void *content);
void			lstadd_front(t_list **alst, t_list *new);
int				lstsize(t_list *lst);
t_list			*lstlast(t_list *lst);
void			lstadd_back(t_list **alst, t_list *new);
void			lstdelone(t_list *lst, void (*del)(void*));
void			lstclear(t_list **lst, void (*del)(void*));
void			lstiter(t_list *lst, void (*f)(void *));
t_list			*lstmap(t_list *l, void *(*f)(void *), \
														void (*del)(void *));

#endif
