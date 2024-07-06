/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:21:37 by pjolidon          #+#    #+#             */
/*   Updated: 2024/07/06 18:58:43 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	findvalue(int nb)
{
	if (nb > 2)
		return (2);
	return (1);
}

char	*readvalue(int pos, char **argv)
{
	char	*value;
	int		len;
	int		i;

	printf("position: %d\n", pos);
	len = 0;
	while (argv[pos][len])
		len++;
	i = 0;
	value = malloc(sizeof(char) * (len + 1));
	if (value == NULL)
		return (NULL);
	while (i < len)
		value[i++] = argv[pos][len];
	value[i] = '\0';
	printf("valeur lue:\"%s\"\n", value);
	return (value);
}

char	*setdict(char argc, char **argv)
{
	char	*dict;
	int		len;

	if (argc == 1)
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
	printf("valeur dict:\"%s\"\n", dict);
	return (dict);
}

void	parseparams(int nb, char **argv, char *params)
{
	int	pvalue;
	int	i;

	pvalue = 1;
	if (nb > 2)
		pvalue = 2;
	i = 0;
	while (argv[pvalue][i])
		i++;
}

int	main(int argc, char **argv)
{
	char	*totranslate;
	char	*dict;
	int		i;

	if (argc == 1)
		return (0);
	totranslate = readvalue (findvalue(argc), argv);
	dict = setdict(argc, argv);
	if (totranslate == NULL || dict == NULL)
		return (0);
}
