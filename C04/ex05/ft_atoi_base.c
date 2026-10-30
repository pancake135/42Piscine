/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujchoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 10:52:13 by ujchoi            #+#    #+#             */
/*   Updated: 2026/08/05 10:52:17 by ujchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_check(char *base)
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

int	index_check(char c, char *base)
{
	int	idx;

	idx = 0;
	while (base[idx] != '\0')
	{
		if (base[idx] == c)
			return (idx);
		idx++;
	}
	return (-1);
}

int	f_idx(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	len;
	int	cnt;
	int	i;

	result = 0;
	cnt = 1;
	len = base_check(base);
	i = f_idx(str);
	if (len < 2)
		return (0);
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			cnt *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (index_check(str[i], base) == -1)
			return (result * cnt);
		result = result * len + index_check(str[i++], base);
	}
	return (result * cnt);
}
