/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:49:11 by gmersch           #+#    #+#             */
/*   Updated: 2023/11/22 16:10:36 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static	int	type_finder(char c, va_list lst)
{
	if (c == 'd')
		return (write_data(1, lst));
	else if (c == 'c')
		return (write_data(2, lst));
	else if (c == 's')
		return (write_data(3, lst));
	else if (c == 'i')
		return (write_data(4, lst));
	else if (c == 'u')
		return (write_data(5, lst));
	else if (c == 'x')
		return (write_data(6, lst));
	else if (c == 'X')
		return (write_data(7, lst));
	else if (c == 'p')
		return (write_data(8, lst));
	else if (c == '%')
		write(1, "%", 1);
	return (0);
}

int	percent_or_write(va_list lst, int *result, int *i, const char *str)
{
	if (str[*i] == '%' && str[*i + 1] != '\0')
	{
		result = result + type_finder(str[*i + 1], lst);
		*i = *i + 1;
		return (1);
	}
	else
		write(1, &str[*i], 1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		result;
	int		i;
	int		nb_percent;
	va_list	lst;

	if (str == NULL)
		return (-1);
	i = 0;
	nb_percent = 0;
	result = 0;
	va_start(lst, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '\0')
			return (-1);
		nb_percent += percent_or_write(lst, &result, &i, str);
		i++;
	}
	va_end(lst);
	return (ft_strlen(str) + result - nb_percent);
}
/*
int main (void)
{
	int i = 0;
	unsigned int u = 0;
	int x = 0;
	int X = 0;
	int *p = &x;
	
	//Ma Fonction
	ft_printf("\
	d = %d\n\
	c = %c\n\
	s = %s\n\
	i = %i\n\
	u = %u\n\
	x = %x\n\
	X = %X\n\
	p = %p\n\
	pourcent = %%\n\n", -2147483647, 'j', "les amies", i, u, x, X, p);
	
	//Vrais Fonction
	printf("VRAIS PRINTF\n\
	d = %d\n\
	c = %c\n\
	s = %s\n\
	i = %i\n\
	u = %u\n\
	x = %x\n\
	X = %X\n\
	p = %p\n\
	pourcent = %%\n", -2147483647, 'j', "les amies", i, u, x, X, p);
	printf("%d", ft_printf("%s vla", "salut"));
	return (0);

}*/
