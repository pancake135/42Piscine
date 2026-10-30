#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

void	ft_stdin(char **argv, int i);
void	errorprint(char *msg, char **argv, int i);

int	ft_strcmp(char *a1, char *a2)
{
	int	idx;

	idx = 0;
	while (a1[idx] == a2[idx] && a1[idx] != '\0' && a2[idx] != '\0')
		idx++;
	return ((unsigned char)a1[idx] - (unsigned char)a2[idx]);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	}
	return (1);
}

int jubge_c(char **argv)
{
	int	i;
	int	cnt;

	cnt = 2;
	i = 2;
	if(argv[1][0] == '-' && argv[1][1] == 'c')
	{
		if (argv[1][2] == '\0')
			return (2);
		while (argv[1] && (argv[1][i] >= '0' && argv[1][i] <= '9'))
		{
			cnt++;
			i++;
		}
		if (cnt == i)
			return (1);
	}
	return (0);
}

int	jubgestdin(char **argv, int i)
{
	if (ft_strcmp(argv[3],"-") == 0 || (ft_strcmp(argv[3], "--") && argv[4] == 0))
	{
		ft_stdin(argv, i);
		return (1);
	}
	else if ((ft_strcmp(argv[3], "--") == 0 && argv[4] != 0)
		|| ft_strcmp(argv[3], "--") || ft_strcmp(argv[3], "-"))
	{
		errorprint(strerror(errno), argv, i);
		return (1);
	}
	return (0);
}
