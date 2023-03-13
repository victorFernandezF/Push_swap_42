/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:27:10 by victofer          #+#    #+#             */
/*   Updated: 2023/03/09 12:41:14 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <signal.h>
# include <stdint.h>

/*BONUS*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(void *s1, const void *s2, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
long long	ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strtrim(char *s1, char *set);
char		**ft_split(char *s, char c);
char		**ft_split2(char *s);
char		*ft_itoa(int n);
char		*ft_strmapi(char *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

/* BONUS */
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* MORE FUNCTIONS ADDED  */
void		ft_put_bin(unsigned int num); //Print int to binary
void		ft_put_oct(unsigned int num); //Print int to octal
void		ft_put_hexa(unsigned int num);//Print int to Hexadecomal
char		*ft_str_rev(char *str);
int			ft_bin_to_dec(int num); //Return a binary number in decimal base
int			ft_dec_to_bin(int num); //Return a decimal number in binary base
int			ft_dec_to_oct(int num); //Return a decimal number in octal base
char		*ft_dec_to_hexa(int num); //Return a decimal number in hexa base
int			max(int *tab, unsigned int len); //Returns the max value of an array
int			min(int *tab, unsigned int len); //Returns the min value of an array
int			ft_pow(int n, int pow); //pow (pow(2, 3) -> 2 * 2 * 2) you know...
int			ft_power(int n, int pow); //pow (pow(2, 3) -> 2 * 2 * 2) you know...
int			ft_strcmp(char const *s1, char const *s2);

//FT_PRINTF AND RELATED FUNCTIONS
int			ft_printf(char const *input, ...); //Something like prinf
int			ft_print_char(int c);
int			ft_print_unsigned(unsigned int n); //print an unsigned int (ret)
char		*ft_unsigned_itoa(unsigned int n);
int			ft_print_ptr(unsigned long long ptr); //print pointer of void ...
int			ft_print_string(char *s);
int			ft_print_int(int n);
int			ft_print_hexa(unsigned int num, char format);
char		*ft_strcpy(char *dst, const char *src);

#endif
