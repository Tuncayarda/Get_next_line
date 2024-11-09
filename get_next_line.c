/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:47:37 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/09 23:37:44 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_del_line(char *buffer)
{
	char	*rtn;
	int		i;

	i = 0;
	rtn = NULL;
	while (buffer && buffer[i] && buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	i++;
	rtn = ft_substr_gnl(buffer, i, ft_strlen_gnl(buffer) - i);
	free(buffer);
	return (rtn);
}

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	line = ft_substr_gnl(buffer, 0, i + 1);
	if (!line)
		free(buffer);
	return (line);
}

char	*ft_fill_buff(char *buffer, int fd)
{
	char	*temp;
	int		rd;

	rd = 1;
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
	{
		free(buffer);
		return (NULL);
	}
	while (ft_strchr_gnl(buffer, '\n') == 0 && rd != 0)
	{
		rd = read(fd, temp, BUFFER_SIZE);
		if (rd == -1)
			return (free(buffer), free(temp), NULL);
		temp[rd] = '\0';
		buffer = ft_strjoin_gnl(buffer, temp);
		if (!buffer)
			return (free(temp), NULL);
	}
	free(temp);
	if (!buffer[0])
		return (free(buffer), NULL);
	return (buffer);
}

char	*ft_read_file(int fd, char *buffer)
{
	int		rd;
	char	*rtn;

	rtn = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!rtn)
		return (NULL);
	rd = read(fd, rtn, BUFFER_SIZE);
	if (rd == -1 || rd == 0)
	{
		free(rtn);
		free(buffer);
		return (NULL);
	}
	rtn[rd] = '\0';
	return (rtn);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	buffer = ft_fill_buff(buffer, fd);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_del_line(buffer);
	return (line);
}
