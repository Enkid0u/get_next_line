/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:42:03 by rrebois           #+#    #+#             */
/*   Updated: 2022/12/06 13:40:41 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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

static char	*ft_new_str(char *temp)
{
	size_t	i;
	char	*str;

	i = 0;
	// if (temp == NULL)
	// 	return (NULL);
	while (temp[i] != '\0' && temp[i] != '\n')
		i++;
	// if (temp[i] == '\0')
	// 	return (NULL);
	if (temp[i] == '\n')
		i++;
	str = (char *)malloc(sizeof(*str) * (ft_strlen(temp) - i + 1));
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = temp[i];
		i--;
	}
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
			return (NULL);
		buf[ret] = '\0';
		temp = ft_strjoin(temp, buf);
		if (!temp)
			return (NULL);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*ptr;

	if (temp != NULL)
		if (temp[0] == '\0')
			return (NULL);
	ptr = NULL;
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = ft_read_file(fd, temp);
	if (temp[0] == '\0')
		return (NULL);
	ptr = ft_line(temp, ptr);
	temp = ft_new_str(temp);
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
	printf("string: %s\n", get_next_line(fd));
	// printf("string: %s\n", get_next_line(fd));
	// printf("string: %s\n", get_next_line(fd));
	// printf("string: %s\n", get_next_line(fd));

	if (close(fd) == -1)
		return (1);
	return (0);
}
