/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:30:50 by ktintim-          #+#    #+#             */
/*   Updated: 2024/07/06 18:30:54 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	res_1(int i, char *str, int res)
{
	int		j;
	int		k;
	char	*number;
	char	*cpy;

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
	ft_part(i - 1, cpy);
}

void	res_2(int i, char *str, int res)
{
	int		j;
	int		k;
	char	*number;
	char	*cpy;

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
	ft_part(i - 2, cpy);
}

void	res_0(int i, char *str)
{
	int		j;
	int		k;
	char	*number;
	char	*cpy;

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
	ft_part(i - 3, cpy);
}

char	*ft_part(int i, char *str)
{
	int	res;

	res = i % 3;
	if (res == 1)
	{
		res_1(i, str, res);
	}
	if (res == 2)
	{
		res_2(i, str, res);
	}
	if (res == 0)
	{
		res_0(i, str);
	}
	return (str);
}
/*
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
	ft_part(i, *argv);
}
*/