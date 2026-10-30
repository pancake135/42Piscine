/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujchoi <ujchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 11:12:06 by juyelee           #+#    #+#             */
/*   Updated: 2026/10/30 16:33:51 by ujchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		joongbock_check(char **grid, int row, int col, char num);
int		one_col_check(char **grid, int row, int col, char *rules);
int		col_check(char **grid, int row, int col, char *rules);
int		row_check(char **grid, int row, int col, char *rules);
int		base_len(char **grid);
int		str_count(char *str);
void	mk_rules_arr(char *str, char *rules, int len);

void	print_grid(char **grid, int base)
{
	int	i;
	int	j;

	i = 0;
	while (i < base)
	{
		j = 0;
		while (j < base)
		{
			write(1, &grid[i][j], 1);
			if (j != base - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	num_push(char **grid, int idx, int base, char *rules)
{
	int	num;

	if (idx == base * base)
	{
		if (col_check(grid, 0, 0, rules))
		{
			print_grid(grid, base);
			return (1);
		}
		return (0);
	}
	num = 0;
	while (++num <= base)
	{
		if (joongbock_check(grid, idx / base, idx % base, num + '0'))
		{
			grid[idx / base][idx % base] = num + '0';
			if (idx % base != base - 1 || row_check(grid, idx / base, 0, rules))
				if (num_push(grid, idx + 1, base, rules))
					return (1);
			grid[idx / base][idx % base] = 0;
		}
	}
	return (0);
}

void	free_all(char **grid, char *rules, int j)
{
	int	i;

	if (rules)
		free (rules);
	if (grid)
	{
		i = 0;
		while (i < j)
		{
			if (grid[i])
				free(grid[i]);
			i++;
		}
		free(grid);
	}
}

char	**mk_grid(char *rules, int len, int *error)
{
	char	**grid;
	int		i;

	i = 0;
	grid = (char **)malloc(sizeof(char *) * len / 4);
	if (!grid)
	{
		free(rules);
		*error = 1;
	}
	while (i < len / 4)
	{
		grid[i] = (char *)malloc(sizeof(char) * len / 4);
		if (!grid[i])
		{
			free_all(grid, rules, i);
			*error = 1;
		}
		i++;
	}
	return (grid);
}

int	main(int argc, char **argv)
{
	char	**grid;
	char	*rules;
	int		len;
	int		error;

	error = 0;
	len = 0;
	len = str_count(argv[1]);
	rules = (char *)malloc(sizeof(char) * len);
	if ((len % 4 != 0) || (argc != 2) || !rules)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	mk_rules_arr(argv[1], rules, len);
	grid = mk_grid(rules, len, &error);
	if (!num_push(grid, 0, len / 4, rules))
		error = 1;
	free_all(grid, rules, len / 4);
	if (error)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}