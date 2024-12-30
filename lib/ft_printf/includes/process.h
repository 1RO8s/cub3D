/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:20:59 by kamitsui          #+#    #+#             */
/*   Updated: 2023/08/28 16:58:42 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include "ft_printf.h"
# include <stddef.h>

# define FLAG_ZERO	"0"
# define FLAG_LEFT	"-"
# define FLAG_HASH	"#"
# define FLAG_SPACE	" "
# define FLAG_PLUSE	"+"

# define FIELD_PREC	"."

# define PREFIX_HH	"hh"
# define PREFIX_LL	"ll"
# define PREFIX_H	"h"
# define PREFIX_L	"l"

# define ALL_TYPE	"diuoxXpcs%"

# define NB_FLAG	5
# define NB_FIELD	2
# define NB_PREFIX	4
# define NB_TYPE	10

# define TRUE		1
# define FALSE		0

# define BIT_ZERO	0x000001
# define BIT_LEFT	0x000002
# define BIT_HASH	0x000004
# define BIT_SPACE	0x000008
# define BIT_PLUSE	0x000010
# define BIT_WIDTH	0x000020
# define BIT_PREC	0x000040

# define BIT_HH		0x000100
# define BIT_LL		0x000200
# define BIT_H		0x000400
# define BIT_L		0x000800

# define BIT_D		0x001000
# define BIT_I		0x002000
# define BIT_U		0x004000
# define BIT_O		0x008000
# define BIT_X		0x010000
# define BIT_XMAJ	0x020000
# define BIT_P		0x040000
# define BIT_C		0x080000
# define BIT_S		0x100000
# define BIT_PER	0x200000

void	process(const char *input, t_sm *machine);

typedef int		(*t_f_process)(const char *, t_sm *);
int		letter(const char *input, t_sm *machine);
int		flag(const char *input, t_sm *machine);
int		field(const char *input, t_sm *machine);
int		prefix(const char *input, t_sm *machine);
int		type(const char *input, t_sm *machine);
int		error(const char *input, t_sm *machine);
void	add_to_buff(const char c, t_sm *machine);

typedef int		(*t_f_field)(const char *, t_sm *);
int		width(const char *input, t_sm *machine);
int		precision(const char *input, t_sm *machine);
size_t	get_field_nbr(const char *input, t_sm *machine);

#endif
