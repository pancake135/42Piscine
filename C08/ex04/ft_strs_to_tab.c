/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujchoi <ujchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 00:57:16 by ujchoi            #+#    #+#             */
/*   Updated: 2026/08/13 00:57:36 by ujchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*arr;
	int		i;

	i = 0;
	while (src[i])
		i++;
	arr = (char *)malloc(sizeof(char) * (i + 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		arr[i] = src[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*x;
	int			i;

	x = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (x == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		x[i].size = len(av[i]);
		x[i].str = av[i];
		x[i].copy = ft_strdup(av[i]);
		if (x[i].copy == NULL)
		{
			while (--i >= 0)
				free(x[i].copy);
			free(x);
			return (NULL);
		}
		i++;
	}
	x[i].str = 0;
	return (x);
}
