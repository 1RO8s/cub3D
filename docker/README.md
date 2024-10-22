# How to use
```sh
# Build and Run container (Cub3D develop environment)
docker-compose up --build -d

# End using Cub3D container : stop & remove
docker-compose down

# Inter cub3D container
docker exec -it cub3d /bin/bash

# Execute XQuartz and Allow access to XQuartz
xhost + localhost

# Display on host-docker from cub3d-container
# Simple test ... call by cub3d-conatiner
xeyes

# Security Note : Revoke access to XQuartz
xhost - localhost
```
