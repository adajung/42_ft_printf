/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwalee <hwalee@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:11:33 by hwalee            #+#    #+#             */
/*   Updated: 2025/11/13 15:50:56 by hwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*temp;

	p = *lst;
	*lst = NULL;
	while (p != NULL)
	{
		del(p->content);
		temp = p->next;
		free(p);
		p = temp;
	}
	return ;
}
