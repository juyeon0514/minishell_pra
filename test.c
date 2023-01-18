/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:42:33 by juykang           #+#    #+#             */
/*   Updated: 2023/01/18 15:39:20 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char *str = "ls -l| cat << > '' abc a>";
	t_token	*head;

	head = new_token();
	set_token(str, &head);
	head = head->next;
	/*while (head)
	{
		printf("%d", head->type);
		printf("%s", head->str);
		head = head->next;
	}*/
	return (0);
}
