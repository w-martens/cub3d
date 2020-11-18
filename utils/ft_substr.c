/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmartens <wmartens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 15:48:49 by wmartens      #+#    #+#                 */
/*   Updated: 2020/11/11 15:21:09 by y4k_wm        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static char	*strmaker(char const *s, unsigned int start, int len, \
	char *substr)
{
	int	i;

	i = 0;
	while (i < len && s[start] != '\0')
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}

char		*ft_substr(char const *s, unsigned int start, int len)
{
	int		startcopy;
	int	sublen;
	char	*substr;

	if (s == 0)
		return (0);
	if ((int)start > ft_strlen(s))
		return (ft_strdup(""));
	sublen = 0;
	startcopy = start;
	while (s[startcopy] != '\0')
	{
		sublen++;
		startcopy++;
	}
	if (sublen > len)
		sublen = len;
	substr = (char*)malloc(sizeof(char) * (sublen + 1));
	if (substr == 0)
		return (0);
	substr = strmaker(s, start, len, substr);
	return (substr);
}
