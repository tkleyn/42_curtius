#include "libasm.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	
	//test ft_read
	char	str[8];
	int		fd;
	
	str[7] = '\0';
	fd = open("main.c", O_RDONLY);
	printf("READ NORMAL : %zd\n", read(fd, str, 7));
	printf("%s\n", str);
	close(fd);

	fd = open("main.c", O_RDONLY);
	printf("READ LIBASM : %zd\n", ft_read(fd, str, 7));
	printf("%s\n\n", str);
	close(fd);

	//test ft_write
	printf("WRITE NORMAL : %zd\n", write(1, "writetest12\n", 13));
	printf("WRITE LIBASM : %zd\n\n", ft_write(1, "writetest12\n", 13));

	//test ft_strlen
	printf("STRLEN NORMAL : %zu\n", strlen("strlentest12\n"));
	printf("STRLEN LIBASM : %zu\n\n", ft_strlen("strlentest12\n"));

	//test ft_strcmp
	printf("STRCMP NORMAL : %d\n", strcmp("test", "test"));
	printf("STRCMP LIBASM : %d\n\n", ft_strcmp("test", "test"));

	//test ft_strdup
	printf("STRDUP NORMAL : %s\n", strdup("poi^p"));
	printf("STRDUP LIBASM : %s\n\n", ft_strdup("poi^p"));

	//test ft_strcpy
	char	*ptr;

	ptr = malloc(5);
	printf("STRCPY NORMAL : %s\n", strcpy(ptr, "copy"));
	printf("STRCPY LIBASM : %s\n\n", ft_strcpy(ptr, "copy"));
	return (0);
}