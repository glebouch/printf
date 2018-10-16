/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:51:56 by glebouch          #+#    #+#             */
/*   Updated: 2017/11/15 14:20:26 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *maillon;

	if (!(maillon = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		maillon->content = NULL;
		maillon->content_size = 0;
	}
	else
	{
		if (!(maillon->content = malloc(sizeof(content))))
			return (NULL);
		ft_memmove(maillon->content, content, content_size);
		maillon->content_size = content_size;
	}
	maillon->next = NULL;
	return (maillon);
}
