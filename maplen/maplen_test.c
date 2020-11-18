
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int m_len(char *mapfile)
{
	int i;
	int fd;
	char buf[1];

	i = 0;
	fd = open(mapfile, O_RDONLY);
	while (read(fd, buf, 1))
	{
		if (buf[0] == '\n')
		{
			read(fd, buf, 1);
			if (buf[0] == '\n')
				break ;
		}
	}
	while (read(fd, buf, 1))
	{
		if (buf[0] == '\n')
			i++;
	}
	return (i);
}

int main(void)
{ 	
	int i;

	i = 0;
	i = m_len("map.txt");
	printf("%i", i);
}