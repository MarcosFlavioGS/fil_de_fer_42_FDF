/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflavio- <mfghost69@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:18:49 by mflavio-          #+#    #+#             */
/*   Updated: 2022/09/27 00:18:50 by mflavio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		len = 0;
	if (s + start > s + ft_strlen(s))
	{
		dest = malloc(1);
		*dest = '\0';
		return (dest);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	dest = (char *) malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s + start, len + 1);
	return (dest);
}
