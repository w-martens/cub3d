/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: y4k_wm <y4k_wm@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 12:13:25 by y4k_wm        #+#    #+#                 */
/*   Updated: 2020/11/18 17:52:17 by y4k_wm        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	if (s1 == NULL)
		return (0);
	while (s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}