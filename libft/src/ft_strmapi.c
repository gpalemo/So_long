/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:20:13 by cmauley           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/10/23 19:57:26 by cmauley          ###   ########.fr       */
=======
/*   Updated: 2025/10/14 22:31:06 by cmauley          ###   ########.fr       */
>>>>>>> 5163350 (final)
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

<<<<<<< HEAD

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char)) //
=======
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
>>>>>>> 5163350 (final)
{
	unsigned int	i;
	char			*res;

	res = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
