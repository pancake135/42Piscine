/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujchoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 09:05:49 by ujchoi            #+#    #+#             */
/*   Updated: 2026/07/31 09:54:10 by ujchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	idx;
	int	temp;

	idx = 0;
	while (size > idx)
	{
		temp = tab[size - 1];
		tab[size - 1] = tab[idx];
		tab[idx] = temp;
		size--;
		idx++;
	}
}
