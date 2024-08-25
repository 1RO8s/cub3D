#!/bin/bash

# List of submodule directories
DIRS=("libft" "ft_printf")

# Func to check if a directory is empty
is_empty() {
	[ -d "$1" ] && [ -z "$(ls -A "$1")" ]
}

# Initialize and Update git submodules
for dir in "${DIRS[@]}"; do
	if is_empty "$dir"; then
		echo "$dir directory is empty."
		git submodule update --init --recursive
		exit $?
	fi
done

echo "submodules contained" "${DIRS[0]}" "${DIRS[1]}"
