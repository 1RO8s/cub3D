### how to convert the video to GIF
```sh
# Capture video file on mac
ffmpeg -i game_video.mov -vf "fps=10,scale=640:-1:flags=lanczos" -c:v gif output.gif
# Capture video file on Ubuntu
ffmpeg -i game_video.webm -vf "fps=10,scale=640:-1:flags=lanczos" -c:v gif output.gif
```

```sh
```

### what is ffmpeg
Play, record, convert, and stream audio and video
[https://ffmpeg.org/](https://ffmpeg.org/)
```sh
brew install ffmpeg
```
