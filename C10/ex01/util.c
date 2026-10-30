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
