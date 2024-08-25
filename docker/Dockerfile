FROM ubuntu:22.04

# Install necessary packages
RUN apt-get update && apt-get install -y \
	x11-apps \
	mesa-utils \
    xorg \
    openbox \
    libglu1-mesa-dev freeglut3-dev mesa-common-dev \
    libgl1-mesa-glx \
    libgl1-mesa-dri \
    mesa-utils \
    build-essential \
    cmake \
    git \
    wget
#RUN apt-get update && apt-get install -y \
#    x11-apps \
#    mesa-utils \
#    xorg \
#    openbox \
#    libglu1-mesa-dev freeglut3-dev mesa-common-dev

# Set the working directory
WORKDIR /workspace

# Copy your game source code into the container
#COPY .. /workspace

# Build your game (this will vary depending on your build system)
# RUN make

CMD ["bash"]
