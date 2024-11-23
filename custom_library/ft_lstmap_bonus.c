/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:12:00 by azerfaou          #+#    #+#             */
/*   Updated: 2024/10/25 13:02:28 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
* ft_lstmap: Creates a new list by applying the function 'f' to each node's
* content in the original list 'lst'. If memory allocation for any node fails,
*/
/*
** the 'del' function is used to free all previously allocated nodes.
**
** Key points:
** - Iterates over the original list 'lst'.
** - Applies 'f' to each node's content and creates a new node with the result.
** - Uses 'ft_lstadd_back' to add each new node to the new list.
** - If memory allocation fails at any point,
	it clears the new list with 'ft_lstclear'
**   and returns NULL to prevent memory leaks.
**
** Parameters:
** - lst: Pointer to the first node of the original list.
** - f: Function to apply to each node's content.
** - del: Function to free the content of a node in case of allocation failure.
**
** Return:
** - The new list if successful, or NULL if allocation fails.
*/

// dont forget to free new_content separatly

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*new_node;
	t_list	*new_lst;
	void	*new_content;

	new_lst = NULL;
	current = lst;
	if (!lst)
		return (NULL);
	while (current != NULL)
	{
		new_content = f(current->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		current = current->next;
	}
	return (new_lst);
}
