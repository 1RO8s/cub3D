#ifndef ERROR_CUB3D_H
# define ERROR_CUB3D_H


/**
 * @brief error message
 */
# define ERR_PROMPT "Error: "

#define EMSG_ARG_COUNT	"One argument must be specified"
#define EMSG_FILE_EXT	"Specify a file path with .cub extension"

// parse_tex.c
# define EMSG_XPM_FILE "texture file"
# define EMSG_IMG_DATA_ADDR "failure mlx_get_data_addr function"


// Entry
// "F: Duplicate entry"
# define EMSG_ENTRY_DUP		"Duplicate entry"
// "F Missing entry"
# define EMSG_ENTRY_MISS	"Missing entry"
// "BA: Invalid entry"
# define EMSG_ENTRY_INVAL	"Invalid entry"

// RGB
// "F: "8523" out of range		... F 8523, 42, 42
# define EMSG_RGB_RANGE_OUT	"Out of range (0 ~ 255)"
// "F: "i" is not a number		...	F i, 42, 42
# define EMSG_RGB_NOT_NUM	"is not a number"
// "F: Missing RGB component B" ... F 10, 10, ,
# define EMSG_RGB_MISS		"Missing RGB component"
// "F: Empty RGB component"		... F
# define EMSG_RGB_EMPTY		"Empty RGB component"

// MAP
# define EMSG_MAP_CHAR			"MAP: Invalid characters found"
# define EMSG_MAP_PLAYER_MULTI	"MAP: Multiple player start positions"
# define EMSG_MAP_PLAYER_MISS	"MAP: Missing player start position"
# define EMSG_MAP_NOT_LAST		"MAP: Must be the last element"
# define EMSG_MAP_NOT_ENCLOSED	"MAP: Not enclosed by walls"
# define EMSG_MAP_TOO_LARGE		"MAP: Too large"


#endif
