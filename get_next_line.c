/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:47:37 by tuaydin           #+#    #+#             */
/*   Updated: 2024/10/25 14:27:39 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*ft_del_line(char *buffer)
{
	char	*rtn;
	int	i;

	i = 0;
	rtn = NULL;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] != '\0')
		rtn = ft_substr(buffer, i + 1, ft_strlen(buffer + i + 1));
	return (rtn);
}

char	*ft_get_line(char *buffer, int fd)
{
	int		i;
	char	*temp;
	int		rd;
	
	i = 0;
	rd = BUFFER_SIZE;
	while (ft_strchr(buffer, '\n') == 0 && rd == BUFFER_SIZE)
	{
		temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		rd = read(fd, temp, BUFFER_SIZE);
		temp[rd] = '\0';
		buffer = ft_strjoin(buffer, temp);
		free(temp);
	}
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	temp = ft_substr(buffer, 0, i + 1);
	free(buffer);
	return (temp);
}

char	*ft_read_file(int fd)
{
	int	rd;
	char	*rtn;

	rtn = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	rd = read(fd, rtn, BUFFER_SIZE);
	if (rd == -1 || rd == 0)
	{
		free(rtn);
		return (NULL);
	}
	rtn[rd] = '\0';
	return (rtn);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0)
		return (NULL);
	if (!buffer)
		buffer = ft_read_file(fd);
	if(!buffer)
		return (NULL);
	line = ft_get_line(buffer, fd);
	if (!line)
		return (NULL);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	buffer = ft_del_line(buffer);
	return (line);
}

/* int main()
{
	int fd;
	char *p;

	fd = open("files/43_with_nl", O_RDWR);
	printf("fd:%d\n",fd);

	p = get_next_line(fd);
	printf(" 1: %s", p);
	free(p);

	p = get_next_line(fd);
	printf(" 2: %s", p);
	free(p);

	p = get_next_line(fd);
	printf(" 3: %s", p);
	free(p);
	
} */
/* void leaks_check() __attribute__((destructor));
void leaks_check() {
    system("leaks a.out");
} */