/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_parse.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: y4k_wm <y4k_wm@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 14:58:15 by y4k_wm        #+#    #+#                 */
/*   Updated: 2020/11/18 18:23:31 by y4k_wm        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// make floor R G B and fill it in store_resource

void freeloop(char **args)
{
	int i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void init_struct(t_cub3 *c_struct)
{
	c_struct->reswidth = 0;
	c_struct->resheight = 0;
	c_struct->notex = NULL;
	c_struct->sotex = NULL;
	c_struct->wetex = NULL;
	c_struct->eatex = NULL;
	c_struct->spritex = NULL;
	// c_struct->floor = {0, 0, 0};
	// c_struct->ceiling = {0, 0, 0};
}

void store_rgb(char **args, t_cub3 *c_struct)
{
	char **colors;
	int i;

	i = 0;
	colors = ft_split(args[1], ',');
	while (i < 3)
	{
		if (*args[0] == 'F')
			c_struct->floor[i] = ft_atoi(colors[i]);
		if (*args[0] == 'C')
			c_struct->ceiling[i] = ft_atoi(colors[i]);
		i++;
	}
	freeloop(colors);
}

void store_resource(char **args, t_cub3 *c_struct)
{
	if (*args[0] == 'R')
	{
		c_struct->reswidth = ft_atoi(args[1]);
		c_struct->resheight = ft_atoi(args[2]);
	}
	if (strcmp(args[0], "NO"))
		c_struct->notex = ft_strdup(args[1]);
	if (strcmp(args[0], "SO"))
		c_struct->sotex = ft_strdup(args[1]);
	if (strcmp(args[0], "WE"))
		c_struct->wetex = ft_strdup(args[1]);
	if (strcmp(args[0], "EA"))
		c_struct->eatex = ft_strdup(args[1]);
	if ((!strcmp(args[0], "SO")) && (strcmp(args[0], "S")))
		c_struct->spritex = ft_strdup(args[1]);
	if (*args[0] == 'F' || *args[0] == 'C')
		store_rgb(args, c_struct);
}

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

void	parse_map(int fd, char *line, char *mapfile, t_cub3 *c_struct)
{
	int i;

	i = 0;
	c_struct->map = (char**)malloc(sizeof(char *) * m_len(mapfile));
	while (get_next_line(fd, &line))
	{
		if (line)
			c_struct->map[i] = ft_strdup(line);
		i++;
		if (*line == '\n')
			break ;
		free(line);
	}
	free(line);
}

void	parser(char *mapfile, t_cub3 *c_struct)
{
	int		fd;
	char	*line;
	char	**args;

	fd = open(mapfile, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (line)
			args = ft_split(line, ' ');
		free(line);
		if (args[0] == NULL)
			break ;
		store_resource(args, c_struct);
		freeloop(args);
	}
	freeloop(args);
	parse_map(fd, line, mapfile, c_struct);
}
