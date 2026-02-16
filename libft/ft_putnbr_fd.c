/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwalee <hwalee@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:11:21 by hwalee            #+#    #+#             */
/*   Updated: 2025/11/12 18:13:13 by hwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	buf_flush(int fd, char *src_buf)
{
	size_t	i;
	size_t	j;
	char	flush_buf[12];

	i = 0;
	j = ft_strlen(src_buf);
	while (j != 0)
		flush_buf[i++] = src_buf[--j];
	flush_buf[i] = '\0';
	write(fd, flush_buf, i);
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	char	buf[12];
	int		i;
	int		sign;

	if (n == -2147483648)
		return (buf_flush(fd, "8463847412-"));
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n *= -1;
	}
	i = 0;
	if (n == 0)
		buf[i++] = '0';
	while (n != 0)
	{
		buf[i++] = n % 10 + '0';
		n = n / 10;
	}
	if (sign == -1)
		buf[i++] = '-';
	buf[i] = '\0';
	return (buf_flush(fd, buf));
}

/*
#include <stdio.h>

int	main()
{
	ft_putnbr_fd(2147483647, 1);
	return (0);
}
*/
