/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:06:32 by jericard          #+#    #+#             */
/*   Updated: 2025/10/29 16:06:34 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*helper(void *content, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;

	content = f(content);
	if (!content)
		return (NULL);
	new = ft_lstnew(content);
	if (!new)
	{
		del(content);
		return (NULL);
	}
	return (new);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tail;

	if (!lst || !f || !del)
		return (NULL);
	head = helper(lst->content, f, del);
	if (!head)
		return (NULL);
	tail = head;
	lst = lst->next;
	while (lst != NULL)
	{
		tail->next = helper(lst->content, f, del);
		if (!tail->next)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		tail = tail->next;
		lst = lst->next;
	}
	return (head);
}
