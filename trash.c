/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:42:03 by rrebois           #+#    #+#             */
/*   Updated: 2022/11/29 12:41:46 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*get_next_line(int fd)
{
	size_t			i;
	size_t			j;
//	static char	*temp;
	char		*buf;
	char	*str;

	// if (!temp)
	// 	temp = NULL;
	buf = (char *)malloc(sizeof(*buf) * (BUF_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	if (read(fd, buf, BUF_SIZE) == -1)
		return (NULL);
	i = 0;
	while (buf[i] != '\n')
		i++;
	// if (i < ft_strlen(buf))
	// {
	// 	str = (char *)malloc(sizeof(*str) * (i + 2));
	// 	if (str == NULL)
	// 		return (NULL);
	// 	while (j <= i)
	// 	{
	// 		str[j] = buf[j];
	// 		j++;
	// 	}
	// 	str[j] = '\0';
	// 	// temp = (char *)malloc(sizeof(*str) * (ft_strlen(buf - i) + 1));
	// 	// while (j < ft_strlen(buf))
	// 	// {
	// 	// 	temp[j] = buf[j];
	// 	// 	j++;
	// 	// }
	// 	// temp[j] = '\0';
	// }
	if (buf[i] == '\n')
	{
		j = 0;
		str = (char *)malloc(sizeof(*str) * (i + 2));
		if (str == NULL)
			return (NULL);
		while (j <= i)
		{
			str[j] = buf[j];
			j++;
		}
		str[j] = '\0';
		return (str);
	}
	return (str);
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
