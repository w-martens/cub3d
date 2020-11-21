/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmartens <wmartens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 15:59:59 by wmartens      #+#    #+#                 */
/*   Updated: 2020/11/11 17:33:44 by y4k_wm        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_atoix(const char *str, long int res, long int sign, long int tmp)
{
	int i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = res;
		res = (res * 10) + str[i] - '0';
		i++;
	}
	if (tmp > res)
	{
		if (sign > 0)
			return (-1);
		else
			return (0);
	}
	return ((int)res * (int)sign);
}

int			ft_atoi(const char *str)
{
	int res;

	res = ft_atoix(str, 0, 1, 0);
	return (res);
}
