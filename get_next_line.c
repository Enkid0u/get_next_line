/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:42:03 by rrebois           #+#    #+#             */
/*   Updated: 2022/11/30 17:15:29 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*get_next_line_str(char *temp, char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (temp[i] != '\0')
	{
		j = 0;
		if (temp[i] == '\n')
		{
			str = (char *)malloc(sizeof(*str) * (i + 1));
			if (str == NULL)
				return (NULL);
			while (j <= i)
			{
				str[j] = temp[j];
				j++;
			}
			str[j] = '\0';
			return (str);
		}
		i++;
	}
	return (NULL);
}

static int	get_next_line_check(char *temp)
{
	size_t	i;

	i = 0;
	while (temp[i] != '\0')
	{
		if (temp[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	int			ret;
	static char	*temp;
	char		*buf;

	buf = (char *)malloc(sizeof(*buf) * (BUF_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	while ((ret = read(fd, buf, BUF_SIZE)) || temp[0] != '\0')
	{
		if (temp == NULL)
			temp = (char *)malloc(sizeof(*temp) * (ft_strlen(buf) + 1));
		if (ret == -1 || temp == NULL)
			return (NULL);
		buf[ret] = '\0';
		temp = ft_strjoin(temp, buf);
		if ((get_next_line_check(temp)) == 1)
		{
			buf = get_next_line_str(temp, buf);
			temp = &temp[ft_strlen(buf)];
			if (ret == 0 && temp[0] == '\0')
				free(temp);
			return (buf);
		}
	}
	return (NULL);
}

int	main()
{
	int		fd;

	fd = open("test", O_RDONLY);
	if (fd == -1)
		return (1);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	printf("string: %s", get_next_line(fd));
	printf("string: %s", get_next_line(fd));
	// printf("string: %s", get_next_line(fd));
	// printf("string: %s", get_next_line(fd));
	// printf("string: %s", get_next_line(fd));
	// printf("string: %s", get_next_line(fd));

	if (close(fd) == -1)
		return (1);
	return (0);
}
