/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spowers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 23:28:47 by spowers           #+#    #+#             */
/*   Updated: 2020/07/17 09:40:13 by spowers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_index(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] != (char)c)
		return (-1);
	return (i);
}

int		get_line(char *str, char **line, int i)
{
	int		len;

	*line = ft_substr(str, 0, i);
	++i;
	len = ft_strlen(str + i) + 1;
	ft_memcpy(str, str + i, len);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*str = NULL;
	int				bwr;
	int				i;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
		return (-1);
	if (str && (((i = check_index(str, '\n')) != -1)))
		return (get_line(str, line, i));
	while (((bwr = read(fd, buff, BUFFER_SIZE)) > 0))
	{
		buff[bwr] = '\0';
		str = ft_join(str, buff);
		if (((i = check_index(str, '\n')) != -1))
			return (get_line(str, line, i));
	}
	if (str)
	{
		*line = ft_strdup(str);
		free(str);
		str = NULL;
		return (bwr);
	}
	*line = ft_strdup("");
	return (bwr);
}
int main (void)
{
char *line;
int fd;
int res;

fd = open("text.txt", O_RDONLY);
//fd = 42;
while ((res=get_next_line(fd, &line)))
{
printf(" res = %d, line is %s\n", res, line);
free(line);
}
printf("res = %d, line is %s\n", res, line);
free(line);
return(0);
}
