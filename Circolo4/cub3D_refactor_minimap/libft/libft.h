/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:46:20 by fcardina          #+#    #+#             */
/*   Updated: 2023/10/13 03:35:19 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				ft_arrdel(char ***arr);
double				ft_atof(const char *str);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_countchar(char *s, char c);
char				**ft_dup_matrix(char **m);
char				**ft_extend_matrix(char **in, char *newstr);
void				ft_free_matrix(char ***m);
char				*get_next_line(int fd);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isnbr(char *str);
int					ft_isprint(int c);
int					ft_isspace(char c);
char				*ft_itoa(int n);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
int					ft_matrixlen(char **m);
char				**ft_matrix_replace_in(char ***big, char **small, int n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
int					ft_hex_len(unsigned	int num);
int					ft_print_ptr(unsigned long long ptr);
int					ft_print_unsigned(unsigned int n);
int					ft_printf(const char *str, ...);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char *s);
int					ft_putendl_fd(char *s, int fd);
int					ft_putmatrix_fd(char **m, int nl, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
void				ft_split_free(char **s);
int					ft_strchars_i(const char *s, char *set);
char				*ft_strchr(const char *s, int c);
char				*ft_strchr1(char *s, int c);
int					ft_strchr_i(const char *s, int c);
int					ft_strcmp(char *s1, char *s2);
void				ft_strdel(char **as);
char				*ft_strdup(const char *src);
char				*ft_strdup1(char *s1);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin1(char *s1, char *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
unsigned int		ft_strlen(const char *s);
size_t				ft_strlen_const(char **s);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strnrcmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);

char				*ft_extract(char *save);
char				*ft_overwrite(char *save);
char				*ft_read_and_save(int fd, char *save);

#endif
