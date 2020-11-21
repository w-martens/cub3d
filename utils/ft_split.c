/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmartens <wmartens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 21:46:53 by wmartens      #+#    #+#                 */
/*   Updated: 2020/11/11 15:20:54 by y4k_wm        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void		free_loop(char **res)
{
	int i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}

static char		*fill_2(char *res, char const *s, char c, int *j)
{
	int len;

	len = 0;
	while (s[*j] != '\0')
	{
		if (s[*j] != c)
		{
			while (s[*j] != c && s[*j] != '\0')
			{
				(*j)++;
				len++;
			}
			res = ft_substr(s, (*j - len), len);
			len = 0;
			break ;
		}
		(*j)++;
	}
	return (res);
}

static char		**fill_1(char **res, char const *s, char c, int scnt)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < scnt)
	{
		res[i] = fill_2(res[i], s, c, &j);
		if (res[i] == NULL)
		{
			free_loop(res);
			return (NULL);
		}
		i++;
	}
	return (res);
}

static int		scntr(char const *s, char c)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			ret++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		if (s[i] == '\0')
			return (ret);
		i++;
	}
	return (ret);
}

char			**ft_split(char const *s, char c)
{
	char	**res;
	int		scnt;

	if (!s || s[0] == '\0')
	{
		res = malloc(sizeof(char*) * 1);
		if (res == 0)
			return (NULL);
		res[0] = NULL;
		return (res);
	}
	scnt = scntr(s, c);
	res = malloc(sizeof(char*) * (scnt + 1));
	if (!res)
		return (NULL);
	else
	{
		res = fill_1(res, s, c, scnt);
		res[scnt] = NULL;
	}
	return (res);
}
