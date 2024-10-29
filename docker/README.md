### How to use
```sh
# Build and Run container (Cub3D develop environment)
docker-compose up --build -d

# End using Cub3D container : stop & remove
docker-compose down

# Inter cub3D container
docker-compose exec cub3d /bin/bash
# or
docker exec -it cub3d /bin/bash

# Execute XQuartz and Allow access to XQuartz
xhost + localhost

# Display on host-docker from cub3d-container
# Simple test ... call by cub3d-conatiner
xeyes

# Security Note : Revoke access to XQuartz
xhost - localhost
```

### other memo
```
# Storage driver is currently using
docker info

# Show the disk space used
docker system df

# Remove unused objects
docker system prune # All Object : container, network, image, volume with option
docker image prune  # Only Image
docker volume prune # Only Volume

# BuiltKit for speedy building
export DOCKER_BUILDKIT=1
docker-compose build
# Local build cache
docker build --cache-form=my-cached-image .
# Paralel build in multiple service
docker-compose build --parallel
# Only specific servife
docker-compose build service_name
```

### Built Check
[docker build check](https://www.docker.com/ja-jp/blog/introducing-docker-build-checks/)
