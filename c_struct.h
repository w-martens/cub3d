/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   c_struct.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: y4k_wm <y4k_wm@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 14:29:32 by y4k_wm        #+#    #+#                 */
/*   Updated: 2020/12/10 15:00:33 by wmartens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBEMAIN_H
# define CUBEMAIN_H

typedef	struct	s_cub3
{
	int		reswidth;
	int		resheight;
	char	*notex;
	char	*sotex;
	char	*wetex;
	char	*eatex;
	char	*spritex;
	int		floor[3];
	int		ceiling[3];
	char	**map;
}				t_cub3;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

#endif
