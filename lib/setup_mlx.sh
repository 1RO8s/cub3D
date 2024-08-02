#!/bin/bash

# Extract target
DST="minilibx-linux"
SRC="../resource/minilibx-linux.tgz"

if [ ! -d "${DST}" ]; then
	echo "Extract files from ${SRC}...";
	tar -xzf ${DST};
else
	echo "${DST} exists. No action needed.";
fi
