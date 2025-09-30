#pragma once
#include"DxLib.h"
#include<vector>

struct bullet;
struct enemy;

struct user {
	int x;
	int y;
	int state; //0‚Ì‚Æ‚«‚Í€‚ñ‚Å‚¨‚è,1‚Ì‚Æ‚«‚Í¶‚«‚Ä‚¢‚é.
	int hp;
};

void draw_user(int x, int y);
void move_user(int& x, int& y);
void check_user_alive(vector<enemy>& ene, user& user1, vector<bullet>& ene_bul, int& scene);
void user_initialize(user& user1); //ƒ†[ƒU[î•ñ‚ğ‰Šú‰».
void draw_hp(user user1);