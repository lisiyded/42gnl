/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spowers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 23:26:34 by spowers           #+#    #+#             */
/*   Updated: 2020/07/17 09:25:58 by spowers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

int			get_next_line(int fd, char **line);
char		*ft_substr(char const *s, int start, int len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_join(char *s1, char *s2);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);

#endif
