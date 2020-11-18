/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnljoin.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmartens <wmartens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 18:51:58 by wmartens      #+#    #+#                 */
/*   Updated: 2020/11/13 14:26:44 by y4k_wm        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static char	*strjoiner(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (res == 0)
		return (0);
	while (s1[i] != '\0')
	{
		res[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		res[j] = s2[i];
		i++;
		j++;
	}
	res[j] = '\n';
	res[j + 1] = '\0';
	return (res);
}

char		*ft_strnljoin(char *s1, char *s2)
{
	char	*res;

	res = strjoiner(s1, s2);
	return (res);
}
