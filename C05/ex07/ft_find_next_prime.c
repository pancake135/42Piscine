/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujchoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 14:19:49 by ujchoi            #+#    #+#             */
/*   Updated: 2026/08/07 08:41:39 by ujchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 2;
	if (nb <= 1)
		return (0);
	while (i < nb)
	{
		if (nb % i == 0)
			cnt++;
		i++;
	}
	if (cnt > 0)
		return (0);
	return (i);
}

int	ft_find_next_prime(int nb)
{
	int	result;
	int	idx;

	idx = 1;
	result = nb;
	if (nb <= 2)
		return (2);
	if (ft_is_prime(nb))
		return (nb);
	while (idx)
	{
		if (result % 2 != 0)
		{
			while (!(ft_is_prime(result)))
				result += 2;
			return (result);
		}
		else
			result += 1;
	}
	return (1);
}
