/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujchoi <ujchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 12:38:36 by ujchoi            #+#    #+#             */
/*   Updated: 2026/08/19 16:37:21 by ujchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*box;
	int	i;

	i = 0;
	if (!tab || length <= 0 || !f)
		return (NULL);
	box = (int *)malloc(sizeof(int) * length);
	if (!box)
		return (NULL);
	while (i < length)
	{
		box[i] = f(tab[i]);
		i++;
	}
	return (box);
}
