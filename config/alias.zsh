export DISPLAY=':0.0 ./cub3D map/test.cub'
DEBUG_ON=0

alias run='./cub3D map/test.cub'
if [[ $DEBUG_ON -eq 1 ]]; then
	alias ctags_cub3d='ctags srcs/**/*.c lib/debug/srcs/*.c lib/libft/*.c includes/*.h lib/debug/includes/*.h'
	alias norm='norminette includes srcs lib/debug > norm_result.txt'
else
	alias ctags_cub3d='ctags srcs/**/*.c lib/libft/*.c includes/*.h'
	alias norm='norminette includes srcs > norm_result.txt'
fi
alias nm_cub='nm -u cub3D > nm_cub.txt'
alias nm_obj='nm -u objs/*.o > nm_obj.txt'
alias leak_check='valgrind --leak-check=full ./cub3D map/test.cub'
alias leak_check_all='valgrind --leak-check=full --show-leak-kinds=all ./cub3D map/test.cub'
root="$(pwd)"
alias tree="$root/config/tree.sh"
