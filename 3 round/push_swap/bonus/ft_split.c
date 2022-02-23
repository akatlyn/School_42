/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akatlyn <akatlyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:22:14 by akatlyn           #+#    #+#             */
/*   Updated: 2021/10/13 21:22:15 by akatlyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"checker.h"

static int	ft_nstr(const char *s, char c)
{
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != 0)
			l++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (l);
}

static int	ft_wrdlen(const char *s, char c, int i)
{
	int	l;

	l = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		l++;
	}
	return (l);
}

static void	*ft_free(char	**mass, int m)
{
	int		i;

	i = 0;
	while (m > i)
		free(mass[i++]);
	free(mass);
	return (0);
}

static char	**ft_mpstr(char const *s, char c, char **mass, int nstr)
{
	int		i;
	int		l;
	int		m;
	int		mm;

	i = 0;
	m = 0;
	while (nstr > m)
	{
		while (s[i] == c)
			i++;
		l = ft_wrdlen(s, c, i);
		mass[m] = (char *)malloc(sizeof(char) * (l + 1));
		if (mass[m] == 0)
			return (ft_free(mass, m));
		mm = 0;
		while (l > mm)
			mass[m][mm++] = s[i++];
		mass[m++][mm] = '\0';
	}
	mass[m] = NULL;
	return (mass);
}

char	**ft_split(char const *s, char c)
{
	char	**mass;
	int		nstr;

	if (s == 0)
		return (0);
	nstr = ft_nstr(s, c);
	mass = (char **)malloc(sizeof(char *) * (nstr + 1));
	if (mass == 0)
		return (0);
	ft_mpstr(s, c, mass, nstr);
	return (mass);
}
