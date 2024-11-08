/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:51:10 by ezeppa            #+#    #+#             */
/*   Updated: 2024/11/08 19:39:52 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

#include <stdio.h>
char	*ft_strdup(const char *s)
{
	int		s_len;
	char	*ptr;

	s_len = ft_strlen(s);
	ptr = malloc(sizeof(char) * s_len + 1);
	if (!ptr)
		return (ptr);
	ft_strlcpy(ptr, s, s_len + 1);
	return (ptr);
}
