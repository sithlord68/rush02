/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjolidon <pjolidon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:34:30 by fmixtur           #+#    #+#             */
/*   Updated: 2024/07/07 22:21:23 by pjolidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

char	*get_txt(char *ptr);
char	*get_txt(char *ptr);
char	*ft_strstr(char *str, char *to_find);
void	print_text(char *ptr, char *nb);

int	get_file_size(void)
{
	int		fl;
	char	c;
	int		file_size;

	fl = open("./numbers.dict",O_RDWR);
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

char	*get_txt(char *ptr)
{
	int	fl;

	fl = open("./numbers.dict",O_RDWR);
	if (fl == -1)
	{
		write(1,"ERROR\n",6);
		return (NULL);
	}
	ptr = malloc(sizeof(char) * get_file_size() + 1);
	read(fl, ptr, get_file_size() + 1);
	close(fl);
	return (ptr);
}

void	parse(char *ptr, char *str, int i)
{
	char	c[2];

	c[1] = '\0';
	if (str[0] == '0' && str[1] == '\0')
		print_text(ptr, "0");
	while (*str =='0')
		str++;
	if (i == 3 )
	{
		c[0] = str[0];
		print_text(ptr, c);
		write(1, " ", 1);
		print_text(ptr, "100");
		write(1, " ", 1);
		parse(ptr, str + 1, --i);
	}
	else if (i == 2 )
	{
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
	else if (i == 1 && str[0] != '0')
	{
		print_text(ptr, str);
	}
}

void	print_text(char *ptr, char *nb)
{
	char	*find;
	int		i;

	i = 0;
	find = ft_strstr(ptr, nb);
	while (find[i] != '\n')
	{
		if ((find[i] >= 'a' && find[i] <= 'z') || (find[i] >= 'A' && find[i] <= 'Z'))
		{
			write(1,&find[i],1);
		}
		i++;
	}
}

int	ft_read(char *str, int j)
{
	char	*ptr;
	int		i;
	int		len;

	len = 0;
	while (str[len])
		len++;
	i = 0;
	ptr = get_txt(ptr);
	parse(ptr, str, len);
	return (0);
}
