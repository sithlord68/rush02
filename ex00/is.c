/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:23:26 by pjolidon          #+#    #+#             */
/*   Updated: 2024/07/07 15:41:55 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alpha(char c)
{
	if (c < 'A' || (c > 'Z' && c < 'a') || c > 'z')
		return (0);
	return (1);
}

int	is_numeric(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	is_space(char c)
{
	if (c == ' ')
		return (1);
	if (c >= 9 && c <= 13)
		return (1);
	return (0);
}

int	is_delim(char c, char delim)
{
	if (c == delim)
		return (1);
	return (0);
}

int	is_cr(char c)
{
	if (c == '\n')
		return (1);
	return (0);
}
