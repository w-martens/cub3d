/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: y4k_wm <y4k_wm@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 18:20:41 by y4k_wm        #+#    #+#                 */
/*   Updated: 2020/11/18 18:23:45 by y4k_wm        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "utils/utils.h"
# include <fcntl.h>
# include "c_struct.h"
# include <stdio.h>

void	init_struct(t_cub3 *c_struct);
void	parser(char *map, t_cub3 *c_struct);
void	parse_map(int fd, char *line, char *mapfile, t_cub3 *c_struct);

#endif
