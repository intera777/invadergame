#pragma once
#include"invadergame2.h"

void check_enemy(vector<enemy>& ene, vector<bullet>& bul, int& s) {
	for (int i = 0; i < ENEMYNUM; i++) {
		int x1 = ene.at(i).x, y1 = ene.at(i).y;
		for (int j = 0; j < MAXBULLETNUM; j++) {
			int x2 = bul.at(j).x, y2 = bul.at(j).y;
			if (((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= (ENEMY_RAD + BULLET_RAD) * (ENEMY_RAD + BULLET_RAD)) && ene.at(i).state == 1) {
				ene.at(i).state = 0;
				bul.at(j).state = 0;
				s += 50;
				break;
			}
		}
	}
}

void draw_enemy(vector<enemy>& ene) {
	for (int i = 0; i < ENEMYNUM; i++) {
		if (ene.at(i).state == 1) {
			DrawCircle(ene.at(i).x, ene.at(i).y, ENEMY_RAD, RED, TRUE);
		}
	}
}

void move_enemy(vector<enemy>& ene, int& t) {
	if (((0 <= t && t < ENEMY_MOVE_SPEED) || (ENEMY_MOVE_SPEED * 5 <= t && t < ENEMY_MOVE_SPEED * 6)) && t % ENEMY_MOVE_COOLTIME == 0) {

		for (int i = 0; i < ENEMYNUM; i++) {
			ene.at(i).x -= ENEMY_MOVE_COOLTIME;
		}
		if (t == ENEMY_MOVE_SPEED * 6 - 1) {
			t = 0;
		}
		else {
			t++;
		}
	}
	else if (((ENEMY_MOVE_SPEED <= t && t < ENEMY_MOVE_SPEED * 2) || (ENEMY_MOVE_SPEED * 4 <= t && t < ENEMY_MOVE_SPEED * 5)) && t % ENEMY_MOVE_COOLTIME == 0) {
		if (t % 2 == 0) {
			for (int i = 0; i < ENEMYNUM; i++) {
				ene.at(i).y += max(ENEMY_MOVE_COOLTIME / 2, 1);
			}
		}
		t++;
	}
	else if (ENEMY_MOVE_SPEED * 2 <= t && t < ENEMY_MOVE_SPEED * 4) {
		for (int i = 0; i < ENEMYNUM; i++) {
			ene.at(i).x += ENEMY_MOVE_COOLTIME;
		}
		t++;
	}
}
void enemy_initialize(vector<enemy>& ene) {
	for (int i = 0; i < ENEMYNUM; i++) {
		ene.at(i).x = 60 * (i % (ENEMYNUM / 2) + 1) + 80;
		ene.at(i).y = 20 + 40 * (i / (ENEMYNUM / 2));
		ene.at(i).state = 1;
	}
 }

void check_enemy_completed(int& scene, vector<enemy>& ene) {
	int flag = 1;
	for (int i = 0; i < ENEMYNUM; i++) {
		if (ene.at(i).state == 1) {
			flag = 0;
		}
	}
	if (flag == 1) {
		scene = CLEAR;
	}
}

void enemy_bullet_initialize(vector<bullet>& bul) {
	for (int i = 0; i < ENEMYNUM; i++) {
		bul.at(i).x = -100;
		bul.at(i).y = -100;
		bul.at(i).state = 0;
	}
}

void enemy_bullet_appear(vector<bullet>& bul, vector<enemy>& ene, int& cooltime) {
	if (cooltime < ENEMYBULLETCOOLTIME) {
		cooltime++;
	}
	else {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> distrib(0, ENEMYNUM / 2 - 1);
		int bx = distrib(gen);
		for (int i = 0; i < 2; i++) {
			int index = bx + (1 - i) * (ENEMYNUM / 2);
			if (ene.at(index).state == 1 && bul.at(index).state == 0) {
				bul.at(index).x = ene.at(index).x;
				bul.at(index).y = ene.at(index).y + 40;
				bul.at(index).state = 1;
				break;
			}
			if (ene.at(index).state == 1 && bul.at(index).state == 1) {
				break;
			}
		}
		cooltime = 0;
	}

}

void enemy_bullet_move(vector<bullet>& bul, int r, int move_vector) {
	for (int i = 0; i < ENEMYNUM; i++) {
		if (bul.at(i).state == 1) {
			bul.at(i).y += move_vector;
			if (bul.at(i).y > HEIGHT) {
				bul.at(i).x = -100; bul.at(i).y = -100; bul.at(i).state = 0;
			}
		}
	}
}

void enemy_draw_bullet(vector<bullet>& bul, int r, int color) {
	int img_bullet = LoadGraph("image/enemy_bullet.png");
	for (int i = 0; i < ENEMYNUM; i++) {
		if (bul.at(i).state == 1) {
			DrawGraph(bul.at(i).x - BULLET_RAD, bul.at(i).y - BULLET_RAD, img_bullet, FALSE);
		}
	}
}

int check_user_enemybullet(vector<bullet>& ene_bul, user user1) {
	int ux = user1.x, uy = user1.y;
	for (int i = 0; i < ENEMYNUM; i++) {
		if (ene_bul.at(i).state == 0) { continue; }
		int ex = ene_bul.at(i).x, ey = ene_bul.at(i).y;

		//ìGÇ™â°Ç…Ç¢ÇÈÇ∆Ç´.
		if (ey >= HEIGHT - 40 && ux - ex <= BULLET_RAD && ux - ex >= -(40 + BULLET_RAD)) {
			ene_bul.at(i).state = 0; return 1;
		} //ìGÇ™è„Ç…Ç¢ÇÈÇ∆Ç´;
		else if (ux - ex <= BULLET_RAD && ux - ex >= -(40 + BULLET_RAD) && uy - ey <= BULLET_RAD) {
			ene_bul.at(i).state = 0; return 1;
		}
		else
		{
			if ((ux - ex) * (ux - ex) + (uy - ey) * (uy - ey) <= BULLET_RAD * BULLET_RAD ||
				((ux + 40) - ex) * ((ux + 40) - ex) + (uy - ey) * (uy - ey) <= BULLET_RAD * BULLET_RAD) {
				ene_bul.at(i).state = 0; return 1;
			}
		}
	}
	return 0;
}

int check_user_enemy(vector<enemy>& ene, user& user1) {
	int ux = user1.x, uy = user1.y;
	for (int i = 0; i < ENEMYNUM; i++) {
		if (ene.at(i).state == 0) { continue; }
		int ex = ene.at(i).x, ey = ene.at(i).y;

		//ìGÇ™â°Ç…Ç¢ÇÈÇ∆Ç´.
		if (ey >= HEIGHT - 40 && ux - ex <= ENEMY_RAD && ux - ex >= -(40 + ENEMY_RAD)) {
			 return 1;
		} //ìGÇ™è„Ç…Ç¢ÇÈÇ∆Ç´;
		else if (ux - ex <= ENEMY_RAD && ux - ex >= -(40 + ENEMY_RAD) && uy - ey <= ENEMY_RAD) {
			return 1;
		}
		else
		{
			if ((ux - ex) * (ux - ex) + (uy - ey) * (uy - ey) <= ENEMY_RAD * ENEMY_RAD ||
				((ux + 40) - ex) * ((ux + 40) - ex) + (uy - ey) * (uy - ey) <= ENEMY_RAD * ENEMY_RAD) {
				return 1;
			}
		}
	}
	return 0;
}
