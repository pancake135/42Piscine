/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujchoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 09:40:44 by ujchoi            #+#    #+#             */
/*   Updated: 2026/07/31 09:52:49 by ujchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	idx;
	int	idx0;
	int	temp;

	idx0 = size - 1;
	while (idx0 > 0)
	{
		idx = size - 1;
		while (idx > 0)
		{
			if (tab[idx] < tab[idx - 1])
			{
				temp = tab[idx];
				tab[idx] = tab[idx - 1];
				tab[idx - 1] = temp;
			}
			idx--;
		}
		idx0--;
	}
}
