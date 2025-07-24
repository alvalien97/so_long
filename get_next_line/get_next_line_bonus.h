/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:14:34 by alvalien          #+#    #+#             */
/*   Updated: 2024/10/17 17:14:44 by alvalien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_next(char *buffer);
char	*ft_line(char *buffer);
char	*ft_free_join(char *gnl_buf, char *buf);
char	*read_file(int fd, char *gnl_buf);
char	*ft_strdup(const char *s1);
char	*read_and_append(int fd, char *gnl_buf, char *buffer);

#endif
