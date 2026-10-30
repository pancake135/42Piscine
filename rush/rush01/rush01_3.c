/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujchoi <ujchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 11:16:54 by juyelee           #+#    #+#             */
/*   Updated: 2026/10/30 16:34:05 by ujchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_count(char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '9')
		{
			len++;
			i++;
		}
		else if ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			i++;
		else
			return (-1);
	}
	return (len);
}

void	mk_rules_arr(char *str, char *rules)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '9')
		{
			rules[j] = str[i];
			i++;
			j++;
		}
		else if ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			i++;
	}
}