/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujchoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 14:22:23 by ujchoi            #+#    #+#             */
/*   Updated: 2026/08/06 14:22:25 by ujchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	culc(int a, int b)
{
	if (a - b < 0)
		return (b - a);
	return (a - b);
}

void	num_print(int *chess)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = chess[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	judge(int *chess, int row, int col)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (col == chess[i]
			|| culc(row, i) == culc(col, chess[i]))
			return (0);
		i++;
	}
	return (1);
}

void	queens(int *chess, int row, int *count)
{
	int	col;	

	col = 0;
	if (row == 10)
	{
		num_print(chess);
		(*count)++;
		return ;
	}
	while (col < 10)
	{
		if (judge(chess, row, col))
		{
			chess[row] = col;
			queens(chess, row + 1, count);
		}
		col++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	row;
	int	count;
	int	chess[10];

	count = 0;
	row = 0;
	queens(chess, row, &count);
	return (count);
}
