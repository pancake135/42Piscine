/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujchoi <ujchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 15:57:48 by ujchoi            #+#    #+#             */
/*   Updated: 2026/08/13 18:30:45 by ujchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	base_check(char *base);
int	ft_atoi_base(char *str, char *base);

int	put_nbr_len(long nbr, int base_len)
{
	int	len;

	len = 0;
	if (nbr <= 0)
	{
		len++;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}

void	fill_str(long nb, char *base_to, char *str, int *idx)
{
	int	len_to;

	len_to = base_check(base_to);
	if (nb >= len_to)
		fill_str(nb / len_to, base_to, str, idx);
	str[(*idx)++] = base_to[nb % len_to];
}

int	intjudge(char *base_from, char *base_to)
{
	int		len_from;
	int		len_to;

	len_from = base_check(base_from);
	len_to = base_check(base_to);
	if (len_from < 2 || len_to < 2)
		return (1);
	return (0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	num;
	int		len_to;
	int		str_len;
	int		idx;
	char	*str;

	len_to = base_check(base_to);
	if (intjudge(base_from, base_to))
		return (NULL);
	num = (long)ft_atoi_base(nbr, base_from);
	str_len = put_nbr_len(num, len_to);
	str = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!str)
		return (NULL);
	idx = 0;
	if (num < 0)
	{
		str[idx++] = '-';
		num = -num;
	}
	fill_str(num, base_to, str, &idx);
	str[idx] = '\0';
	return (str);
}
