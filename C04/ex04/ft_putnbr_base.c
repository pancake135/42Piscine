/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujchoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 10:55:32 by ujchoi            #+#    #+#             */
/*   Updated: 2026/08/05 10:55:34 by ujchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check(char *base)
{
	int	len;
	int	i;

	len = 0;
	while (base[len] != '\0')
	{
		if (base[len] == '+' || base[len] == '-'
			|| (base[len] >= 9 && base[len] <= 13) || base[len] == 32)
			return (0);
		i = len + 1;
		while (base[i])
		{
			if (base[i] == base[len])
				return (0);
			i++;
		}
		len++;
	}
	return (len);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	long	nb;

	nb = (long)nbr;
	len = ft_check(base);
	if (len < 2)
		return ;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= len)
		ft_putnbr_base((nb / len), base);
	write(1, &base[(nb % len)], 1);
}
