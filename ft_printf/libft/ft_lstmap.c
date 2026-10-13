/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgroenve <sgroenve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 16:40:53 by sgroenve          #+#    #+#             */
/*   Updated: 2026/10/06 18:05:55 by sgroenve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new;
	t_list	*temp2;

	head = NULL;
	while (lst != NULL)
	{
		new = ft_lstnew(((*f)(lst->content)));
		if (new == NULL)
			return (NULL);
		ft_lstadd_back(&head, new);
		temp2 = lst->next;
		if (lst->content != NULL)
			del(lst->content);
		free(lst);
		lst = temp2;
	}
	return (head);
}
