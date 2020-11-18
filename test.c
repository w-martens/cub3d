/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: y4k_wm <y4k_wm@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 15:18:24 by y4k_wm        #+#    #+#                 */
/*   Updated: 2020/11/18 17:19:23 by y4k_wm        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void print_map(t_cub3 *c_struct)
{
	int i;

	i = 0;

	printf("\n res= \t%i, %i", c_struct->reswidth, c_struct->resheight);
	printf("\n no= \t%s", c_struct->notex);
	printf("\n so= \t%s", c_struct->sotex);
	printf("\n we= \t%s", c_struct->wetex);
	printf("\n ea= \t%s", c_struct->eatex);
	printf("\n spr= \t%s", c_struct->spritex);
	printf("\n floor= \t%i,%i,%i", c_struct->floor[0], \
	c_struct->floor[1], c_struct->floor[2]);
	printf("\n ceiling= \t%i,%i,%i\n\n", c_struct->ceiling[0],\
	c_struct->ceiling[1], c_struct->ceiling[2]);

	while (c_struct->map[i] != NULL)
	{
		printf("%s\n", c_struct->map[i]);
		i++;
	}
}

// void freeloop1(char **args)
// {
// 	int i;

// 	i = 0;
// 	while (*args[i] != NULL)
// 	{
// 		free(*args[i]);
// 		i++;
// 	}
// 	free(*args);
// }

void free_struct(t_cub3 *c_struct)
{
	int i;
	i = 0;

	free(c_struct->notex);
	free(c_struct->sotex);
	free(c_struct->wetex);
	free(c_struct->eatex);
	free(c_struct->spritex);

	while (c_struct->map[i] != NULL)
	{
		free(c_struct->map[i]);
		i++;
	}

	free(c_struct->map[i]);
	free(c_struct->map);
}

int	main(void)
{
	t_cub3 c_struct;

	init_struct(&c_struct);
	parse_map("map.txt", &c_struct);
	print_map(&c_struct);

	// int i;

	// i = 0;
	// while (*c_struct.map[i] != NULL)
	// {
	// 	free(*c_struct.map[i]);
	// 	i++;
	// }
	free_struct(&c_struct);
	return(0);
}
