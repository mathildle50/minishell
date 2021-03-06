/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 17:30:15 by mallard           #+#    #+#             */
/*   Updated: 2017/09/09 17:48:07 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../libft/include/libft.h"

static char		**tab_cpy(char **tab)
{
	int		i;
	char	**tmp;

	tmp = NULL;
	if (*tab)
	{
		i = tablen(tab);
		if (!(tmp = newtab(i)))
			return (NULL);
		i = -1;
		while (tab[++i])
			tmp[i] = ft_strdup(tab[i]);
	}
		return (tmp);
}

static void		ft_u(char *name)
{
	extern char		**environ;
	char			**tmp;
	int				i;
	
	tmp = tab_cpy(environ);
	if ((i = env_chr(name, ft_strlen(name))) >= 0)
		char_del(tmp, i);
	print_tab(tmp);
	tabdel(tmp);
}

void			ft_env(char *line)
{
	extern char		**environ;
	char			**tmp;
	char			*str;
	char			*n;

	n = NULL;
	if (!(tmp = ft_split(line)))
		return ;
	if (tablen(tmp) == 1)
		print_tab(environ);
	else
	{
		str = ft_strtrim(tmp[1]);
		if (!ft_strcmp(str, "-u"))
		{
			if (tablen(tmp) == 3)
				ft_u(tmp[2]);
		}
		else if (!ft_strcmp(str, "-i"))
			is_built(ft_strtrim(ft_strchr(line, '-') + 2), "/Users/mallard", &n);
		else
			ft_putendl("usage : ");
	}
}
