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
	if (!save_line)
		return (0);
	while (save_line[i])
		if (save_line[i++] == '\n')
			return (i - 1);
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
	if (s1)
		while (s1[i])
		{
			tab[i] = s1[i];
			i++;
		}
	free(s1);
	if (s2)
		while (s2[j])
		{
			tab[i] = s2[j];
			i++;
			j++;
		}
	tab[i] = '\0';
	s2[0] = '\0';
	return (tab);
}

char	*get_new_line(char **stock)
{
	char	*line;
	char	*rest, *tmp = *stock;
	ssize_t	len;
	ssize_t	i;

	i = is_line(*stock);
	i++;
	line = malloc (i + 1);
	if (!line)
		return (NULL);
	len = -1;
	rest = *stock;
	while (++len < i)
		line[len] = rest[len];
	line[len] = '\0';
	tmp = malloc (ft_strlen(rest + len) + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (rest[len])
	{
		tmp[i++] = rest[len++];
	}
	tmp[i] = '\0';
	free(rest);
	*stock = tmp;
	// printf("%s=======================\n\n", *stock);
	return (line);
}
