/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:08:34 by avaganay          #+#    #+#             */
/*   Updated: 2023/01/18 13:38:48 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_save(int fd, char *surplus)
{
	char	*buff;
	int		nbyte;

	nbyte = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	while (!ft_found_newline(surplus) && nbyte != 0)
	{
		nbyte = read(fd, buff, BUFFER_SIZE);
		if (nbyte == -1)
		{
			free (buff);
			free (surplus);
			return (NULL);
		}
		buff[nbyte] = '\0';
		surplus = ft_strjoin(surplus, buff);
	}
	free (buff);
	return (surplus);
}

char	*ft_extract_line(char *surplus, char *line)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (surplus[i] && surplus[i] != '\n')
		i++;
	if (surplus[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	len = ft_strlcpy(line, surplus, i + 1);
	return (line);
}

char	*ft_clean_surplus(char *surplus)
{
	char	*clean_surplus;
	size_t	i;
	size_t	surplus_len;
	size_t	j;

	i = 0;
	surplus_len = ft_strlengnl(surplus);
	while (surplus[i] && surplus[i] != '\n')
		i++;
	if (surplus[i] != '\0')
		i++;
	if (surplus == NULL)
		return (NULL);
	clean_surplus = malloc(sizeof(char) * (surplus_len - i) + 1);
	if (!clean_surplus)
		return (NULL);
	j = 0;
	while (surplus[i])
		clean_surplus[j++] = surplus[i++];
	clean_surplus[j] = '\0';
	free (surplus);
	return (clean_surplus);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*surplus;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	surplus = ft_read_save(fd, surplus);
	if (surplus == NULL)
		return (NULL);
	line = ft_extract_line(surplus, line);
	surplus = ft_clean_surplus(surplus);
	if (line[0] == '\0')
	{
		free (surplus);
		surplus = NULL;
		free (line);
		return (NULL);
	}
	return (line);
}
