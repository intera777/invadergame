#pragma once
#include"invadergame2.h"

void draw_block(vector<block> v) {
	int img_block = LoadGraph("image/block.png");
	for (int i = 0; i < BLOCKNUM; i++) {
		int x = v.at(i).x, y = v.at(i).y, state = v.at(i).state;
		if (state == 1) {
			DrawGraph(x, y, img_block, FALSE);
		}
	}
}

void check_block_bullet(vector<bullet>& bul, vector<block>& blo) {
	for (int i = 0; i < BLOCKNUM; i++) {
		int block_x = blo.at(i).x, block_y = blo.at(i).y;
		for (int j = 0; j < MAXBULLETNUM; j++) {
			int bullet_x = bul.at(j).x, bullet_y = bul.at(j).y;
			if (block_x <= bullet_x && bullet_x < block_x + BLOCKSIZE && bullet_y-block_y<=BLOCKSIZE+BULLET_RAD ) {
				bul.at(j).state = 0;
			}
		}
	}
}

void check_block_enemybullet(vector<bullet>& bul, vector<block>& blo) {
	for (int i = 0; i < BLOCKNUM; i++) {
		int block_x = blo.at(i).x, block_y = blo.at(i).y;
		for (int j = 0; j < ENEMYNUM; j++) {
			int bullet_x = bul.at(j).x, bullet_y = bul.at(j).y;
			if (block_x <= bullet_x && bullet_x < block_x + BLOCKSIZE && block_y <= bullet_y + BULLET_RAD) {
				bul.at(j).state = 0;
			}
		}
	}
}

void block_initialize(vector<block>& blo) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 4; k++) {
				blo.at(8 * i + 4 * j + k).x = 320 * (i + 1) + k * BLOCKSIZE-200;
				blo.at(8 * i + 4 * j + k).y = HEIGHT - 140 + BLOCKSIZE * j;
				blo.at(8 * i + 4 * j + k).hp = 1;
				blo.at(8 * i + 4 * j + k).state = 1;
			}
		}
	}
}



