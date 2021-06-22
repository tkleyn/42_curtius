/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:03:53 by tkleynts          #+#    #+#             */
/*   Updated: 2021/06/22 12:20:18 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

uint64_t	get_time(void)
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

static void	lengths(long int n, size_t *len, long int *weight)
{
	*len = 1;
	if (n >= 0)
	{
		*len = 0;
		n = -n;
	}
	*weight = 1;
	while (n / *weight < -9)
	{
		*weight *= 10;
		*len += 1;
	}
}

char	*ft_ltoa(int64_t n)
{
	size_t		len;
	long int	weight;
	size_t		cur;
	char		*str;

	lengths(n, &len, &weight);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	cur = 0;
	if (n < 0)
	{
		str[cur] = '-';
		cur++;
	}
	if (n > 0)
		n = -n;
	while (weight >= 1)
	{
		str[cur++] = -(n / weight % 10) + 48;
		weight /= 10;
	}
	str[cur] = '\0';
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	if (!s1)
		return (-1);
	while (size != 0 && (*s1 || *s2))
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		size--;
		s1++;
		s2++;
	}
	return (0);
}
