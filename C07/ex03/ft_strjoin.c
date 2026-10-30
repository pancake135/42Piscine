/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujchoi <ujchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 16:01:05 by ujchoi            #+#    #+#             */
/*   Updated: 2026/08/13 18:02:03 by ujchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	totallen(char **strs, char *sep, int size)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (i < size)
	{
		cnt += ft_strlen(*strs);
		strs++;
		i++;
	}
	cnt += ft_strlen(sep) * (size - 1);
	return (cnt + 1);
}

char	*mkstr(int size, char **strs, char *sep, char *strbox)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	len = 0;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			strbox[len] = strs[i][j];
			len++;
			j++;
		}
		j = 0;
		while (sep[j] && i != size - 1)
		{
			strbox[len] = sep[j];
			len++;
			j++;
		}
	}
	strbox[len] = '\0';
	return (strbox);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*strbox;
	int		len;

	if (size <= 0)
	{
		strbox = (char *)malloc(1);
		if (!strbox)
			return (NULL);
		strbox[0] = '\0';
		return (strbox);
	}
	len = totallen(strs, sep, size);
	strbox = (char *)malloc(sizeof(char) * len);
	if (!strbox)
		return (NULL);
	mkstr(size, strs, sep, strbox);
	return (strbox);
}
