/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:17:37 by aid-bray          #+#    #+#             */
/*   Updated: 2024/11/17 13:55:08 by aid-bray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd)
{
	char	*buff;
	ssize_t	len;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff = malloc (BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	len = read(fd, buff, BUFFER_SIZE);
	if (len <= 0)
		return (free(buff), NULL);
	buff[len] = '\0';
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*stock = NULL;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (!is_line(stock))
	{
		buff = read_file(fd);
		if (!buff)
			break ;
		stock = ft_strjoin(stock, buff);
		free(buff);
	}
	if (is_line(stock) || ft_strlen(stock))
		return (get_new_line(&stock));
	free(stock);
	stock = NULL;
	return (NULL);
}

int main()
{
    char *p;
    int fd = 0;//open("dev/",O_RDONLY);
     int fd2 = open("write1",O_WRONLY );
    if (fd < 0 || fd2 < 0)
        return (1);
    int i = 1;
    int j = 1;
    while (i)
    {
        p = get_next_line(fd);
        if (!p)
            break;
        write(fd2, p, ft_strlen(p));
		free(p);
       // printf("%s", p);
	//    scanf("%d",&i);
    }
return j;
}