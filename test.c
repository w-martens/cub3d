/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: y4k_wm <y4k_wm@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 15:18:24 by y4k_wm        #+#    #+#                 */
/*   Updated: 2021/03/09 18:49:49 by wmartens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" 


void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    char    *dst;

    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	winclose(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
    	mlx_destroy_window(mlx->ptr, mlx->win);
	}
}

int	main(void)
{
	t_vars	vars;
    vars.mlx.ptr = mlx_init();
    vars.mlx.win = mlx_new_window(vars.mlx.ptr, 640, 480, "heyyyyyyy");
	vars.img.img = mlx_new_image(vars.mlx.ptr, 640, 480);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);

	mlx_hook(vars.mlx.win, 2, 1L<<0, winclose, &vars.mlx);
    mlx_loop(vars.mlx.ptr);
}