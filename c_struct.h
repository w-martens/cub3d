/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   c_struct.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: y4k_wm <y4k_wm@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 14:29:32 by y4k_wm        #+#    #+#                 */
/*   Updated: 2020/11/18 18:06:16 by y4k_wm        ########   odam.nl         */
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

#endif
