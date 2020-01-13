/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dpattij <dpattij@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 17:51:38 by dpattij        #+#    #+#                */
/*   Updated: 2019/11/05 21:20:28 by dpattij       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef NULL
#  define NULL (void *)0
# endif

# ifndef LONG_MAX
#  define LONG_MAX 0x7FFFFFFFFFFFFFFFL
# endif

# define SUCCESS				0x0
# define ERROR_GENERIC			0x1
# define ERROR_MALLOC_FAILED	0x2

typedef unsigned long long t_size;

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_vec
{
	void			**raw;
	t_size			capacity;
	t_size			size;
}					t_vec;

int					vec_new(t_vec *new);
int					vec_with_capacity(t_vec *new, t_size capacity);
int					vec_push(t_vec *self, void *item);
void				*vec_get(t_vec *self, t_size index);
void				*vec_last(t_vec *self);
int					vec_extend(t_vec *self, t_size delta);
void				*vec_pop(t_vec *self);
int					vec_shrink(t_vec *self, t_size capacity);
int					vec_shrink_to_fit(t_vec *self);
void				*vec_drop(t_vec *self, void (*del)(void *));
int					ft_isalpha(int chr);
int					ft_isdigit(int chr);
int					ft_isalnum(int chr);
int					ft_isascii(int chr);
int					ft_isprint(int chr);
int					ft_isinset(char c, const char *set);
int					ft_isspace(int chr);
int					ft_isupper(int chr);
int					ft_islower(int chr);
int					ft_toupper(int chr);
int					ft_tolower(int chr);
void				*ft_calloc(t_size count, t_size size);
int					ft_atoi(const char *str);
void				*ft_memccpy(
	void *dest, const void *src, int term, t_size length);
void				*ft_memchr(
	const void *string, int occur, t_size length);
int					ft_memcmp(
	const void *str1, const void *str2, t_size length);
void				*ft_memcpy(void *dest, const void *src, t_size length);
void				*ft_memmove(void *dest, const void *src, t_size length);
void				*ft_memset(void *byte_string, int value, t_size length);
char				*ft_strchr(const char *str, int chr);
t_size				ft_strlcat(char *dest, const char *src, t_size dstsize);
t_size				ft_strlcpy(char *dest, const char *src, t_size dstsize);
t_size				ft_strlen(const char *str);
char				*ft_strnstr(
	const char *haystack, const char *needle, t_size len);
char				*ft_strrchr(const char *str, int chr);
int					ft_strncmp(
	const char *str1, const char *str2, t_size length);
char				*ft_strdup(const char *str);
void				ft_bzero(void *string, t_size length);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_substr(const char *s1, unsigned int start, t_size len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s1, const char *set);
t_size				ft_strsetcount(const char *s1, const char *set);
char				*ft_itoa(int n);
char				*ft_strmapi(const char *s1, char (*f)(unsigned int, char));
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(
	t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
