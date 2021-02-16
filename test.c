/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: y4k_wm <y4k_wm@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 15:18:24 by y4k_wm        #+#    #+#                 */
/*   Updated: 2021/02/11 14:19:12 by wmartens      ########   odam.nl         */
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

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

typedef	struct	s_vars
{
	void	*mlx;
	void	*win;
	int		*keycode;
	t_data		img;
	int mousex;
	int mousey;		
	int i;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	int i;
	i = 0;
	return (keycode);
}

void square(t_data *img, void *mlx, void *mlx_win, t_vars *vars)
{
	int x = vars->mousex;
	int y = vars->mousey;
	int color = create_trgb(0, 255, 0, 0);
	img->img = mlx_new_image(mlx, 640, 480);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	while (x < (vars->mousex + 50))
	{
		my_mlx_pixel_put(img, x, y, color);
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0); 
	x = vars->mousex;
	while (y < (vars->mousey + 50))
	{
		my_mlx_pixel_put(img, vars->mousex, y, color);
		my_mlx_pixel_put(img, (vars->mousex + 50), y, color);
		y++;
	}
	x = vars->mousex;
	while (x < (vars->mousex + 50))
	{
		my_mlx_pixel_put(img, x, y, color);
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
}
// links 123
// rechts 124
// boven 126
// beneden 125

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
    // printf("%i,\t%i\n", x, y);
	vars->mousex = x;
	vars->mousey = y;
	return(button);
}

int squareprint(t_vars *vars)
{
	if((vars->mousex > 0) || (vars->mousey > 0))
	{
		square(&vars->img, vars->mlx, vars->win, vars);
		vars->mousex = 0;
		vars->mousey = 0;
	}
	return(0);
}

int	winclose(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
    	mlx_destroy_window(vars->mlx, vars->win);
	}
}

int	main(void)
{
	t_vars	vars;
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	vars.img.img = mlx_new_image(vars.mlx, 640, 480);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);

    // mlx_key_hook(vars.win, key_hook, &vars);
	vars.mousex = 0;
	vars.mousey = 0;
	vars.i = 0;
	// square(&vars.img, vars.mlx, vars.win, &vars);
    mlx_mouse_hook(vars.win, mouse_hook, &vars);
	// mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 2, 1L<<0, winclose, &vars);
	mlx_loop_hook(vars.mlx, squareprint, &vars);
    mlx_loop(vars.mlx);
}
