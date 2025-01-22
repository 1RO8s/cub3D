# ffmpeg {#ffmpeg}

Convert media file formats.

- ex : .gif -> .webm or .mov

### How to use
```sh
# Capture video file on mac
ffmpeg -i game_video.mov -vf "fps=10,scale=640:-1:flags=lanczos" -c:v gif output.gif
# Capture video file on Ubuntu
ffmpeg -i game_video.webm -vf "fps=10,scale=640:-1:flags=lanczos" -c:v gif output.gif
```

### what is ffmpeg
Play, record, convert, and stream audio and video

[https://ffmpeg.org/](https://ffmpeg.org/)
```sh
brew install ffmpeg
```
