/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:47:40 by tkleynts          #+#    #+#             */
/*   Updated: 2019/11/15 16:48:41 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		line_packager(char **line, char **rest)
{
	char *endl_found;

	if ((endl_found = endl_check(*rest)))
	{
		//printf("old rest : %s\n", *rest);
		if ((*line = ft_strmdup(*rest, endl_found - *rest)) < 0)
			return (-1);
		if ((endl_found = ft_strmdup(endl_found + 1, -1)) < 0)
			return (-1);
		free(*rest);
		//printf("line : %s\n", *line);
		//printf("new rest : %s\n\n\n\n", *rest);
		*rest = endl_found;
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char			read_buff[BUFFER_SIZE + 1];
	static char		*rest;
	int				read_size;
	int				package_return;

	if (!line || fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (ft_desaloc(line, &rest));
	*line = NULL;
	if (rest)
	{
		package_return = line_packager(line, &rest);
		if (package_return == 1)
			return (1);
		else if (package_return == 1)
			return (ft_desaloc(line, &rest));
	}
	while ((read_size = read(fd, read_buff, BUFFER_SIZE)) > 0)
	{
		//printf("old rest : %s\n", rest);
		//printf("read : %s\n", read_buff);
		rest = ft_strjoin(rest, read_buff);
		//printf("new rest : %s\n", rest);

		package_return = line_packager(line, &rest);
		if (package_return == 1)
			return (1);
		else if (package_return == 1)
			return (ft_desaloc(line, &rest));
	}
	if (read_size < 0)
		return (ft_desaloc(line, &rest));
	*line = ft_strmdup(rest, -1);
	rest = NULL;
	return (0);
}


/*int main()
{
	char *line;
	int		out;
	int		p[2];
	int		fd;
	int		gnl_ret;

	fd = 1;
	out = dup(fd);
	pipe(p);
	dup2(p[1], fd);
	write(fd, "aaa", 3);
	close(p[1]);
	dup2(out, fd);
	gnl_ret = get_next_line(p[0], &line);
	printf("%s", line);
	free(line);
}

#include <fcntl.h>

int main (int argc, char **argv)
{
	int fd;
	int i = 0;

	if (argc == 2)	
		fd = open(argv[1], O_RDONLY);
	else
		fd = open("get_next_line_utils.c", O_RDONLY);
	
	char *line;

	while (get_next_line(1, &line))
		{
			printf("ligne %d %s\n",i, line);
			i++;
		}
	//close(fd);
}
*/