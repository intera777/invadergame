#pragma once
#include"DxLIb.h"
#include<vector>

struct user;
struct enemy;

struct bullet {
	int x;
	int y;
	int state;
	//0は待機状態,1はフィールド内に存在.	
};

const int MAXBULLETNUM = 10; //同時に存在できる弾の数の最大値.
const int BULLET_RAD = 10; //	弾の半径.
const int BULLET_COOLTIME = 15; //弾が発射されてから次の弾が発射可能になるまでの時間(フレーム数).

void bullet_appear(vector<bullet>& vec, int x, int y, int& cooltime);
//弾が発射できるかどうかを判断し,発射できるなら(x,y)の位置に弾を発射する.

void bullet_move(vector<bullet>& vec, int r, int color, int move_vector);
void draw_bullet(vector<bullet>& bul, int r, int color);
void bullet_initialize(vector<bullet>& bul); //銃弾の情報を初期化.
