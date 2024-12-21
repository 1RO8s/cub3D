/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formalize.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:04:49 by kamitsui          #+#    #+#             */
/*   Updated: 2023/03/29 22:43:39 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMALIZE_H
# define FORMALIZE_H

# include "ft_printf.h"
# include <stdlib.h>

void	formalize(const char *str, t_sm *machine);
void	adjust(const char *str, t_sm *machine);
void	adjust_field(const char *str, t_sm *machine);
void	adjust_width(const char *str, t_sm *machine);
void	adjust_prec(const char *str, t_sm *machine);
void	adjust_number(const char *str, t_sm *machine);
void	adjust_string(const char *str, t_sm *machine);
void	adjust_sign(char *str, t_sm *machine);
void	adjust_hash(char *str, t_sm *machine);
void	pad_str(const char *str, t_sm *machine);
void	pad_n_str(const char *str, t_sm *machine, int limit);
void	pad_width(t_sm *machine, int offset);
void	pad_prec(t_sm *machine, int len);
void	sequence_signed(const char *str, t_sm *machine);
void	sequence_unsigned(const char *str, t_sm *machine);

#endif
