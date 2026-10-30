/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujchoi <ujchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 12:40:11 by ujchoi            #+#    #+#             */
/*   Updated: 2026/08/19 17:02:53 by ujchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char **str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

int	ft_strcmp(char *a1, char *a2)
{
	int	idx;

	idx = 0;
	while (a1[idx] == a2[idx] && a1[idx] != '\0' && a2[idx] != '\0')
		idx++;
	return ((unsigned char)a1[idx] - (unsigned char)a2[idx]);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	int		len;
	char	*temp;

	i = 0;
	len = ft_strlen(tab);
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (tab[j + 1] != 0 && ft_strcmp(tab[j], tab[j + 1]) > 0)
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
