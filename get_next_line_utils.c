/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:21:51 by aid-bray          #+#    #+#             */
/*   Updated: 2024/11/16 17:37:45 by aid-bray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	is_line(char *save_line)
{
	size_t	i;

	i = 0;
	while (save_line[i])
		if (save_line[i++] == '\n')
			return (1);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	tab = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!tab)
		return (NULL);
	while (s1 && s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2 && s2[j])
	{
		tab[i] = s2[j];
		i++;
		j++;
	}
	tab[i] = '\0';
	s2[0] = '\0';
	return (tab);
}

char	*lin_to_return(char *save_line, char *buffer)
{
	char	*line;
	size_t	len;
	size_t	i;

	len = 0;
	while (save_line[len] != '\n')
		len++;
	i = ++len;
	line = malloc (len + 1);
	if (!line)
		return (NULL);
	line[len] = '\0';
	while (len--)
		line[len] = save_line[len];
	len = 0;
	while (save_line[i])
	{
		buffer[len] = save_line[i];
		i++;
		len++;
	}
	buffer[len] = '\0';
	free(save_line);
	return (line);
}
