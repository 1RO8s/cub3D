#!/bin/bash

# Check if the input file is provided
if [ -z "$1" ]; then
  echo "Usage: $0 <input_video_file>"
  exit 1
fi

# Get the input file name and extension
input_file="$1"

# Remove the file extension and append .gif to create the output file name
output_file="${input_file%.*}.gif"

# Run ffmpeg to convert the input file to GIF
ffmpeg -i "$input_file" -vf "fps=10,scale=640:-1:flags=lanczos" -c:v gif "$output_file"

echo "Conversion complete: $output_file"
