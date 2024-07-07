/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readdict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:37:53 by pjolidon          #+#    #+#             */
/*   Updated: 2024/07/07 16:51:27 by pjolidon         ###   ########.fr       */
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
void	ft_putnstr(char *str, int n);

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
	int		cnt;
	char	*temp;

	temp = malloc(sizeof(char) * filesize);
	cnt = read(file, temp, filesize);
	printf("retour: %d\n", cnt);
	statuschange = 'i';
	status = 'i';
	i = 0;
	ft_putnstr(temp, 20);
	while (i < filesize)
	{
		c = temp[i];;
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
	free (temp);
	return (readtable);
}

char	*getdict(char *dictfile)
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
	file = close(file);
	if (fsize < 1)
	{
		return (NULL);
	}
	readtable = malloc(sizeof(char) * (fsize + 1));
	file = open(dictfile, O_RDONLY, 0);
	readdictcontent(readtable, file, fsize);
	file = close(file);
	return (readtable);
}
