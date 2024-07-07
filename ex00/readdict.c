/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readdict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:37:53 by pjolidon          #+#    #+#             */
/*   Updated: 2024/07/07 15:44:54 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	is_alpha(char c);

int	is_numeric(char c);

int	is_space(char c);

int	is_delim(char c, char delim);

int	is_cr(char c);

int	filesize(int file)
{
	int		len;
	int		goonread;
	char	*c;

	len = 0;
	goonread = 1;
	c = malloc(sizeof(char));
	while (goonread > 0)
	{
		goonread = read(file, c, 1);
		if (goonread > 0)
			len++;
	}
	free(c);
	return (len);
}

char	handlevalue(char *readtable, char c, char status, char statuschange)
{
	int	line;

	line = 0;
	while (readtable[line])
	{
		printf("lu: %s", &readtable[line]);
		line++;
	}
	if (line > 0)
		line--;
	if (status != statuschange)
	{
		if (statuschange == 'v')
		{
			readtable[line] += ':';
		}
		else
		{
			readtable[line] += '\0';
			line++;
		}
	}
	status = statuschange;
	readtable[line] += c;
	return (status);
}

char	*readdictcontent(char *readtable, int file, int filesize)
{
	int		i;
	char	c;
	int		statuschange;
	int		status;

	statuschange = 'i';
	status = 'i';
	i = 0;
	while (i < filesize)
	{
		c = read(file, &c, 1);
		if (is_delim(c, ':'))
			statuschange = 'v';
		else if (is_cr(c))
			statuschange = 'i';
		else if (is_space(c))
			statuschange = 'v';
		else
			status = handlevalue(readtable, c, status, statuschange);
		i++;
	}
	return (readtable);
}

char	*match(char *dictfile)
{
	int		file;
	int		fsize;
	char	*readtable;

	file = open(dictfile, O_RDONLY, 0);
	if (file < 1)
	{
		return (NULL);
	}
	fsize = filesize(file);
	if (fsize < 1)
	{
		return (NULL);
	}
	readtable = malloc(sizeof(char) * (fsize + 1));
	readdictcontent(readtable, file, fsize);
	file = close(file);
	return (readtable);
}
