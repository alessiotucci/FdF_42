/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:38:39 by atucci            #+#    #+#             */
/*   Updated: 2023/02/01 15:57:23 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H	
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              STRUCT PROTOTYPES
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              FUNCTION PROTOTYPES
*/
int		ft_isalpha(int argum);
int		ft_isdigit(int argum);
int		ft_isalnum(int argum);
int		ft_isascii(int argum);
int		ft_isprint(int argum);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *dest, int v, size_t count);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *sour, size_t n);
void	*ft_memmove(void *dest, const void *sour, size_t n);
size_t	ft_strlcpy(char *dest, const char *sour, size_t size);
size_t	ft_strlcat(char *dest, const char *sour, size_t destsize);
int		ft_toupper(int argum);
int		ft_tolower(int argum);
char	*ft_strchr(const char *str, int d);
char	*ft_strrchr(const char *str, int d);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *sour);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		pt_putchar(char c);
int		pt_strlen(const char *str);
int		ft_putnbr(int n);
int		pt_putstr(char *str);
int		ft_printf(const char *format, ...);
int		ft_len_u(unsigned long n);
int		ft_pointer(unsigned long nb);
int		ft_number_base(unsigned long long int nbr, char *base);
int		check_sign(int num);
int		ft_putuns(unsigned int nbr);
int		check_sign_flags(const char *str, int i);
int		pt_print_padding(char c, int width);
int		check_formatting_flags(const char *str, int i);
int		print_sign(int n);

#endif 
