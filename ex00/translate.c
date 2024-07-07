/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:00:06 by pjolidon          #+#    #+#             */
/*   Updated: 2024/07/07 15:59:07 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*match(char *dictfile);

char	*translate(char *totranslate, char *dictfile)
{
	char	*translate;

	translate = match(dictfile);
	if (translate == NULL)
		return (NULL);
	(void) totranslate;
	return (translate);
}
