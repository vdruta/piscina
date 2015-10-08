unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dsize;
	int		i;

	while (dest[dsize])
		dsize++;
	while (src[i])
	{
		if (dsize < size - 1)
			dest[dsize] = src[i];
		i++;
		dsize++;
	}
	dest[dsize] = '\0';
	return (dsize);
}
