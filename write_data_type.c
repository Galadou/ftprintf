/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_data_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:44:04 by gmersch           #+#    #+#             */
/*   Updated: 2023/11/24 18:44:21 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	write_data(int nb, va_list lst)
{
	char	letter;
	char	*str;
	int		i;

	i = 0;
	if (nb == 1)
		ft_putnbr(va_arg(lst, int));
	else if (nb == 2)
	{
		letter = (char)va_arg(lst, int);
		write(1, &letter, 1);
	}
	else if (nb == 3)
	{
		str = va_arg(lst, char *);
		while (str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
		}
		return (ft_strlen(str));
	}
	else if (nb > 3)
		write_data_next(nb, lst);
	return (0);
}

void	write_data_next(int nb, va_list lst)
{
	char	*str;
	int		i;

	i = 0;
	if (nb == 4)
		ft_putnbr(va_arg(lst, long int));
	else if (nb == 5)
	{
		str = ft_second_itoa(va_arg(lst, unsigned int));
		while (str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	else if (nb == 6)
		hexa_base_16_lower(va_arg(lst, int));
	else if (nb == 7)
		hexa_base_16_upper(va_arg(lst, int));
	else if (nb == 8)
	{
		write(1, "0x", 2);
		hexa_base_16_pt(va_arg(lst, long int));
	}
}
