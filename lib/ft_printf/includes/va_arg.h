/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:18:08 by kamitsui          #+#    #+#             */
/*   Updated: 2023/06/21 15:26:11 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VA_ARG_H
# define VA_ARG_H

typedef unsigned long long	(*t_f_u_va_arg)(t_sm *);
unsigned long long	unsign_hh(t_sm *machine);
unsigned long long	unsign_ll(t_sm *machine);
unsigned long long	unsign_h(t_sm *machine);
unsigned long long	unsign_l(t_sm *machine);
unsigned long long	unsign_int(t_sm *machine);
unsigned long long	unsign_va_arg(t_sm *machine);

typedef long long			(*t_f_s_va_arg)(t_sm *);
long long			sign_hh(t_sm *machine);
long long			sign_ll(t_sm *machine);
long long			sign_h(t_sm *machine);
long long			sign_l(t_sm *machine);
long long			sign_int(t_sm *machine);
long long			sign_va_arg(t_sm *machine);

#endif
