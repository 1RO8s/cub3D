/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:03:47 by kamitsui          #+#    #+#             */
/*   Updated: 2024/08/04 06:13:01 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include	<unistd.h>
# include	<stdlib.h>
# include	"libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
//#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

#endif
