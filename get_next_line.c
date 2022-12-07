/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roro <roro@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:42:03 by rrebois           #+#    #+#             */
/*   Updated: 2022/12/07 14:40:05 by roro             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#define BUFFER_SIZE 1
static char	*ft_extract_line(char *temp)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (temp == NULL || temp[i] == '\0')
		return (NULL);
	while (temp[i] != '\0' && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		i++;
	ptr = (char *)malloc(sizeof(*ptr) * (i + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (temp[i] != '\0' && temp[i] != '\n')
	{
		ptr[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
	{
		ptr[i] = temp[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static char *ft_new_str(char *temp)
{
	size_t	i;
	size_t	j;
	char	*new_temp;

	i = 0;
	j = 0;
	while (temp[i] != '\0' && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		i++;
	if (temp[i] == '\0')
		return (free(temp), NULL);
	new_temp = (char *)malloc(sizeof(*new_temp) * (ft_strlen(temp) - i + 1));
	while (temp[i] != '\0')
	{
		new_temp[j] = temp[i];
		i++;
		j++;
	}
	return (free(temp), new_temp);
}

static char	*ft_free_temp(char *temp, char *buf)
{
	char	*s;

	s = ft_strjoin(temp, buf);
	free(temp);
	return (s);
}

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
		temp = ft_free_temp(temp, buf);
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
	ptr = ft_extract_line(temp);
	temp = ft_new_str(temp);
	return (ptr);
}
/*
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
}*/
