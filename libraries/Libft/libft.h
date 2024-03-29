/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:49:36 by parthur-          #+#    #+#             */
/*   Updated: 2024/02/20 02:47:06 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define FD_MAX 1024

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_node
{
	long int		value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

long int		ft_atoi(const char *nptr);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_itoa(int n);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
t_list			*ft_lstlast(t_list *lst);
int				ft_lstsize(t_list *lst);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void
					*(*f)(void *), void (*del)(void *));
char			*get_next_line(int fd);
char			*free_variable(char *variable);
char			*adjust_pointer(char *str);
char			*make_line(char *str);
char			*read_line(int fd, char *line, ssize_t bytesread);
char			*ft_strjoin_gnl(char *s1, char *s2);
size_t			ft_strlen_gnl(char *s);
int				ft_putaddress(unsigned long p);
int				ft_puthexa(unsigned long p, char ch);
int				ft_putchar(char c);
int				ft_putstr(char *s);
char			*ft_toupper_printf(char *str);
int				ft_strlen_printf(const char *s);
char			*inverts(char *str);
int				ft_printf(const char *str, ...);
int				ft_itoa_printf(long int n);
size_t			matrix_len(char **mat);
char			*ft_strpchr(const char *s, int c, int index);
t_node			*new_dnode(int content);
t_node			*remove_node_dlist(t_node *node);
void			init_double_list(t_node **tail, t_node **head, int content);
void			free_double_list(t_node **head, t_node **tail);
void			add_dnode_front(t_node **tail, t_node *new);
void			add_dnode_back(t_node **head, t_node *new);
void			insert_after_dlist(t_node *curr, t_node *after);
void			insert_before_dlist(t_node *curr, t_node *before);
t_node			*go_to_tail(t_node *node);
t_node			*go_to_head(t_node *node);
#endif