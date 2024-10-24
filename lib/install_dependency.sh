#!/bin/bash

# Function to identify OS
detect_os() {
	OS=$(uname -s)

	if [ "$OS" = "Darwin" ]; then
		echo "macOS detected, exit from install_dependency.sh"
		exit
	elif [ "$OS" = "Linux" ]; then
		echo "Ubuntu detected, continuing..."
	else
		echo "Unsupported OS"
		exit 1
	fi
}

# Function to check if a package is installed
is_installed() {
    dpkg -s "$1" &> /dev/null
    return $?
}

# Flag to indicate if apt-get update has been run
updated=0

# Function to install a package if not already installed
check_and_install() {
    if is_installed "$1"; then
        echo "$1 is already installed."
    else
		# Update package list only once
		if [ $updated -eq 0 ]; then
			echo "Updating package list..."
			apt-get update
			updated=1
		fi
		# Install package
		echo "Installing $1..."
		apt-get install -y "$1"
	fi
}

# List of packages to check and install
packages=("gcc" "make" "xorg" "libxext-dev" "zlib1g-dev" "libbsd-dev")

# Call detect_os function
detect_os

# Loop through the list of packages and check/install each
for pkg in "${packages[@]}"; do
	check_and_install "$pkg"
done

echo "All specified packages are installed."
