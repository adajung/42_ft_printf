/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwalee <hwalee@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:15:32 by hwalee            #+#    #+#             */
/*   Updated: 2025/11/12 16:04:29 by hwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && (i < n))
	{
		if (s1[i] != s2[i])
		{
			if ((unsigned char)s1[i] > (unsigned char)s2[i])
				return (1);
			else
				return (-1);
		}
		i++;
	}
	if (i == n || (unsigned char)s1[i] == (unsigned char)s2[i])
		return (0);
	if ((unsigned char)s1[i] > (unsigned char)s2[i])
		return (1);
	else
		return (-1);
}
