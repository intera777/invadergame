#pragma once
#include"DxLib.h"
#include<vector>
using namespace std;

struct block {
	int x; //左上の座標
	int y;
	int hp;
	int state; //0なら非存在,1なら存在.
};

const int BLOCKNUM = 24; //ブロックの初期個数.
const int BLOCKSIZE = 20; //ブロックの一辺の長さ.

void draw_block(vector<block> v);
void check_block_bullet(vector<bullet>& bul, vector<block>& blo);
void block_initialize(vector<block>& blo);
void check_block_enemybullet(vector<bullet>& bul, vector<block>& blo);  //ブロックと敵の銃弾が触れていれば銃弾を削除.