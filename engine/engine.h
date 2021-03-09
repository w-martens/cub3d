/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   engine.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmartens <wmartens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 18:01:58 by wmartens      #+#    #+#                 */
/*   Updated: 2021/03/09 18:30:26 by wmartens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

typedef struct	s_pos
{
	int		x;
	int		y;
}				t_pos;

typedef struct  s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	            t_img;

typedef	struct	s_mlx
{
	void	*ptr;
	void	*win;
}				t_mlx;

typedef struct	s_vars
{
	t_img img;
	t_mlx mlx;
}				t_vars;

#endif