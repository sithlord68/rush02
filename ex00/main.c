/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:21:37 by pjolidon          #+#    #+#             */
/*   Updated: 2024/07/07 23:13:51 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_part(int i, char *str, char *dict);
void	ft_putstr(char *str);
void	ft_putchar(char c);

int	findvalue(int argc)
{
	if (argc > 2)
		return (2);
	return (1);
}

char	*readvalue(int pos, char **argv)
{
	char	*value;
	int		len;
	int		i;

	len = 0;
	while (argv[pos][len])
		len++;
	value = malloc(sizeof(char) * (len + 1));
	if (value == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		value[i] = argv[pos][i];
		i++;
	}
	value[i] = '\0';
	return (value);
}

char	*setdict(char argc, char **argv)
{
	char	*dict;
	int		len;

	if (argc == 2)
	{
		dict = malloc(sizeof(char) * 15);
		dict = "./numbers.dict";
	}
	else
	{
		len = 0;
		while (argv[1][len])
			len++;
		dict = malloc(sizeof(char) * (len + 1));
		dict = argv[1];
	}
	return (dict);
}

int	main(int argc, char **argv)
{
	char	*totranslate;
	char	*dict;
	int		len;
	int		back;

	if (argc == 1)
		return (0);
	totranslate = readvalue (findvalue(argc), argv);
	dict = setdict(argc, argv);
	if (totranslate == NULL || dict == NULL)
		return (0);
	len = 0;
	while (totranslate[len])
	{
		if (totranslate[len] < '0' || totranslate[len] > '9')
		{
			write(1, "Error\n", 6);
			return (0);
		}
		len++;
	}
	back = ft_part(len, totranslate, dict);
	return (1);
}
