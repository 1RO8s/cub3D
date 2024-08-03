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

exit $?


#	if [ $$? -eq 0 ]; then
#		echo "$(GREEN)Success : mlx library is exist.$(NC)";
#	else
#		echo "$(RED)Failed : mlx library setup_mlx.sh exection failed.$(NC)";
#		exit 1;
#	fi
# exit 1;  ... error ?
