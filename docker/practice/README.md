# Docker practice

\page docker_xeyes Docker xeyes

```
docker build . -t xeyes

xhost -
xhost + localhost
docker run --rm -e DISPLAY=host.docker.internal:0 xeyes
```

# Reference
https://blog.aoirint.com/entry/2020/xquartz_docker/
