/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarbert <mnarbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:07:16 by mnarbert          #+#    #+#             */
/*   Updated: 2018/11/28 15:34:48 by mnarbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *src, const char *to_find)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (to_find[i] == '\0')
		return ((char*)src);
	while (src[i] != '\0')
	{
		while (src[i + j] == to_find[j])
		{
			if (to_find[j] == '\0')
				return ((char*)&src[i]);
			j++;
		}
		if (to_find[j] == '\0')
			return ((char*)&src[i]);
		i++;
		j = 0;
	}
	return (NULL);
}
