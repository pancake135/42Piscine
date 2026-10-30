/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujchoi <ujchoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:09:45 by ujchoi            #+#    #+#             */
/*   Updated: 2026/08/20 16:55:46 by ujchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0 || i < 1024)
	{
		i++;
	}
	return (i);
}

void	read_all(int fd)
{
	char	buf[1024];
	int		bytes;

	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buf, 1024);
		write(1, buf, bytes);
	}
	if (bytes == -1)
		write(2, "Cannot read file.\n", 18);
	close(fd);
}

int	main(int argc, char **argv)
{
	int	fd;

	fd = 0;
	if (argc < 2)
	{
		write(2, "File name missing.\n", 20);
		return (0);
	}
	else if (argc > 2)
	{
		write(2, "Too many arguments.\n", 21);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	read_all(fd);
	return (0);
}
