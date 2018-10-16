/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:56:07 by glebouch          #+#    #+#             */
/*   Updated: 2017/11/14 15:15:52 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int	size;

	size = 1;
	if (n < 0)
		size++;
	while (n / 10)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	int		size;
	char	*s;

	size = ft_size(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (!(s = (char *)malloc(size + 1)))
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	s[size] = '\0';
	while (n > 0)
	{
		s[size - 1] = n % 10 + 48;
		n = n / 10;
		--size;
	}
	return (s);
}
