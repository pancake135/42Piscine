/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujchoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 14:59:22 by ujchoi            #+#    #+#             */
/*   Updated: 2026/08/03 15:21:59 by ujchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	f;

	i = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		f = 0;
		while (str[i + f] == to_find[f] && str[i + f]
			!= '\0' && to_find[f] != '\0')
			f++;
		if (to_find[f] == '\0')
			return (&str[i]);
		i++;
	}
	return (NULL);
}
