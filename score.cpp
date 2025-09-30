#pragma once
#include"invadergame2.h"

void draw_score(int s) {
	DrawFormatString(WIDTH - 180, 0, WHITE, "ÉXÉRÉA: %d", s);
}