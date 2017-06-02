/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 16:32:14 by mallard           #+#    #+#             */
/*   Updated: 2017/06/02 18:09:44 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	check_access(char **str, char *test)
{
	extern char		**environ;
	int				i;
	char			*tmp;
	char			**tab;

	if (access(test, F_OK) == 0)
		*str = test;
	else
	{
		i = 0;
		while (environ[i] && ft_strncmp(environ[i], "PATH", 4))
			i++;
		tmp = ft_strchr(environ[i], '=') + 1;
		tab = ft_strsplit(tmp, ':');
		i = 0;
		while (tab[i])
		{
			tmp = double_path(tab[i], test);
			if (access(tmp, F_OK) == 0)
			{
				*str = tmp;
				tabdel(tab);
				return ;
			}
			else
				ft_strdel(&tmp);
			i++;
		}
		tabdel(tab);
		error_command(test);
	}
}

char    *double_path(char *s1, char *s2)
{
	char    *str;

	if (!s1 || !s2)
		return (NULL);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	else
	{
		str = ft_strjoin(s1, "/");
		str = ft_strjoin_f(str, s2, 0);
	}
	return (str);
}