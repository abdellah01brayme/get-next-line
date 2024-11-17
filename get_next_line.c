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

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*save_line;
	char		*to_return;
	long		length;

	save_line = NULL;
	while (fd != -1)
	{
		save_line = ft_strjoin(save_line, buffer);
		if (is_line(save_line))
		{
			to_return = lin_to_return(save_line, buffer);
			return (to_return);
		}
		length = read (fd, buffer, BUFFER_SIZE);
		buffer[length] = '\0';
		if (length <= 0)
		{
			if (ft_strlen(save_line) > 0)
				return (buffer[0] = '\0', save_line);
			free(save_line);
			break ;
		}
	}
	return (NULL);
}

int main()
{
    char *p;
    int fd = open("txt1",O_RDONLY);
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