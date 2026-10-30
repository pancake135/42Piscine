#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

int	ft_strcmp(char *a1, char *a2);
int	ft_strlen(char *str);
int	is_digit(char *str);
int jubge_c(char **argv);
int	jubgestdin(char **argv, int i);

void	errorprint(char *msg, char **argv, int i)
{
	int		len;

	len = ft_strlen(argv[0]);
	write(2, argv[0], len);
	write(2, ": ", 2);
	write(2, "cannot open", 11);
	if (argv[i])
	{
		len = ft_strlen(argv[i]);
		write(2, argv[i], len);
	}
	write(2, "for reading", 11);
	write(2, ": ", 2);
	len = ft_strlen(msg);
	write(2, msg, len);
	write(2, "\n", 1);
}

void	ft_stdin(char **argv, int i)
{
	int		bytes;
	char	buf[1024];

	if (argv[i + 1])
		write(1, "==> standard input <==\n", 23);
	while ((bytes = read(0, buf, 1024)) > 0)
		write(1, buf, bytes);
	if (bytes < 0)
		errorprint(strerror(errno), argv, i);
}

void	readall(char **argv, int i)
{
	int	fd;
	int	bytes;
	char buf[1024];

	if (jubgestdin(argv, 0))
		return;
	if (argv[i + 1])
	{
		write(1, "==> ", 4);
		write(1, argv[i], ft_strlen(argv[i]));
		write(1, " <==\n", 6);
	}
	fd = open(argv[i], O_RDONLY);
	if (fd < 0)
	{
		errorprint(strerror(errno), argv, i);
		return ;
	}
	while ((bytes = read(fd, buf, 1024)) > 0)
		write(1, buf, bytes);
	if (bytes < 0)
		errorprint(strerror(errno), argv, i);
	close(fd);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 3;
	if (!jubge_c(argv))
	{
		errorprint(strerror(errno), argv, 1);
		return (0);
	}
	if (jubge_c(argv) == 2)
	{
		if (!is_digit(argv[2]))
		{
			errorprint(strerror(errno), argv, 2);
			return (0);
		}
	}
	while (i < argc)
	{
		readall(argv, i);
		i++;
	}
	return (0);
}
