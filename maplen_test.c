
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int m_len(char *mapfile)
{
	int i;
	int fd;
	int ret;
	char buf[2];

	i = 0;
	fd = open(mapfile, O_RDONLY);
	while (1)
	{
		ret = read(fd, buf, 1);
		if ((*buf == '\n') && ((*buf + 1) == '\n'));
			break ;
	}
	while (1)
	{
		ret = read(fd, buf, 1);
		if (*buf == '\n');
			i++;
		if (((*buf == '\n') && ((*buf + 1) == '\n')) || ret == 0);
			break ;
	}
}

int main(void)
{ 	
	int i;
	i = m_len("map.txt");
	printf("%i", i);
}