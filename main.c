/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 10:39:44 by aschulz-          #+#    #+#             */
/*   Updated: 2026/05/27 18:56:40 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void test_strnstr();
void test_substr();
void test_strjoin();
void test_strtrim();

int	main(void)
{
	printf("%s", ft_strrchr("famioma", 'a'));
	test_strnstr();
	test_substr();
	test_strjoin();
	test_strtrim();
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
