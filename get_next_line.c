/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spowers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 23:28:47 by spowers           #+#    #+#             */
/*   Updated: 2020/07/18 23:40:15 by spowers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		ft_free(char **str)
{
	if (str != NULL && *str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

int			check_index(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] != (char)c)
		return (-1);
	return (i);
}

int			get_line(char *str, char **line, int i)
{
	int		len;

	if (!(*line = ft_substr(str, 0, i)))
		return (-1);
	++i;
	len = ft_strlen(str + i) + 1;
	ft_memcpy(str, str + i, len);
	return (1);
}

int			set_line(char **str, char **line, int bwr)
{
	if (*str)
	{
		if (!(*line = ft_strdup(*str)))
			return (-1);
		ft_free(str);
		return (bwr);
	}
	if (!(*line = ft_strdup("")))
		return (-1);
	return (bwr);
}

int			get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*str;
	int			bwr;
	int			i;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
		return (-1);
	if (str && (((i = check_index(str, '\n')) != -1)))
		return (get_line(str, line, i));
	while (((bwr = read(fd, buff, BUFFER_SIZE)) > 0))
	{
		buff[bwr] = '\0';
		if (!(str = ft_join(str, buff)))
			return (-1);
		if (((i = check_index(str, '\n')) != -1))
			return (get_line(str, line, i));
	}
	return (set_line(&str, line, bwr));
}
