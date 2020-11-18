/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: y4k_wm <y4k_wm@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/20 15:11:22 by y4k_wm        #+#    #+#                 */
/*   Updated: 2020/11/11 16:46:41 by y4k_wm        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "utils/utils.h"
# include <fcntl.h>
# include "c_struct.h"
# include <stdio.h>

void init_struct(t_cub3 *c_struct);
void parse_map(char *map, t_cub3 *c_struct);

#endif