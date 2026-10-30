/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujchoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 13:22:03 by ujchoi            #+#    #+#             */
/*   Updated: 2026/08/02 13:22:29 by ujchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *a1, char *a2)
{
	int	idx;

	idx = 0;
	while (a1[idx] == a2[idx] && a1[idx] != '\0' && a2[idx] != '\0')
		idx++;
	return ((unsigned char)a1[idx] - (unsigned char)a2[idx]);
}
