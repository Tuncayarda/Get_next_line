/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:57:31 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/09 23:30:17 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen_gnlb(char *str);
char	*ft_substr_gnlb(char *s, unsigned int start, size_t len);
char	*ft_strchr_gnlb(char *s, int c);
char	*ft_strdup_gnlb(char *s1);
char	*ft_strjoin_gnlb(char *s1, char *s2);
char	*ft_strrchr_gnlb(char *s, int c);

#endif
