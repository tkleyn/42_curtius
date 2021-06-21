/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:03:53 by tkleynts          #+#    #+#             */
/*   Updated: 2021/06/21 15:03:55 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int	ft_fatoi(const char	*str, uint8_t	*flag)
{
	uint64_t	number;
	int			sign;

	*flag = 0;
	sign = 1;
	number = 0;
	while (*str == '\r' || *str == '\f' || *str == '\n' || *str == '\v'
		|| *str == '\t' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -sign;
	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str++ - '0');
		if ((number > INT32_MAX && sign == 1)
			|| (number > (uint64_t)INT32_MAX + 1 && sign == -1))
			return (*flag = 1);
	}
	if (*str != '\0')
		return (*flag = 1);
	return ((int)(number * sign));
}

uint64_t get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && *str)
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	char	*new_str_cpy;
	char	*s1_cpy;

	if (!s1 && !s2)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1));
	if (!new_str)
		return (NULL);
	new_str_cpy = new_str;
	s1_cpy = s1;
	while (s1 && *s1)
		*new_str_cpy++ = *s1++;
	while (s2 && *s2)
		*new_str_cpy++ = *s2++;
	if (s1_cpy)
		free(s1_cpy);
	*new_str_cpy++ = '\0';
	return (new_str);
}

char	*ft_ltoa(int64_t n)
{
	char	*str;
	int64_t	nc;
	size_t	len;
	char	sign;

	sign = (n < 0) ? -1 : 1;
	len = 2 + (n < 0);
	nc = n;
	while ((n = n / 10))
		len++;
	n = nc;
	if (NULL == (str = (char *)malloc(len--)))
		return (NULL);
	str[len--] = '\0';
	str[len--] = sign * (n % 10) + '0';
	while ((n = n / 10))
		str[len--] = sign * (n % 10) + '0';
	if (sign < 0)
		str[len] = '-';
	return (str);
}

