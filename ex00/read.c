/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:34:30 by fmixtur           #+#    #+#             */
/*   Updated: 2024/07/07 23:14:51 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

char	*get_txt(char *ptr, char *dict);
char	*ft_strstr(char *str, char *to_find);
void	print_text(char *ptr, char *nb);
void	parse(char *ptr, char *str, int i);

int	get_file_size(void)
{
	int		fl;
	char	c;
	int		file_size;

	fl = open("./numbers.dict", O_RDWR);
	if (fl == -1)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	file_size = 0;
	while ((read(fl, &c, 1)) > 0)
		file_size++;
	close(fl);
	return (file_size);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	char	*needle;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		if (str[i] == to_find[j])
		{
			needle = &str[i];
			while (str[i] == to_find[j])
			{
				i++;
				j++;
				if (to_find[j] == '\0')
					return (needle);
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}

char	*get_txt(char *ptr, char *dict)
{
	int	fl;

	fl = open(dict, O_RDWR);
	if (fl == -1)
	{
		write(1, "ERROR\n", 6);
		return (NULL);
	}
	ptr = malloc(sizeof(char) * get_file_size() + 1);
	read(fl, ptr, get_file_size() + 1);
	close(fl);
	return (ptr);
}

void	print_text(char *ptr, char *nb)
{
	char	*find;
	int		i;

	i = 0;
	find = ft_strstr(ptr, nb);
	while (find[i] != '\n')
	{
		if ((find[i] >= 'a' && find[i] <= 'z')
			|| (find[i] >= 'A' && find[i] <= 'Z'))
		{
			write(1, &find[i], 1);
		}
		i++;
	}
}

int	ft_read(char *str, int j, char *dict)
{
	char	*ptr;
	int		i;
	int		len;
	char	*zeros;

	len = 0;
	while (str[len])
		len++;
	i = 0;
	zeros = malloc(sizeof(char) * j);
	while (0 < j--)
		zeros[i++] = '0';
	ptr = NULL;
	ptr = get_txt(ptr, dict);
	parse(ptr, str, len);
	write(1, " ", 1);
	if (zeros[1] != '\0')
		print_text(ptr, zeros);
	write(1, " ", 1);
	free(ptr);
	return (0);
}
