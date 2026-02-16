/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwalee <hwalee@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:40:06 by hwalee            #+#    #+#             */
/*   Updated: 2025/11/13 15:30:49 by hwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_sep(char const *s, char c)
{
	size_t	i;
	size_t	spnum;
	int		flag;

	i = 0;
	spnum = 0;
	flag = 1;
	while (s[i])
	{
		if (flag == 1 && s[i] != c)
		{
			spnum++;
			flag = 0;
		}
		else if (flag == 0 && s[i] == c)
			flag = 1;
		i++;
	}
	return (spnum);
}

static void	*free_dptr(char **p, size_t i)
{
	while (i > 0)
		free(p[i--]);
	free(p[i]);
	free(p);
	return (0);
}

static char	**malloc_dptr(char const *s, char c, size_t spnum)
{
	char	**p;
	size_t	i;
	size_t	j;
	size_t	size;

	p = (char **)malloc((spnum + 1) * sizeof(char *));
	if (p == NULL)
		return (0);
	if (spnum == 0)
		p[0] = NULL;
	i = 0;
	j = 0;
	while (i < spnum)
	{
		size = 0;
		while (s[j] == c)
			j++;
		while (s[j] && (s[j++] != c))
			size++;
		p[i] = (char *)malloc((size + 1) * sizeof(char));
		if (p[i] == NULL)
			return ((char **)free_dptr(p, i));
		i++;
	}
	return (p);
}

static void	init_dptr(char **p, char const *src, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (p[0] == NULL)
		return ;
	while (src[i])
	{
		if (src[i] != c)
			p[j][k++] = src[i];
		if ((src[i] == c) && (src[i + 1] != c) && (src[i + 1] != '\0'))
		{
			if (k != 0)
				p[j++][k] = '\0';
			k = 0;
		}
		if (src[++i] == '\0')
			p[j++][k] = '\0';
	}
	p[j] = NULL;
	return ;
}

char	**ft_split(char const *s, char c)
{
	size_t	spnum;
	char	**p;

	if (s == NULL)
		return (0);
	spnum = count_sep(s, c);
	p = malloc_dptr(s, c, spnum);
	if (p == NULL)
		return (0);
	init_dptr(p, s, c);
	return (p);
}
/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	**p;
	size_t	i;

	if (argc != 3)
		return (0);
	p = ft_split(argv[1], *argv[2]);
	i = 0;
	while (p[i] != NULL)
	{
		printf("%s\n", p[i++]);
	}
	return (0);
}
*/
