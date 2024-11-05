#ifndef ERROR_CUB3D_H
# define ERROR_CUB3D_H


/**
 * @brief error message
 */
# define ERR_PROMPT "Error: "

// parse_tex.c
# define EMSG_XPM_FILE "texture file"
# define EMSG_IMG_DATA_ADDR "failure mlx_get_data_addr function"


// Entry
// "Duplicate entry : F"
# define EMSG_ENTRY_DUP		"Duplicate entry"
// "Missing entry : F"
# define EMSG_ENTRY_MISS	"Missing entry"
// Invalid entry: BA
# define EMSG_ENTRY_INVAL	"Invalid entry"

// RGB
// "F: "8523" out of range
# define EMSG_RGB_RANGE_OUT	"Out of range (0 ~ 255)"
// "F: "i" is not a number
# define EMSG_RGB_NOT_NUM	"is not a number"
// "F: Missing RGB component B"
# define EMSG_RGB_MISS		"Missing RGB component"
// "F: Empty RGB component"
# define EMSG_RGB_EMPTY		"Empty RGB component"

// MAP
# define EMSG_MAP_CHAR			"MAP: Invalid characters found"
# define EMSG_MAP_PLAYER_MULTI	"MAP: Multiple player start positions"
# define EMSG_MAP_PLAYER_MISS	"MAP: Missing player start position"
# define EMSG_MAP_NOT_LAST		"MAP: Must be the last element"
# define EMSG_MAP_NOT_ENCLOSED	"MAP: Not enclosed by walls"


#endif
