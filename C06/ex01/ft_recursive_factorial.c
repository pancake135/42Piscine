/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujchoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 14:14:43 by ujchoi            #+#    #+#             */
/*   Updated: 2026/08/06 16:26:23 by ujchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	result;

	result = nb;
	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	if (nb > 0)
	{
		result *= ft_recursive_factorial(nb - 1);
	}
	return (result);
}
