int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (argv[1] != '\0')
	{
		if (argv[1][i] < 48 || argv[1][i] > 57)
			write(1, "Error/n");
		i++;
	}
	
}