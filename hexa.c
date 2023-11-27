/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:00:35 by gmersch           #+#    #+#             */
/*   Updated: 2023/11/25 18:35:57 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

void	hexa_base_16_lower(int n)
{
	unsigned int	nb;
	char			*str;

	str = "0123456789abcdef";
	nb = n;
	if (nb > 16)
		hexa_base_16_lower(nb / 16);
	nb = nb % 16;
	write(1, &str[nb], 1);
}

void	hexa_base_16_upper(int n)
{
	unsigned int	nb;
	char			*str;

	str = "0123456789ABCDEF";
	nb = n;
	if (nb > 16)
		hexa_base_16_upper(nb / 16);
	nb = nb % 16;
	write(1, &str[nb], 1);
}

void	hexa_base_16_pt(long int n)
{
	unsigned long int	nb;
	char				*str;

	str = "0123456789abcdef";
	nb = n;
	if (nb > 16)
		hexa_base_16_pt(nb / 16);
	nb = nb % 16;
	write(1, &str[nb], 1);
}
