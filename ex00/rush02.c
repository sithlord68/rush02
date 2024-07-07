/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:21:37 by pjolidon          #+#    #+#             */
/*   Updated: 2024/07/07 11:56:58 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*translate(char *totranslate, char *dict);
void	ft_putstr(char *str);

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
	char	*toput;
	int		i;

	if (argc == 1)
		return (0);
	totranslate = readvalue (findvalue(argc), argv);
	dict = setdict(argc, argv);
printf("totranslate: \"%s\"\n", totranslate);
printf("dict: \"%s\"\n", dict);
	if (totranslate == NULL || dict == NULL)
		return (0);
	toput = translate(totranslate, dict);
	ft_putstr(toput);
//	free(totranslate);
//	free(dict);
}
