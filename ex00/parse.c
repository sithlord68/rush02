/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 22:52:29 by ktintim-          #+#    #+#             */
/*   Updated: 2024/07/07 23:16:17 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	parse(char *ptr, char *str, int i);
void	print_text(char *ptr, char *nb);

void	i_3(char *ptr, char *str, int i)
{
	char	c[2];

	c[1] = '\0';
	c[0] = str[0];
	print_text(ptr, c);
	write(1, " ", 1);
	print_text(ptr, "100");
	write(1, " ", 1);
	parse(ptr, str + 1, --i);
}

void	i_2(char *ptr, char *str, int i)
{
	char	c[2];

	c[1] = '\0';
	if (str[0] == '1')
	{
		print_text(ptr, str);
	}
	else
	{	
		c[0] = str[1];
		str[1] = '0';
		print_text(ptr, str);
		write(1, " ", 1);
		parse(ptr, c, --i);
	}
}

void	parse(char *ptr, char *str, int i)
{
	if (str[0] == '0' && str[1] == '\0')
		print_text(ptr, "0");
	while (*str == '0')
		str++;
	if (i == 3)
	{
		i_3(ptr, str, i);
	}
	else if (i == 2)
	{
		i_2(ptr, str, i);
	}
	else if (i == 1 && str[0] != '0')
	{
		print_text(ptr, str);
	}
}
