/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readdict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:37:53 by pjolidon          #+#    #+#             */
/*   Updated: 2024/07/07 12:47:02 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*match(char *dictfile)
{
	char	file;
	char	readstr[256]

	file = open(dictfile);
	readstr = read(file);
}

