#include"invadergame2.h"
using namespace std;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR ldCmdLine, int nCmdShow)
{

	SetWindowText("インベーダーゲーム");
	SetGraphMode(WIDTH, HEIGHT, 32);
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1) return -1;
	SetBackgroundColor(0, 0, 0);
	SetDrawScreen(DX_SCREEN_BACK);

	user user1; //ユーザーの情報を持つ構造体.
	vector<bullet> bul(MAXBULLETNUM); //弾の情報を持つ構造体の配列.
	vector<bullet> ene_bul(ENEMYNUM); //敵が撃つ弾の情報を持つ構造体の配列.
	vector<enemy> ene(ENEMYNUM); //敵の情報を持つ構造体の配列.
	vector<block> blo(BLOCKNUM); //ブロックの情報を持つ構造体の配列.
	vector<effect> exp_eff(ENEMYNUM); //敵が倒された時のエフェクトの情報を持つ構造体.

	//銃弾関係の定数
	int bullet_cooltime = 0; //再び銃弾が発射可能になるまでの時間.

	//敵関係の定数
	int enemy_cycle = 0; //敵の動きが一周したらリセット.
	int enemy_bullet_cooltime = 0;

	int score = 0;

	int scene = TITLE;
	while (1) {
		ClearDrawScreen();

		if (scene == END) { break; }
		switch (scene) {

		case TITLE:
			SetFontSize(50);
			DrawString(200, HEIGHT / 2, "インベーダーゲーム(仮)", WHITE);
			SetFontSize(20);
			DrawString(250, HEIGHT * 2 / 3, "Sキーを押すとゲームを開始します", WHITE);
			DrawString(250, HEIGHT * 3 / 4, "右移動:L 左移動:J 弾発射: Z", WHITE);
			DrawString(700, HEIGHT * 5 / 6, "ver 0.0.2", WHITE);
			if (CheckHitKey(KEY_INPUT_S) == 1) { 
				scene = PLAY;
				game_start_initialize(user1, bul, ene, ene_bul, score, blo, exp_eff);
			}
			break;

		case PLAY:


			//ユーザーの移動.
			move_user(user1.x, user1.y);

			//ユーザーの描画
			draw_user(user1.x, user1.y);

			
			check_block_bullet(bul,blo);
			draw_block(blo);

			draw_explosion(exp_eff);


			//敵が全て倒されたかチェック.
			check_enemy_completed(scene, ene);

			//敵が倒されたかチェック
			check_enemy(ene, bul, exp_eff, score);

			//敵の移動
			move_enemy(ene, enemy_cycle);

			//敵の描画.
			draw_enemy(ene);

			//敵が倒された時のエフェクトの描画.
			draw_explosion(exp_eff);

			//銃弾の移動.
			bullet_move(bul, BULLET_RAD, WHITE, -20);

			draw_bullet(bul, BULLET_RAD, WHITE);
			//銃弾の生成.
			bullet_appear(bul, user1.x + 20, user1.y, bullet_cooltime);
			
			//敵の銃弾の生成.
			enemy_bullet_appear(ene_bul, ene, enemy_bullet_cooltime);

			//敵の銃弾の移動.
			enemy_bullet_move(ene_bul, BULLET_RAD, 20);

			//敵の銃弾の描画.
			enemy_draw_bullet(ene_bul, BULLET_RAD, ORANGE);

			check_block_enemybullet(ene_bul, blo);

			check_user_alive(ene, user1, ene_bul, scene);

			draw_score(score);

			draw_hp(user1);

			if (user1.state == 0) { scene = OVER; }
			break;

		case OVER:
			SetFontSize(50);
			DrawString(250, HEIGHT / 2, "ゲームオーバー", WHITE);
			SetFontSize(20);
			DrawString(300, HEIGHT * 2 / 3, "Sキーを押すとリスタートします", WHITE);
			DrawString(300, HEIGHT * 2 / 3 + 40, "Qキーを押すとゲームを終了します", WHITE);
			if (CheckHitKey(KEY_INPUT_S) == 1) { scene = TITLE;}
			else if (CheckHitKey(KEY_INPUT_Q) == 1) { scene = END; }
			break;

		case CLEAR:
			SetFontSize(50);
			DrawString(250, HEIGHT / 2, "ゲームクリア!", WHITE);
			SetFontSize(20);
			DrawString(300, HEIGHT * 2 / 3, "Sキーを押すとリスタートします", WHITE);
			DrawString(300, HEIGHT * 2 / 3 + 40, "Qキーを押すとゲームを終了します", WHITE);
			if (CheckHitKey(KEY_INPUT_S) == 1) { scene = TITLE; }
			else if (CheckHitKey(KEY_INPUT_Q) == 1) { scene = END; }
			break;
		}
		ScreenFlip();
		WaitTimer(33);
		if (ProcessMessage() == -1) break;
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break;
	}


	DxLib_End();
	return 0;
}