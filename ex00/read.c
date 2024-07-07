/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:34:30 by fmixtur           #+#    #+#             */
/*   Updated: 2024/07/06 13:34:32 by fmixtur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

char	*get_txt(char *ptr);
char	*get_txt(char *ptr);
char	*ft_strstr(char *str, char *to_find);

int	get_file_size(void)
{
	int		fl;
	char	c;
	int		file_size;

	fl = open("./numbers.dict",O_RDWR);
	if (fl == -1)
	{
		printf("ERROR\n");
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

char	*get_txt(char *ptr)
{
	int	fl;

	fl = open("./numbers.dict",O_RDWR);
	if (fl == -1)
	{
		printf("ERROR\n");
		return (NULL);
	}
	ptr = malloc(sizeof(char) * get_file_size() + 1);
	read(fl, ptr, get_file_size() + 1);
	close(fl);
	return (ptr);
}

int	main(void)
{
	char	*ptr;
	char	*find;
	int		i;

	i = 0;
	ptr = get_txt(ptr);
	find = ft_strstr(ptr, "5");
	while (find[i] != '\n')
	{
		if ((find[i] >= 'a' && find[i] <= 'z') || (find[i] >= 'A' && find[i] <= 'Z'))
		{
			printf("%c",find[i]);
		}
		i++;
	}
	return (0);
}