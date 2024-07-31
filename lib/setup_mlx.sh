DIR="minilibx-linux"
RESOURCE_MLX="../resource/minilibx-linux.tgz"

if [ ! -d "${DIR}" ]; then
	echo "Extract files from {RESOURCE_MLX}...";
	tar -xzf ${RESOURCE_MLX};
else
	echo "${DIR} exists. No action needed.";
fi
