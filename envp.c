/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:13:34 by juykang           #+#    #+#             */
/*   Updated: 2023/01/16 20:36:39 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_envp_key(char *envp)
{
	int		i;
	int		len;
	char	*res;

	if (!envp)
		return (NULL);
	len = 1;
	while (envp[len] != '\0' && envp[len] != '=')
		len++;
	res = (char *)malloc(sizeof(char) * len + 1);
	i = 0;
	while (i < len)
	{
		res[i] = envp[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*get_envp_value(char *envp)
{
	char	*res;

	res = ft_strchr(envp, '=') + 1;
	return (res);
}

t_envp_list	*new_node(void)
{
	t_envp_list	*tmp;

	tmp = (t_envp_list *)malloc(sizeof(t_envp_list));
	if (!tmp)
		return (NULL);
	tmp->key = NULL;
	tmp->value = NULL;
	tmp->len = 1;
	tmp->next = NULL;
	return (tmp);
}

void	set_envp_list(char **envp)
{
	t_envp_list	*envp_list;

	envp_list = new_node();
	while (*envp)
	{
		envp_list->key = get_envp_key(*envp);
		envp_list->value = get_envp_value(*envp);
		envp_list->len++;
		envp_list->next = new_node();
		envp_list = envp_list->next;
		envp++;
	}
}
