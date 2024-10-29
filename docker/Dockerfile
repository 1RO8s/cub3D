# Base Image
FROM ubuntu:22.04

# Set non-interactive mode for APT
ENV DEBIAN_FRONTEND=noninteractive

#RUN DEBIAN_PRIORITY=critical apt-get update && apt-get install -y \
#    keyboard-configuration \
#    console-setup \
#	&& apt-get clean

# Install necessary dependencies
RUN DEBIAN_PRIORITY=critical apt-get update && apt-get install -y \
	keyboard-configuration \
	console-setup \
	libx11-dev \
	libxext-dev \
	libxrandr-dev \
	libxinerama-dev \
	libxcursor-dev \
	libxi-dev \
	x11-apps \
	mesa-utils \
	xorg \
	openbox \
	libglu1-mesa-dev freeglut3-dev mesa-common-dev \
	libgl1-mesa-glx \
	libgl1-mesa-dri \
	mesa-utils \
	build-essential \
	zlib1g-dev \
	libbsd-dev \
	cmake \
	git \
	valgrind \
	wget \
	vim fzf \
	silversearcher-ag \
	&& apt-get clean

# Set the working directory
WORKDIR /workspace

# Set entry point to bash
CMD ["bash"]
