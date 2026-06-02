/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 13:00:30 by aschulz-          #+#    #+#             */
/*   Updated: 2026/06/01 15:13:28 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLIST_H
# define LINKEDLIST_H

# include <stdlib.h>

typedef struct ll_node	t_ll_node;

struct ll_node
{
	void		*content;
	t_ll_node	*next;
	t_ll_node	*prev;
};

t_ll_node	*ll_new_node(void *content)
{
	t_ll_node	*node;
	
	
	node = malloc(sizeof(t_ll_node));
	if (!node)
		return (NULL);
	node->content = content; // ele esta dizendo que a chave content da struct `struct ll_node{content}` e igual ao content passado como parametro `t_ll_node	*ll_new_node(void *content << esse daqui)`;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	subjec_add_front(t_ll_node *list, t_ll_node *new_node)
{
	t_ll_node *temp = list->prev;
	while(temp)
	{
		if (list->prev)
			list = list->prev;
		temp = list->prev;
	}
	list->prev = new_node;
	new_node->next = list;
}

void	subjec_add_back(t_ll_node *list, t_ll_node *new_node)
{
	t_ll_node *temp = list->next;
	while(temp)
	{
		if (list->next)
			list = list->next;
		temp = list->next;
	}
	list->next = new_node;
	new_node->prev = list;
}

typedef struct ll	t_ll;

void		ll_add_front_node(t_ll *self, void *content);
void		ll_add_back_node(t_ll *self, void *content);
void		ll_detach_node(t_ll *self, t_ll_node	*node);
void		ll_remove_node(t_ll *self, t_ll_node	*node);
t_ll_node	*ll_find(t_ll *self, void *content, int (*compare)(void *cont1, void *cont2));


struct ll
{
	size_t		size;
	t_ll_node	*begin;
	t_ll_node	*end;

	void		(*add_front)(t_ll *self, void *content);
	void		(*add_back)(t_ll *self, void *content);
	void		(*detach)(t_ll *self, t_ll_node	*node);
	void		(*remove)(t_ll *self, t_ll_node	*node);
	t_ll_node	*(*find)(t_ll *self, void *content, int (*compare)(void *cont1, void *cont2));
};

t_ll	*ll_new()
{
	t_ll	*linkedlist;
	
	
	linkedlist = malloc(sizeof(t_ll));
	if (!linkedlist)
		return (NULL);
	linkedlist->size = 0;
	linkedlist->begin = NULL;
	linkedlist->end = NULL;
	linkedlist->add_front = ll_add_front_node;
	linkedlist->add_back = ll_add_back_node;
	linkedlist->detach = ll_detach_node;
	linkedlist->remove = ll_remove_node;
	linkedlist->find = ll_find;
	return (linkedlist);
}

void	ll_add_front_node(t_ll *self, void *content)
{
	t_ll_node	*node = ll_new_node(content);
	if (self->size == 0)
	{
		self->begin = node;
		self->end = node;
		self->size++;
		return;
	}
	self->begin->prev = node;
	node->next = self->begin;
	self->begin = node;
	self->size++;
}

void	ll_add_back_node(t_ll *self, void *content)
{
	t_ll_node	*node = ll_new_node(content);
	if (self->size == 0)
	{
		self->begin = node;
		self->end = node;
		self->size++;
		return;
	}
	self->end->next = node;
	node->prev = self->end;
	self->end = node;
	self->size++;
}

void	ll_detach_node(t_ll *self, t_ll_node	*node)
{
	if (node->next)
		node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	if (self->begin == node)
		self->begin = node->next;
	if (self->end == node)
		self->end = node->prev;
	node->next = NULL;
	node->prev = NULL;
	self->size--;
}

void	ll_remove_node(t_ll *self, t_ll_node *node)
{
	ll_detach_node(self, node);
	free(node);
}

t_ll_node	*ll_find(t_ll *self, void *content, int (*compare)(void *cont1, void *cont2))
{
	t_ll_node	*temp = self->begin;
	while(temp)
	{
		if (compare(temp->content, content))
			return temp;
		temp = temp->next;
	}
	return NULL;
}

#endif