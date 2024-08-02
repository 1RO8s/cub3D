#!/bin/bash

# Function to check if a package is installed
is_installed() {
    dpkg -s "$1" &> /dev/null
    return $?
}

# Function to install a package if not already installed
check_and_install() {
    if is_installed "$1"; then
        echo "$1 is already installed."
    else
        echo "Installing $1..."
        apt-get install -y "$1"
    fi
}

# Update package list
echo "Updating package list..."
apt-get update

# Install gcc
check_and_install "gcc"

# Install make
check_and_install "make"

# Install xorg
check_and_install "xorg"

# Install libxext-dev
check_and_install "libxext-dev"

# Install libbsd-dev
check_and_install "libbsd-dev"

echo "All specified packages are installed."
