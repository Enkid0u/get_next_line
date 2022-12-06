/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:42:03 by rrebois           #+#    #+#             */
/*   Updated: 2022/12/06 17:24:48 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#define BUFFER_SIZE 1
static char	*ft_extract_line(char *temp, char *ptr)
{
	size_t	i;

	i = 0;
	if (temp == NULL)
		return (free(temp), NULL);
	while (temp[i] != '\0' && temp[i] != '\n')
		i++;
printf("%i\n", temp[i]);
	return (ptr);
}

// static char	*ft_free(char *temp, char *buf)
// {
// 	char	*s;

// 	s = ft_strjoin(temp, buf);
// 	free(temp);
// 	return (s);
// }

static char	*ft_read_file(int fd, char *temp)
{
	char	buf[BUFFER_SIZE + 1];
	int		ret;

	if (temp == NULL)
	{
		temp = (char *)malloc(sizeof(*temp) * 1);
		temp[0] = '\0';
	}
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		buf[ret] = '\0';
		temp = ft_strjoin(temp, buf);
		if (temp == NULL)
			return (NULL);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*ptr;

	ptr = NULL;
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = ft_read_file(fd, temp);
	if (temp == NULL)
		return (NULL);
	ptr = ft_extract_line(temp, ptr);
	return (ptr);
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
	printf("string: %s\n", get_next_line(fd));
	printf("string: %s\n", get_next_line(fd));
	// printf("string: %s\n", get_next_line(fd));
	// printf("string: %s\n", get_next_line(fd));
	// printf("string: %s\n", get_next_line(fd));
	// printf("string: %s\n", get_next_line(fd));

	if (close(fd) == -1)
		return (1);
	return (0);
}
