/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 01:05:09 by juykang           #+#    #+#             */
/*   Updated: 2023/01/18 16:51:42 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*new_token(void)
{
	t_token	*res;

	res = (t_token *)malloc(sizeof(t_token));
	if (!res)
		return (NULL);
	res->type = 0;
	res->str = NULL;
	res->next = NULL;
	return (res);
}

t_token	*ft_tokenlast(t_token *token)
{
	if (!token)
		return (NULL);
	while (token->next != NULL)
		token = token->next;
	return (token);
}

void	ft_lstadd_token(t_token **lst, t_token *new)
{
	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
		ft_tokenlast(*lst)->next = new;
}
