#include <stdio.h>
#include <math.h>

// 迷路のサイズ
#define MAP_WIDTH 10
#define MAP_HEIGHT 10

#define TILE_SIZE 1 // 1マスのサイズ
#define DEG_FOV 60 // カメラの視野角(度)

// 画面の横幅が何ピクセルか
#define SCREEN_WIDTH 20

// 迷路データ (1は壁、0は空間)
int worldMap[MAP_WIDTH][MAP_HEIGHT] = {
    {1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1}
};

typedef struct s_vector
{
	double	x;
	double	y;
}			t_vector;

// 交点が壁だったら1を返す
int hit_wall(double inter_x, double inter_y) {
	// マップの範囲外なら壁に当たったとみなす
	if (inter_x < 0 || inter_x >= MAP_WIDTH * TILE_SIZE || inter_y < 0 || inter_y >= MAP_HEIGHT * TILE_SIZE) {
		return 1;
	}
	int map_x = inter_x / TILE_SIZE;
	int map_y = inter_y / TILE_SIZE;
	if (worldMap[map_x][map_y] == 1) {
		return 1;
	}
	return 0;
}

// 水平方向の壁との交点座標を計算
t_vector calc_h_intersection(t_vector pos, t_vector dir,double r_angle) {
	// rayが水平方向(0度または180度)の場合
	if ( r_angle == 0 || r_angle == M_PI) {
		return (t_vector){pos.x, pos.y};
	} 
	// 交点から次の交点までのステップ
	// double  y_step = TILE_SIZE;
	double  y_step = (sin(r_angle) < 0) ? -TILE_SIZE : TILE_SIZE;
	double  x_step = y_step / tan(r_angle);
	// 最初の壁との交点
	// double inter_y = floor(pos.y/TILE_SIZE) * TILE_SIZE;
	double inter_y = floor(pos.y / TILE_SIZE) * TILE_SIZE + (sin(r_angle < 0) ? 0 : TILE_SIZE);
	double inter_x = pos.x + (inter_y - pos.y) / tan(r_angle);
	
	
	while(!hit_wall(inter_x, inter_y)) {
		inter_x += x_step;
		inter_y += y_step;
	}
	(void)dir;
	return (t_vector){inter_x, inter_y};
}

// 垂直方向の壁との交点座標を計算
t_vector calc_v_intersection(t_vector pos, t_vector dir,double r_angle) {
	// rayが垂直方向(90度または270度)の場合
    if (sin(r_angle) == 0) {
        return (t_vector){pos.x, pos.y};
    }
	// 交点から次の交点までのステップ
	// double  x_step = TILE_SIZE;
	double x_step = (dir.x < 0) ? -TILE_SIZE : TILE_SIZE;

	double  y_step = x_step * tan(r_angle);
	// 最初の壁との交点
	// double inter_x = floor(pos.x/TILE_SIZE) * TILE_SIZE;
	double inter_x = floor(pos.x / TILE_SIZE) * TILE_SIZE + ((dir.x < 0) ? 0 : TILE_SIZE);
	double inter_y = pos.y + (inter_x - pos.x) * tan(r_angle);
	
	while(!hit_wall(inter_x, inter_y)) {
		inter_x += x_step;
		inter_y += y_step;
	}
	return (t_vector){inter_x, inter_y};
}

// posからinterまでの距離を計算
double calc_distance(t_vector pos, t_vector inter) {
	return sqrt(pow(inter.x - pos.x, 2) + pow(inter.y - pos.y, 2));	
}

void performRaycasting(t_vector pos, t_vector dir) {
	int i;
	i = 0;
	double p_angle = atan2(dir.y, dir.x); // プレイヤーの角度(ラジアン)
	double FOV = (DEG_FOV * M_PI / 180)  ; // 視野角(ラジアン)
	double r_angle = p_angle - FOV/2; // 最初のrayの角度
  while(i < SCREEN_WIDTH){
		double distance = 0; // 壁までの距離
	  t_vector h_intersection = calc_h_intersection(pos,dir,r_angle); // 水平方向の壁との交点
		t_vector v_intersection = calc_v_intersection(pos,dir,r_angle); // 垂直方向の壁との交点

		// 水平方向の壁と垂直方向の壁の交点のうち、プレイヤーに近い方を選択
		if (calc_distance(pos, v_intersection) < calc_distance(pos, h_intersection)) {
			distance = calc_distance(pos, v_intersection);
		} else {
			distance = calc_distance(pos, h_intersection);
		}
		// 魚眼レンズ効果を補正
		double correct_distance = distance * cos(r_angle - p_angle);
		// デバッグ用
		printf("%2d: ",i);
		// printf("h_intersection: %f, %f,\t ", h_intersection.x, h_intersection.y);
		// printf("v_intersection: %f, %f,\t", v_intersection.x, v_intersection.y);
		printf("radian:%f, distance:%f, corrected:%f\n", r_angle,distance, correct_distance);
    i++;
		r_angle += FOV / SCREEN_WIDTH; // 次のrayの角度
	}
}

void print_settings(t_vector pos, t_vector dir) {
	printf("pos: x: %f, y: %f\n", pos.x, pos.y);
	printf("dir: x: %f, y: %f\n", dir.x, dir.y);
	printf("\n");
}

int main() {
	t_vector pos;
	t_vector dir;

	pos.x = 5.0;
	pos.y = 5.0;
	dir.x = -1.0;
	dir.y = 0.0;

	print_settings(pos, dir);
  performRaycasting(pos,dir);
  return 0;
}
