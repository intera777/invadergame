#include"invadergame2.h"

void game_start_initialize(user& user1, vector<bullet>& bul, vector<enemy>& ene, vector<bullet>& ene_bul, int& score,
	vector<block>& blo, vector<effect>& exp_eff) {
	user_initialize(user1);
	enemy_initialize(ene);
	enemy_bullet_initialize(ene_bul);
	block_initialize(blo);
	bullet_initialize(bul);
	effect_initialize(exp_eff, ENEMYNUM);
	score = 0;
}