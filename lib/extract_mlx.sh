#!/bin/bash

# Check if the first argument is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <archive-file>"
    exit 1
fi

# Assign the first argument to SRC
SRC="$1"
SRC_DIR="../resource"

# Determine DST based on the value of SRC
if [ "$SRC" == "$SRC_DIR/minilibx-linux.tgz" ]; then
    DST="minilibx-linux"
elif [ "$SRC" == "$SRC_DIR/minilibx_mms_20200219_beta.tgz" ]; then
    DST="minilibx_mms_20200219"
else
    echo "Unknown archive file: $SRC"
    exit 1
fi

# Extract archive file of mlx library
if [ ! -d "${DST}" ]; then
	echo "Extract files from ${SRC}...";
	tar -xzf ${SRC};
else
	echo "${DST} exists. No action needed.";
fi

exit $?
