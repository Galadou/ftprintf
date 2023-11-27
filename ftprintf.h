/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:40:07 by gmersch           #+#    #+#             */
/*   Updated: 2023/11/24 18:41:21 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putnbr(int n);
int		ft_printf(const char *str, ...);
int		write_data(int nb, va_list lst);
void	write_data_next(int nb, va_list lst);
char	*ft_second_itoa(unsigned int n);
void	hexa_base_16_lower(int n);
void	hexa_base_16_upper(int n);
void	hexa_base_16_pt(long int n);
size_t	ft_strlen(const char *s);

#endif
