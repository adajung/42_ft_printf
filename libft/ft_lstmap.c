/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwalee <hwalee@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:34:44 by hwalee            #+#    #+#             */
/*   Updated: 2025/11/13 16:19:29 by hwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p_new;
	t_list	*new_head;

	if (lst == NULL)
		return (0);
	p_new = ft_lstnew(NULL);
	if (p_new == NULL)
		return (0);
	new_head = p_new;
	while (lst->content != NULL)
	{
		p_new->content = f(lst->content);
		if (lst->next == NULL)
			return (new_head);
		lst = lst->next;
		p_new->next = ft_lstnew(NULL);
		if (p_new->next == NULL)
		{
			ft_lstclear(&new_head, del);
			return (0);
		}
		p_new = p_new->next;
	}
	return (new_head);
}
