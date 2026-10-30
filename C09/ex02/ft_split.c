/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujchoi <ujchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 15:53:45 by ujchoi            #+#    #+#             */
/*   Updated: 2026/08/17 17:17:29 by ujchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	sep_check(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	word_count(char *str, char *charset)
{
	int	i;
	int	cnt;
	int	flag;

	flag = 1;
	cnt = 0;
	i = 0;
	while (str[i])
	{
		if (!sep_check(str[i], charset))
		{
			if (flag == 1)
				cnt++;
			flag = 0;
		}
		else
			flag = 1;
		i++;
	}
	return (cnt);
}

int	word_len(char *str, char *charset, int idx)
{
	int	len;

	len = 0;
	while (str[idx] && !sep_check(str[idx], charset))
	{
		len++;
		idx++;
	}
	return (len);
}

char	*mk_word_arr(char *str, char *charset, int idx)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	len = word_len(str, charset, idx);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		if (!sep_check(str[idx], charset))
		{
			word[i] = str[idx];
			i++;
		}
		idx++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		s_len;
	int		i;
	int		idx;

	idx = 0;
	i = 0;
	s_len = word_count(str, charset);
	arr = (char **)malloc(sizeof(char *) * (s_len + 1));
	if (!arr)
		return (NULL);
	arr[s_len] = NULL;
	while (i < s_len)
	{
		while (str[idx] && sep_check(str[idx], charset))
			idx++;
		arr[i] = mk_word_arr(str, charset, idx);
		idx += word_len(str, charset, idx);
		i++;
	}
	return (arr);
}
