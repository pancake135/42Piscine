/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujchoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 13:22:03 by ujchoi            #+#    #+#             */
/*   Updated: 2026/08/03 17:09:45 by ujchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(char *a1, char *a2, unsigned int n)
{
	unsigned int	idx;

	idx = 0;
	if (n == 0)
		return (0);
	while (idx < n && a1[idx] != '\0' && a2[idx] != '\0' && a1[idx] == a2[idx])
		idx++;
	if (idx == n)
		return (0);
	return ((unsigned char)a1[idx] - (unsigned char)a2[idx]);
}
