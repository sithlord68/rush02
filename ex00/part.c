#include <unistd.h>
#include <stdlib.h>

char	*ft_transform(int i, char *str)
{
	int	res;
	char *number;
	char *cpy;
	int j;
	int	k;

	k = 0;
	res = i % 3;
	if (res == 1)
	{
		number = (char *)malloc(res * sizeof(char));
		cpy = (char *)malloc((i - res) * sizeof(char));
		j = 1;
		number[0] = str[0];
		while (str)
		{
			cpy[k] = str[j];
			k++;
			j++;
		}
		ft_transform(i - 1, cpy);
	}
	if (res == 2)
	{
		number = (char *)malloc(res * sizeof(char));
		cpy = (char *)malloc((i - res) * sizeof(char));
		j = 2;
		number[0] = str[0];
		number[1] = str[1];
		while (str)
		{
			cpy[k] = str[j];
			k++;
			j++;
		}
		ft_transform(i - 2, cpy);
	}
	if (res == 0)
	{
		number = (char *)malloc(3 * sizeof(char));
		cpy = (char *)malloc(3 * sizeof(char));
		j = 3;
		number[0] = str[0];
		number[1] = str[1];
		number[2] = str[2];
		while (str)
		{
			cpy[k] = str[j];
			k++;
			j++;
		}
		ft_transform(i - 3, cpy);
	}
	return (str);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] < 48 || argv[1][i] > 57)
			write(1, "Error/n", 6);
		i++;
	}
	ft_transform(i, *argv);
}