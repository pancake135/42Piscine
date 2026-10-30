/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujchoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 11:00:18 by ujchoi            #+#    #+#             */
/*   Updated: 2026/08/03 17:37:17 by ujchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_tr_memory(unsigned long long c)
{
	int		i;
	char	header[16];
	char	*hexa;

	hexa = "0123456789abcdef";
	i = 15;
	while (i >= 0)
	{
		header[i] = hexa[c % 16];
		c = c / 16;
		i--;
	}
	write(1, header, 16);
	write(1, ": ", 2);
}

void	ft_tr_str(char c)
{
	char	*hexa;
	unsigned char k;

	k = (unsigned char)c;
	hexa = "0123456789abcdef";
	write(1, &hexa[k / 16], 1);
	write(1, &hexa[k % 16], 1);
}

void	ft_2nd(unsigned int idx, unsigned int size, char *str)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < 16)
	{
		j = idx + i;
		if (j < size)
		{
			ft_tr_str(str[j]);
			if (j + 1 < size)
			{
				ft_tr_str(str[j + 1]);
			}
			else
			{
				write(1, "  ", 2);
			}
			write(1, " ", 1);
		}
		else
			write(1, "     ", 5);
		i += 2;
	}
}

void	ft_3rd(unsigned int idx, unsigned int size, char *str)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < 16)
	{
		j = idx + i;
		if (j < size)
		{
			if ((!(str[j] >= 32 && str[j] <= 126)) && str[j])
				write(1, ".", 1);
			else if (str[j] == '\0')
				write(1, ".", 1);
			else
				write(1, &str[j], 1);
		}
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int		idx;
	unsigned long long	c;
	char				*str;

	str = (char *)addr;
	c = (unsigned long long)addr;
	if (size == 0)
		return (addr);
	idx = 0;
	while (idx < size)
	{
		ft_tr_memory(c++);
		ft_2nd(idx, size, str);
		ft_3rd(idx, size, str);
		write(1, "\n", 1);
		idx += 16;
	}
	return (addr);
}
