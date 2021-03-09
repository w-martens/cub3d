/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   config.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: y4k_wm <y4k_wm@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 14:29:32 by y4k_wm        #+#    #+#                 */
/*   Updated: 2021/03/09 18:27:27 by wmartens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "utils/utils.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

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

void	init_struct(t_cub3 *c_struct);
void	parser(char *map, t_cub3 *c_struct);
void	parse_map(int fd, char *line, char *mapfile, t_cub3 *c_struct);

#endif
