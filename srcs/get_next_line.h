/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:47:35 by tuaydin           #+#    #+#             */
/*   Updated: 2024/10/26 19:28:39 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_read_file(int fd);

char	*ft_strrchr(char *s, int c);

#endif
