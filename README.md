# cub3D

### Clone main repository & submodules
```sh
# All repository
git clone --recursive git@github.com:1RO8s/cub3D.git

# or
git clone git@github.com:1RO8s/cub3D.git
git submodule update --init --recursive

# if Case of update libft
cd lib/libft
git fetch
git main
git ../..
```

### Build
```sh
make
```
output the below message
![build_image](docs/image/build_cub3D.png)

### Run
```sh
./cub3D map/test.map
# or
source config/alias.zsh
run
```
-> [Current Progress](docs/progress.md)

> memo : paste the completed cub3D game image here
>
> note : [image_note](docs/pdf/kamitsui_note.pdf)


### Directories and Files
```sh
tree -L 1 .
.
├── Makefile
├── README.md
├── cub3D
├── docker
├── docs
├── includes
├── lib
├── map
├── objs
├── resource
└── srcs
```

### Test
```sh
ln -sf $PWD/cub3D $PWD/test/parse_test/cub3D_parseTest/cub3D
cd test/parse_test/cub3D_parseTest
chmod +x parse.sh
./parse.sh
```

### About us
* [hnagasak](https://profile.intra.42.fr/users/hnagasak) : github[1R08s](https://github.com/1RO8s)
* [kamitsui](https://profile.intra.42.fr/users/kamitsui) : github[kamitsui](https://github.com/kamitsui)

Joined the 42Tokyo in the same year (2023.1)

Start this project at 2024.8
