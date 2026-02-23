/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:57:10 by cmauley           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/10/23 20:12:39 by cmauley          ###   ########.fr       */
=======
/*   Updated: 2025/10/20 20:09:53 by cmauley          ###   ########.fr       */
>>>>>>> 5163350 (final)
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

<<<<<<< HEAD
//
=======
>>>>>>> 5163350 (final)
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
/*int	main()
{
	t_list	*a = ft_lstnew("hello");
	t_list	*b = ft_lstnew("world");
	t_list	*c = ft_lstnew("42");

	a->next = b;
	ft_lstadd_back(&a, c);
	printf("%s\n",(char *)a->next->next->content);
	return(0);
}*/
