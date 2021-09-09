/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:49:58 by tkleynts          #+#    #+#             */
/*   Updated: 2020/08/03 15:35:13 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef unsigned long		t_ul;
typedef unsigned long long	t_ull;
typedef unsigned int		t_ui;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

int					frintf(const char *format, ...);
int					ffrintf(int fd, const char *format, ...);
int					ft_gnl(int fd, char **line);

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isspace(int c);
int					is_str_digit(char *str);

size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s1);
int					ft_strcmp(char *s1, char *s2);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strndup(const char *s1, size_t size);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strjoin2(char *s1, char *s2);
char				*ft_strnjoin(char *s1, char *s2,
									size_t size1, size_t size2);
char				*ft_strnjoin2(char *s1, char *s2,
									size_t size1, size_t size2);
char				*ft_strtrim(char const *s1, char const *set);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
int					ft_strncmp(const char *s1, const char *s2, size_t size);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t len);
char				**split_space(char const *s);
char				*rm_spaces(char *str);

void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);

int					ft_atoi(const char *str);
char				*ft_utoa(unsigned int n);
char				*ft_itohex(unsigned long long num, char *base);
char				*ft_ptohex(unsigned long long num, char *base);
char				*ft_itoa(int n);
uint16_t			swap_uint16(uint16_t val);
int16_t				swap_int16(int16_t val);
uint32_t			swap_uint32(uint32_t val);
int32_t				swap_int32(int32_t val);

char				*ft_strncpy(char *dest, const char *src, size_t len);

#endif
