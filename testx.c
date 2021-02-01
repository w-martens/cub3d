/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: y4k_wm <y4k_wm@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 15:18:24 by y4k_wm        #+#    #+#                 */
/*   Updated: 2020/12/10 19:15:27 by wmartens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./mlx/mlx.h"
#include <stdio.h>
void	print_map(t_cub3 *c_struct)
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

void	free_struct(t_cub3 *c_struct)
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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}
//############## rainbow funny
// void rainbow(t_data	*img)
// {
// 	int color;
// 	int i;
// 	int j;

// 	int r;
// 	int g;
// 	int b;

// 	int x;

// 	i = 5;
// 	j = 5;
// 	r = 255;
// 	g = 0;
// 	b = 0;
	
// 	while (i < 1920)
// 	{
// 		while (j < 1080)
// 		{
// 		color = create_trgb(0, r, g, b);
// 		my_mlx_pixel_put(img, i, j, color);
// 		j++;
// 		}
// 		j = 5;
// 		if ((g < 255) && (b != 255))
// 			g++;
// 		if ((g == 255) && (r > 0))
// 			r--;
// 		if ((r == 0) && (b < 255))
// 			b++;
// 		if ((b == 255) && (b > 0))
// 			g--;
// 		i++;
// 		i++;
// 		while (j < 1080)
// 		{
// 		color = create_trgb(0, r, g, b);
// 		my_mlx_pixel_put(img, i, j, color);
// 		j++;
// 		j++;
// 		}		
// 	}
// }

// int	main(void)
// {
// 	t_cub3	c_struct;
// 	t_data	img;
// 	t_data	img2;
// 	// init_struct(&c_struct);
// 	// parser("map.txt", &c_struct);
// 	// print_map(&c_struct);

// 	// int i;

// 	// i = 0;
// 	// while (*c_struct.map[i] != NULL)
// 	// {
// 	// 	free(*c_struct.map[i]);
// 	// 	i++;
// 	// }

// 	void	*mlx;
// 	void	*mlx_win;
// 	int		i;
// 	int		j;
// 	int		l;
// 	int color;
// 	i = 1;
// 	j = 1;
// 	l = 0;

// 	color = 0;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img2.img = mlx_new_image(mlx, 1920, 1080);

// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	img2.addr = mlx_get_data_addr(img2.img, &img2.bits_per_pixel, &img2.line_length, &img2.endian);

// 	rainbow(&img);

// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);

// 	// free_struct(&c_struct);
// 	return (0);
// }

typedef struct  s_vars {
    void        *mlx;
    void        *win;
}               t_vars;

int             mouse_hook(int button, int x, int y, t_vars *vars)
{
    printf("%i,\t%i\n", x, y);
}

int             main(void)
{
    t_vars      vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
    mlx_mouse_hook(vars.win, mouse_hook, &vars);
    mlx_loop(vars.mlx);
}