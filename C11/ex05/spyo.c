/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spyo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujchoi <ujchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 14:37:07 by ujchoi            #+#    #+#             */
/*   Updated: 2026/08/20 19:46:02 by ujchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);

void	add(int a, int b)
{
	int	result;

	result = a + b;
	ft_putnbr(result);
	write(1, "\n", 1);
}

void	sup(int a, int b)
{
	int	result;

	result = a - b;
	ft_putnbr(result);
	write(1, "\n", 1);
}

void	mul(int a, int b)
{
	int	result;

	result = a * b;
	ft_putnbr(result);
	write(1, "\n", 1);
}

void	div(int a, int b)
{
	int	result;

	if (b == 0)
	{
		write (1, "Stop : division by zero", 23);
		return ;
	}
	result = a / b;
	ft_putnbr(result);
	write(1, "\n", 1);
}

void	mod(int a, int b)
{
	int	result;

	if (b == 0)
	{
		write (1, "Stop : modulo by zero", 21);
		return ;
	}
	result = a % b;
	ft_putnbr(result);
	write(1, "\n", 1);
}
