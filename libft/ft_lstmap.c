/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 20:26:50 by glebouch          #+#    #+#             */
/*   Updated: 2017/11/16 13:00:29 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*debutnew;
	t_list	*inutile;

	inutile = f(lst);
	if (!(new = ft_lstnew(inutile->content, inutile->content_size)))
		return (NULL);
	debutnew = new;
	lst = lst->next;
	while (lst)
	{
		inutile = f(lst);
		if (!(new->next = ft_lstnew(inutile->content, inutile->content_size)))
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (debutnew);
}
