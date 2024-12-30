/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:27:32 by kamitsui          #+#    #+#             */
/*   Updated: 2023/06/21 15:26:42 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
# define CONVERSION_H

# include "ft_printf.h"
# include <stdlib.h>

typedef void				(*t_f_conversion)(t_sm *);
void	conversion(t_sm *machine);
void	decimal(t_sm *machine);
void	unsign_decimal(t_sm *machine);
void	octal(t_sm *machine);
void	hexadecimal(t_sm *machine);
void	pointer(t_sm *machine);
void	character(t_sm *machine);
void	string(t_sm *machine);
void	percent(t_sm *machine);
char	*itoa_buff(unsigned long long num, char *str, int base, t_sm *machine);

#endif
