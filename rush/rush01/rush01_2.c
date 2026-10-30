/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujchoi <ujchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 11:20:28 by juyelee           #+#    #+#             */
/*   Updated: 2026/10/30 16:33:58 by ujchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	base_len(char **grid)
{
	int	i;

	i = 0;
	while (grid[0][i] != '\0')
	{
		i++;
	}
	return (i);
}

int	joongbock_check(char **grid, int row, int col, char num)
{
	int	i;

	i = 0;
	while (i < base_len(grid))
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	one_col_check(char **grid, int row, int col, char *rules)
{
	int	max_bottom;
	int	max_top;
	int	top_count;
	int	bottom_count;

	top_count = 0;
	bottom_count = 0;
	max_top = 0;
	max_bottom = 0;
	while (row < base_len(grid))
	{
		if (grid[row][col] > max_top)
		{
			max_top = grid[row][col];
			top_count++;
		}
		if (grid[base_len(grid) - 1 - row][col] > max_bottom)
		{
			max_bottom = grid[base_len(grid) - 1 - row][col];
			bottom_count++;
		}
		row++;
	}
	return (top_count + '0' == rules[col]
		&& bottom_count + '0' == rules[base_len(grid) + col]);
}

int	col_check(char **grid, int row, int col, char *rules)
{
	while (col < base_len(grid))
	{
		if (!one_col_check(grid, row, col, rules))
		{
			return (0);
		}
		col++;
	}
	return (1);
}

int	row_check(char **grid, int row, int col, char *rules)
{
	int	max_right;
	int	max_left;
	int	l_count;
	int	r_count;

	l_count = 0;
	r_count = 0;
	max_left = 0;
	max_right = 0;
	while (col < base_len(grid))
	{
		if (grid[row][col] > max_left)
		{
			max_left = grid[row][col];
			l_count++;
		}
		if (grid[row][base_len(grid) - 1 - col] > max_right)
		{
			max_right = grid[row][base_len(grid) - 1 - col];
			r_count++;
		}
		col++;
	}
	return (l_count + '0' == rules[(base_len(grid) * 2) + row]
		&& r_count + '0' == rules[(3 * base_len(grid)) + row]);
}