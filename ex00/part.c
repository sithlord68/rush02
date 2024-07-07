/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:30:50 by ktintim-          #+#    #+#             */
/*   Updated: 2024/07/07 23:11:37 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_part(int i, char *str, char *dict);
int	ft_read(char *str, int j, char *dict);

void	res_1(int i, char *str, int res, char *dict)
{
	int		j;
	int		k;
	char	number[2];
	char	*cpy;

	k = 0;
	cpy = (char *)malloc((i - res + 1) * sizeof(char));
	j = 1;
	number[0] = str[0];
	number[1] = '\0';
	while (str[j])
	{
		cpy[k] = str[j];
		k++;
		j++;
	}
	ft_read(number, i - 1, dict);
	ft_part(i - 1, cpy, dict);
}

void	res_2(int i, char *str, int res, char *dict)
{
	int		j;
	int		k;
	char	number[3];
	char	*cpy;

	k = 0;
	cpy = (char *)malloc((i - res + 1) * sizeof(char));
	j = 2;
	number[0] = str[0];
	number[1] = str[1];
	number[2] = '\0';
	while (str[j])
	{
		cpy[k] = str[j];
		k++;
		j++;
	}
	ft_read(number, i - 2, dict);
	ft_part(i - 2, cpy, dict);
}

void	res_0(int i, char *str, char *dict)
{
	int		j;
	int		k;
	char	number[4];
	char	*cpy;

	k = 0;
	cpy = (char *)malloc(4 * sizeof(char));
	j = 3;
	number[0] = str[0];
	number[1] = str[1];
	number[2] = str[2];
	number[3] = '\0';
	while (str[j])
	{
		cpy[k] = str[j];
		k++;
		j++;
	}
	ft_read(number, i - 3, dict);
	ft_part(i - 3, cpy, dict);
}

int	ft_part(int i, char *str, char *dict)
{
	int	res;

	res = i % 3;
	if (res == 1)
	{
		res_1(i, str, res, dict);
	}
	if (res == 2)
	{
		res_2(i, str, res, dict);
	}
	if (res == 0)
	{
		res_0(i, str, dict);
	}
	return (0);
}
