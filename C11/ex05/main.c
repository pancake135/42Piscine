/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujchoi <ujchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 12:36:03 by ujchoi            #+#    #+#             */
/*   Updated: 2026/08/19 22:21:36 by ujchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	add(int a, int b);
void	sup(int a, int b);
void	mul(int a, int b);
void	div(int a, int b);
void	mod(int a, int b);

int	ft_strcmp(char *a1, char *a2)
{
	int	idx;

	idx = 0;
	while (a1[idx] == a2[idx] && a1[idx] != '\0' && a2[idx] != '\0')
		idx++;
	return ((unsigned char)a1[idx] - (unsigned char)a2[idx]);
}

int	ft_atoi(char *str)
{
	int	i;
	int	cnt;
	int	result;

	i = 0;
	cnt = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			cnt *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * cnt);
}

void	ft_putnbr(int nb)
{
	long	n;
	char	c;

	n = nb;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

void	eval(int a, int b, void (*f)(int, int))
{
	f(a, b);
}

int	main(int argc, char **argv)
{
	void	(*f[5])(int, int);

	if (argc != 4)
		return (0);
	(void)argc;
	f[0] = &add;
	f[1] = &sup;
	f[2] = &mul;
	f[3] = &div;
	f[4] = &mod;
	if (ft_strcmp(argv[2], "+") == 0)
		eval(ft_atoi(argv[1]), ft_atoi(argv[3]), f[0]);
	else if (ft_strcmp(argv[2], "-") == 0)
		eval(ft_atoi(argv[1]), ft_atoi(argv[3]), f[1]);
	else if (ft_strcmp(argv[2], "*") == 0)
		eval(ft_atoi(argv[1]), ft_atoi(argv[3]), f[2]);
	else if (ft_strcmp(argv[2], "/") == 0)
		eval(ft_atoi(argv[1]), ft_atoi(argv[3]), f[3]);
	else if (ft_strcmp(argv[2], "%") == 0)
		eval(ft_atoi(argv[1]), ft_atoi(argv[3]), f[4]);
	else
		write(1, "0\n", 2);
	return (0);
}
