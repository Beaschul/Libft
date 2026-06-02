/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 10:39:44 by aschulz-          #+#    #+#             */
/*   Updated: 2026/06/01 14:49:51 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "linkedlist.h"

void test_strnstr();
void test_substr();
void test_strjoin();
void test_strtrim();
void test_split();
void test_linkedlist();

int	main(void)
{
	printf("%s", ft_strrchr("famioma", 'a'));
	test_strnstr();
	test_substr();
	test_strjoin();
	test_strtrim();
	test_split();
	test_linkedlist();
	return 0;
}
void test_strnstr()
{
	printf("\n\n************************************************\n");
	printf("TESTANDO STRNSTR!\n");
	char * nome = "ana beatrice";
	char * oi = ft_strnstr(nome, "ri", ft_strlen(nome));
	printf("res = %s", oi);
}

void test_substr()
{
	printf("\n\n************************************************\n");
	printf("TESTANDO SUBSTR!\n");
	char * nome = "ana beatrice";
	char * oi = ft_substr(nome, 4, ft_strlen(nome));
	printf("res = %s", oi);
}

void test_strjoin()
{
	printf("\n\n************************************************\n");
	printf("TESTANDO STRJOIN!\n");
	char * nome1 = "ana";
	char * nome2 = "beatrice";
	char * joined = ft_strjoin(nome1, nome2);
	printf("res = %s", joined);
}

void test_strtrim()
{
	printf("\n\n************************************************\n");
	printf("TESTANDO STRTRIM!\n");
	char * nome1 = "1ana2";
	char * joined = ft_strtrim(nome1, "123");
	printf("res = %s", joined);	
}
void test_split()
{
	printf("\n\n************************************************\n");
	printf("TESTANDO SPLIT!\n");
	char * nome1 = "";
	char ** joined = ft_split(nome1, ' ');
	
	while (*joined)
	{
		printf("res = %s\n", *joined);
		joined++;	
	}
}

int compare(void *cont1, void *cont2)
{
	return *((int *)cont1) == *((int *)cont2);
}

void test_linkedlist()
{
	printf("\n\n************************************************\n");
	printf("TESTANDO LINKEDLIST!\n");
	int n1 = 1;
	int n2 = 2;
	int n3 = 3;
	int n4 = 4;
	t_ll *linkedlist = ll_new();

	linkedlist->add_back(linkedlist, &n1);
	linkedlist->add_back(linkedlist, &n2);
	linkedlist->add_back(linkedlist, &n3);
	linkedlist->add_back(linkedlist, &n4);

	t_ll_node	*temp = linkedlist->begin;
	while(temp)
	{
		printf("value: %d\n", *((int *)temp->content));
		temp = temp->next;
	}
	int tirou = n4;
	t_ll_node	*finded_node = linkedlist->find(linkedlist, &tirou, compare);
	if (finded_node)
		linkedlist->detach(linkedlist, finded_node);
	printf("tirou o %d!\n", tirou);
	temp = linkedlist->begin;
	while(temp)
	{
		printf("value: %d\n", *((int *)temp->content));
		temp = temp->next;
	}
}
