/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_fonction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:33:19 by gmersch           #+#    #+#             */
/*   Updated: 2023/11/24 18:33:59 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

void	ft_putnbr(int n)
{
	unsigned int	nb;
	int				c;

	nb = n;
	if (n < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
	}
	if (nb > 9)
		ft_putnbr((nb / 10));
	nb = nb % 10;
	c = nb + '0';
	write(1, &c, 1);
}

static size_t	count_number(unsigned int n)
{
	size_t	c;

	c = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

static char	*ft_swap(char *str)
{
	char	b;
	int		a;
	int		z;

	a = 0;
	z = ft_strlen(str);
	z--;
	while (a < z)
	{
		b = str[a];
		str[a] = str[z];
		str[z] = b;
		a++;
		z--;
	}
	return (str);
}

static char	*write_str2(char *str, unsigned int n)
{
	int	i;

	i = 0;
	while (n > 9)
	{
		str[i] = (n % 10) + 48;
		n = n / 10;
		i++;
	}
	str[i] = (n % 10) + 48;
	i++;
	str[i] = '\0';
	str = ft_swap(str);
	return (str);
}

char	*ft_second_itoa(unsigned int n)
{
	size_t	c;
	char	*str;

	c = count_number(n);
	str = malloc(sizeof(char) * c + 1);
	if (!str)
		return (NULL);
	str = write_str2(str, n);
	return (str);
}
