/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:02:25 by mnarbert          #+#    #+#             */
/*   Updated: 2018/11/23 17:02:28 by mnarbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*fresh;
	t_list		*temp;
	t_list		*temp_fresh;

	if (!lst || !f)
		return (NULL);
	temp = f(lst);
	fresh = ft_lstnew(temp->content, temp->content_size);
	temp_fresh = fresh;
	lst = lst->next;
	while (lst)
	{
		temp = f(lst);
		if (!(fresh->next = ft_lstnew(temp->content, temp->content_size)))
			return (NULL);
		fresh = fresh->next;
		lst = lst->next;
	}
	return (temp_fresh);
}
