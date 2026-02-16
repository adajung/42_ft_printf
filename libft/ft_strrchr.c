/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwalee <hwalee@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:10:09 by hwalee            #+#    #+#             */
/*   Updated: 2025/11/12 15:53:01 by hwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				mark;
	unsigned char	unsinged_c;

	mark = -1;
	unsinged_c = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == unsinged_c)
			mark = i;
		i++;
	}
	if (unsinged_c == '\0')
		return ((char *)s + i);
	if (mark < 0)
		return (0);
	return ((char *)s + mark);
}
