#pragma once
#include"DxLib.h"
#include<vector>

struct effect {
	int time;
	int x;
	int y;
};

void draw_explosion(vector<effect>& eff); //敵が倒された時のエフェクトを描画.
void effect_initialize(vector<effect>& eff, int n); //初期化.


