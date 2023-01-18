/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 01:05:09 by juykang           #+#    #+#             */
/*   Updated: 2023/01/18 14:51:57 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*new_node(void)
{
	t_list	*res;

	res = (t_list *)malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->len = 0;
	res->c = '\0';
	res->next = NULL;
	return (res);
}

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

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	if (!(*lst))
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
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

void	destroy_list(t_list **node_head)
{
	t_list	*tmp;

	tmp = (*node_head);
	while ((*node_head))
	{
		(*node_head) = (*node_head)->next;
		free(tmp);
		tmp = (*node_head);
	}
}
