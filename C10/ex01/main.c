#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int	ft_strcmp(char *a1, char *a2);
int	ft_strlen(char *str);

void	errorprint(char *msg, char **argv, int i)
{
	int		len;

	len = ft_strlen(argv[0]);
	write(2, argv[0], len);
	write(2, ": ", 2);
	if (argv[i])
	{
		len = ft_strlen(argv[i]);
		write(2, argv[i], len);
		write(2, ": ", 2);
	}
	len = ft_strlen(msg);
	write(2, msg, len);
	write(2, "\n", 1);
}

int	ft_stdin(char **argv, int i)
{
	int		bytes;
	char	buf[30000];

	while ((bytes = read(0, buf, 30000)) > 0)
	{
		write(1, buf, bytes);
		return (0);
	}
	if (bytes < 0)
	{
		errorprint(strerror(errno), argv, i);
		return (1);
	}
}

int readall(char **argv, int i)
{
    int bytes;
    int fd;
    char buf[30000];

    fd = open(argv[i], O_RDONLY);
    if (fd < 0)
    {
        errorprint(strerror(errno), argv, i);
        return (1);
    }
    bytes = read(fd, buf, 30000);
    while (bytes > 0)
    {
        write(1, buf, bytes);
        bytes = read(fd, buf, 30000);
    }
    
    if (bytes < 0)
    {
        errorprint(strerror(errno), argv, i);
        close(fd);
        return (1);
    }
    close(fd);
    return (0);
}

int main(int argc, char **argv)
{
    int i;
    int exit_status;

    exit_status = 0;
    i = 1;
    while (i < argc)
    {
        if (ft_strcmp(argv[i], "-") == 0)
        {
            if (ft_stdin(argv, i) != 0)
                exit_status = 1;
        }
        else
        {
            if (readall(argv, i) != 0)
                exit_status = 1;
        }
        i++;
    }
    return (exit_status);
}
