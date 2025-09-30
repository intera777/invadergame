#pragma once
#include"DxLib.h"
#include<vector>
using namespace std;

struct bullet;
struct user;
struct enemy;
struct block;
struct effect;

void game_start_initialize(user& user1, vector<bullet>& bul, vector<enemy>& ene, vector<bullet>& ene_bul, int& score,
	vector<block>& blo, vector<effect>& exp_eff);