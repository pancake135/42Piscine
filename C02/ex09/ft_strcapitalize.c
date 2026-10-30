/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujchoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 17:53:51 by ujchoi            #+#    #+#             */
/*   Updated: 2026/08/02 11:41:09 by ujchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_jubge(char *str, int i, int j)
{
	if (j == 0)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] += 'A' - 'a';
			j = 1;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			j = 1;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			j = 1;
	}
	else if (j == 1)
	{
		if (!((str[i] >= 'a' && str[i] <= 'z')
		&& (str[i] >= 'A' && str[i] <= 'Z') && (str[i] >= '0' && str[i] <= '9')))
			j = 0;
		if (str[i] >= '0' && str[i] <= '9')
			j = 1;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'a' - 'A';
		else if (str[i] >= 'a' && str[i] <= 'z')
			j = 1;
	}
	return (j);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		j = ft_jubge(str, i, j);
		i++;
	}
	return (str);
}
