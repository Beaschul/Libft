/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 17:15:04 by aschulz-          #+#    #+#             */
/*   Updated: 2026/06/01 17:33:56 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_lstclear(t_list **lst, void (del)(void *))
{
	t_list *temp;

	temp = (*lst)->next;
	while(*lst)
	{
		ft_lstdelone(*lst, del);
		*lst = temp;
		if (*lst)
			temp = (*lst)->next;
	}
	*lst = NULL;
}
