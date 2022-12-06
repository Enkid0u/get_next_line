/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trashy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:42:03 by rrebois           #+#    #+#             */
/*   Updated: 2022/12/06 15:53:00 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
//#define BUFFER_SIZE 1
static char	*ft_line(char *temp, char *ptr)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (temp[i] != '\0' && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		i++;
	ptr = (char *)malloc(sizeof(*ptr) * (i + 1));
	if (ptr == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		ptr[j] = temp[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

static char	*ft_join(char *temp, char *buf)
{
	char	*str;

	str = ft_strjoin(temp, buf);
	free(temp);
	return (str);
}

static char	*ft_read_file(int fd, char *temp)
{
	char	buf[BUFFER_SIZE + 1];
	int		ret;

	ret = 1;
	if (temp == NULL)
	{
		temp = (char *)malloc(sizeof(*temp) * 1);
		temp[0] = '\0';
	}
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (free(temp), NULL);
		buf[ret] = '\0';
		temp = ft_join(temp, buf);
		if (temp == NULL)
			return (NULL);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*ptr;

	// if (temp != NULL)
	// 	if (temp[0] == '\0')
	// 		return (NULL);
	ptr = NULL;
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = ft_read_file(fd, temp);
	if (temp == NULL)
		return (NULL);
	// if (temp == NULL)
	// 	write(1, "(null)", 6);
	ptr = ft_line(temp, ptr);
	size_t	i;

	i = 0;
	while (temp[i] != '\0' && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		i++;
	temp = &temp[i];
	return (ptr);
}

// int	main()
// {
// 	int		fd;

// 	fd = open("test", O_RDONLY);
// 	if (fd == -1)
// 		return (1);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	printf("string: %s\n", get_next_line(fd));
// 	printf("string: %s\n", get_next_line(fd));
// 	// printf("string: %s\n", get_next_line(fd));
// 	// printf("string: %s\n", get_next_line(fd));
// 	// printf("string: %s\n", get_next_line(fd));
// 	// printf("string: %s\n", get_next_line(fd));

// 	if (close(fd) == -1)
// 		return (1);
// 	return (0);
// }
