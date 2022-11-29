/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:42:03 by rrebois           #+#    #+#             */
/*   Updated: 2022/11/29 17:29:43 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


char	*get_next_line(int fd)
{
	size_t			i;
	size_t			j;
	int				ret;
	static char	*temp;
	char		*buf;
	char		*str;

	buf = (char *)malloc(sizeof(*buf) * (BUF_SIZE + 1));
	if (temp == NULL)
		temp = (char *)malloc(sizeof(*temp) * (ft_strlen(buf) + 1));
	if (buf == NULL || temp == NULL)
		return (NULL);
	while (((ret = read(fd, buf, BUF_SIZE)) != 0) || temp != NULL)
	{
		buf[ret] = '\0';
		if (ret == -1)
			return (NULL);
		i = 0;
		temp = ft_strjoin(temp, buf);
//printf("temp join: %s\n", temp);
		if (temp == NULL)
			return (NULL);
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
				temp = &temp[j];
//printf("temp: %s\n", temp);
				return (str);
			}
			i++;
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
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	if (close(fd) == -1)
		return (1);
	return (0);
}
