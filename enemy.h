#pragma once
#include"DxLIb.h"
#include<vector>
using namespace std;

struct bullet;
struct user;
struct effect;

struct enemy {
	int x;
	int y;
	int state;
};


const int ENEMYNUM = 24;//“G‚Ì”.
const int ENEMY_RAD = 10; //“G‚Ì”¼Œa.
const int ENEMY_MOVE_SPEED = 40; //“G‚ª1‰ñ‚ÌˆÚ“®‚Å“®‚­‹——£(‰¡).
const int ENEMY_MOVE_COOLTIME = 1;//“G‚ª“®‚¢‚Ä‚©‚çÄ‚Ñ“®‚­‚Ü‚Å‚ÌƒN[ƒ‹ƒ^ƒCƒ€(ƒtƒŒ[ƒ€”).
const int ENEMYCYCLE = 150; //“G‚Ì“®‚«‚ÌüŠú;
const int ENEMYBULLETCOOLTIME = 5; //“G‚ÌUŒ‚‚ÌüŠú.

void check_enemy(vector<enemy>& ene, vector<bullet>& bul, vector<effect>& eff, int& s); //“G‚Ì¶€‚ğŠm”F.
void draw_enemy(vector<enemy>& ene); //“G‚ğ•`‰æ.
void move_enemy(vector<enemy>& ene, int& t); //“G‚ğ“®‚©‚·.
void enemy_initialize(vector<enemy>& ene);
void check_enemy_completed(int& scene, vector<enemy>& ene); //“G‚ª‘S•”“|‚³‚ê‚½‚©ƒ`ƒFƒbƒN.
void enemy_bullet_initialize(vector<bullet>& bul); //“G‚Ìe’e‚Ì‰Šú‰»
void enemy_bullet_appear(vector<bullet>& bul, vector<enemy>& ene, int& cooltime); //“G‚Ìe’e‚ğ¶¬
void enemy_bullet_move(vector<bullet>& bul, int r, int move_vector); //“G‚Ìe’e‚ğ“®‚©‚·.
void enemy_draw_bullet(vector<bullet>& bul, int r, int color); //“G‚Ìe’e‚ğ•`‰æ.
int check_user_enemy(vector<enemy>& ene, user& user1); //ƒ†[ƒU[‚Æ“G‚ª’¼ÚG‚ê‚Ä‚¢‚é‚©‚ğ”»’è.
int check_user_enemybullet(vector<bullet>& ene_bul, user user1); //ƒ†[ƒU[‚Æ“G‚Ìe’e‚ªG‚ê‚Ä‚¢‚é‚©‚ğ”»’è.