/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujchoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 15:17:03 by ujchoi            #+#    #+#             */
/*   Updated: 2026/07/30 15:25:49 by ujchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	cont(int n)
{
	ft_putchar((n / 10) + '0');
	ft_putchar((n % 10) + '0');
}

void	ft_print_comb2(void)
{
	int	n1;
	int	n2;

	n1 = 0;
	while (n1 != 99)
	{
		n2 = n1 + 1;
		while (n2 != 100)
		{
			cont(n1);
			write(1, &" ", 1);
			cont(n2);
			if (!(n1 == 98 && n2 == 99))
			{
				write(1, &", ", 2);
			}
			n2++;
		}
		n1++;
	}
}
