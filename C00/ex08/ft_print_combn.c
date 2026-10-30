/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujchoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 14:43:15 by ujchoi            #+#    #+#             */
/*   Updated: 2026/08/10 14:43:18 by ujchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(int n, int *box)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(box[i] + '0');
		i++;
	}
}

void	ft_sort(int n, int *box, int idx, int i)
{
	if (idx == n)
	{
		if (box[0] == 11 - n)
		{
			if (box[n - 1] == 9)
				write(1, "\n", 1);
		}
		else if (box[n - 1] != n -1)
			write(1, ", ", 2);
		ft_print(n, box);
	}
	while (i <= 9)
	{
		box[idx] = i;
		ft_sort(n, box, idx + 1, i + 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	idx;
	int	box[10];

	idx = 0;
	while (idx < 10)
	{
		box[idx] = 0;
		idx++;
	}
	ft_sort(n, box, 0, 0);
}
