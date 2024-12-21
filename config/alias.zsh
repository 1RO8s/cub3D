alias run='./cub3D map/test.cub'
alias norm='norminette includes srcs lib/debug > norm_result.txt'
alias ctags_cub3d='ctags srcs/**/*.c lib/debug/srcs/*.c lib/libft/*.c includes/*.h lib/debug/includes/*.h'
alias leak_check='valgrind --leak-check=full ./cub3D map/test.cub'
alias leak_check_all='valgrind --leak-check=full --show-leak-kinds=all ./cub3D map/test.cub'
root="$(pwd)"
alias tree="$root/config/tree.sh"
