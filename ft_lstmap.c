/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 18:03:19 by aschulz-          #+#    #+#             */
/*   Updated: 2026/06/01 19:22:08 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*ft_lstmap(t_list *lst, void *(f)(void *), void (void *del))
{
	t_list *new_lst;
	t_list *curr_node;
	

	new_lst = ft_lstnew(f(lst->content));
	while (lst)
	{
		lst = lst->next;
		if (!lst)
			return (new_lst);
		curr_node = ft_lstnew(f(lst->content));
		if (!curr_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, curr_node);
	}
	return (new_lst);
}