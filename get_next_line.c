/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:42:03 by rrebois           #+#    #+#             */
/*   Updated: 2022/11/25 20:05:26 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int 	ret;
	char	buf[BUF_SIZE + 1];
}

int	main()
{
	int	fd;

	fd = open("test", O_RONLY);
	if (fd == -1)
		return (1);
	get_next_line(fd);
	if (close(fd) == -1)
		return (1);
	return (0);
}
