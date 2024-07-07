/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:00:06 by pjolidon          #+#    #+#             */
/*   Updated: 2024/07/07 15:43:23 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*match(char *dictfile);

char	*translate(char *totranslate, char *dictfile)
{
	char	*translate;

	translate = match(dictfile);
	(void) totranslate;
	return (translate);
}
