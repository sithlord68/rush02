/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:00:06 by pjolidon          #+#    #+#             */
/*   Updated: 2024/07/07 16:23:08 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*getdict(char *dictfile);

char	*match(char *dict, char *totranslate)
{
	(void) dict;
	return (totranslate);
}

char	*translate(char *totranslate, char *dictfile)
{
	char	*dict;
	char	*toput;

	dict = getdict(dictfile);
	if (dict == NULL)
		return (NULL);
	toput = match(dict, totranslate);
	return (toput);
}
