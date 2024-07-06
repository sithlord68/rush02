/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:06:58 by pjolidon          #+#    #+#             */
/*   Updated: 2024/07/06 13:26:49 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#import <stdio.h>
#import <stdlib.h>

int	main(int argc, char **argv)
{
	int	i;

	printf("Args count : %d\n", argc);
	i = 0;
	while(i < argc)
	{
		printf("Param %d: \"%s\"\n", i,  argv[i]);
		i++;
	}
}
