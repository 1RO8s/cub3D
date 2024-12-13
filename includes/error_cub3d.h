/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cub3d.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:26:28 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/21 02:49:47 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_CUB3D_H
# define ERROR_CUB3D_H

/**
 * @brief error prompt
 */
# define ERR_PROMPT "Error: "

// init_game.c
// Not one argument
# define EMSG_ARG_COUNT	"One argument must be specified"
// Incorrect file extension
# define EMSG_FILE_EXT	"Specify a file path with .cub extension"
// example
// "Error: One argument must be specified"
// "Error: Specify a file path with .cub extension"

// init_cub_contents.c
// open() system call failure
# define EMSG_OPEN_FAILED "File open failed"
// empty file or read() system call failure
# define EMSG_READ_FAILED "File read failed"
// if only '\n' in cubfile
# define EMSG_EMPTY_CUB "Empty cub file"
// example
// "Error: File open failed"
// "Error: File read failed"
// "Error: Empty cub file"

// parse_tex.c
// Only key of texture ... "NO: "
# define EMSG_XPM_FILE "Texture file"
// mlx_get_data_addr() func failure with using texture image
# define EMSG_IMG_DATA_ADDR "mlx_get_data_addr"
// Incorrect XPM format OR mlx_xpm_file_to_image() func failure
# define EMSG_MLX_XPM_TO_IMG "mlx_xpm_file_to_image"
// example
// "Error: NO: Texture file"
// "Error: mlx_get_data_addr"
// "Error: mlx_xpm_file_to_image: file_name.xpm"

// Entry
// If same entry is duplicate
# define EMSG_ENTRY_DUP		"Duplicate entry"
// If Missing entry
# define EMSG_ENTRY_MISS	"Missing entry"
// If invalid entry
# define EMSG_ENTRY_INVAL	"Invalid entry"
// example
// "Error: F: Duplicate entry"
// "Error: F: Missing entry"
// "Error: BA: Invalid entry"

// RGB
// If rgb value is range over
# define EMSG_RGB_RANGE_OUT	"Out of range (0 ~ 255)"
// If the string of rgb value is not a number
# define EMSG_RGB_NOT_NUM	"is not a number"
// If no value in any of the RGB
# define EMSG_RGB_MISS		"Missing RGB component"
// If no the string for RGB
# define EMSG_RGB_EMPTY		"Empty RGB component"
// example
// "Error: F: "8523" Out of range"		... F 8523, 42, 42
// "Error: F: "i" is not a number"		...	F i, 42, 42
// "Error: F: Missing RGB component B" 	... F 10, 10, ,
// "Error: F: Empty RGB component"		... F

// MAP
# define EMSG_MAP_CHAR			"MAP: Invalid characters found"
# define EMSG_MAP_PLAYER_MULTI	"MAP: Multiple player start positions"
# define EMSG_MAP_PLAYER_MISS	"MAP: Missing player start position"
# define EMSG_MAP_NOT_LAST		"MAP: Must be the last element"
# define EMSG_MAP_NOT_ENCLOSED	"MAP: Not enclosed by walls"
# define EMSG_MAP_TOO_LARGE		"MAP: Too large"

#endif
