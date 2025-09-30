#pragma once
#include"DxLIb.h"
#include<vector>



struct enemy;
struct user;
struct bullet;




const int WIDTH = 960;  //âÊñ ÇÃïù
const int HEIGHT = 640; //âÊñ ÇÃècïù

const int BLUE = GetColor(0, 0, 255);
const int WHITE = GetColor(255, 255, 255);
const int RED = GetColor(255, 0, 0);
const int ORANGE = GetColor(255, 165, 0);
const int FLAMERATE = 33;


using std::vector;

enum { TITLE, PLAY, MENU, CLEAR, OVER, END };

