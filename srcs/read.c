/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoldber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:47:54 by tgoldber          #+#    #+#             */
/*   Updated: 2017/12/08 13:47:56 by tgoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fillit.h"
#include "libft.h"

t_tetro		*ft_rewind(t_tetro *tetro)
{
	if (tetro == NULL)
		ft_error("error");
	while (tetro->previous)
		tetro = tetro->previous;
	return (tetro);
}

void		ft_make_str(char **str, char *line)
{
	str[0] = ft_strdup(line);
	str[1] = ft_strnew(5);
	str[2] = ft_strnew(5);
	str[3] = ft_strnew(5);
	str[4] = 0;
	if (str[0] == NULL || str[1] == NULL ||
		str[2] == NULL || str[3] == NULL)
		ft_error("error");
}

void		ft_make_tetro(t_tetro **tetro, char *str)
{
	t_tetro *new;

	if (!(new = (t_tetro*)malloc(sizeof(t_tetro) * 1)))
		ft_error("error");
	ft_check_line(str);
	if ((new->str = (char**)malloc(sizeof(char*) * 5)) == NULL)
		ft_error("error");
	ft_make_str(new->str, str);
	if (*tetro != NULL)
	{
		(*tetro)->next = new;
		new->c = (*tetro)->c + 1;
		if ((*tetro)->c == 'Z')
			ft_error("error");
	}
	else
		new->c = 'A';
	new->previous = *tetro;
	new->next = NULL;
	*tetro = new;
}

t_tetro		*ft_read_file(int fd)
{
	int		i;
	int		gnl;
	t_tetro *tetro;
	char	*str;

	tetro = NULL;
	while ((gnl = get_next_line(fd, &str)) == 1)
	{
		ft_make_tetro(&tetro, str);
		i = 0;
		while (i < 3)
		{
			if ((gnl = get_next_line(fd, &str)) <= 0)
				ft_error("error");
			ft_check_line(str);
			ft_strcpy(tetro->str[i + 1], str);
			i++;
		}
		if ((gnl = get_next_line(fd, &str)) == -1 || ft_strlen(str) != 0)
			ft_error("error");
	}
	if (gnl == -1)
		ft_error("error");
	return (ft_rewind(tetro));
}
