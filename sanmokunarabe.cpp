#include "DxLib.h"
#include<stdlib.h>
#include<time.h>

void gameMain();
int Cell[2][2];


// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	//ウィンドウモード
	ChangeWindowMode(true);
	SetWindowText("立体三目並べ");




	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	while (CheckHitKeyAll() == 0)
	{
		// メッセージループに代わる処理をする
		if (ProcessMessage() == -1)
		{
			break;        // エラーが起きたらループを抜ける
		}

	}


	gameMain();

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}



void gameMain() {
	

	//色指定
	int cr1;
	int cr2;
	int cr3;
	int cr4;
	int cr5;
	int cr6;
	int cr7;

	cr1 = GetColor(0, 0, 255);		//青
	cr2 = GetColor(0, 255, 0);		//緑
	cr3 = GetColor(100, 100, 100);	//黒
	cr4 = GetColor(255, 0, 0);		//赤
	cr5 = GetColor(0, 0, 255);		//青
	cr6 = GetColor(255, 255, 255);	//白
	cr7 = GetColor(255, 0, 0);		//赤


	//変数定義
	int nyuuryokuzumi[28] = { 0 };		//既に丸四角を入力しているか判定
	int turn = 0;						//丸、四角のターン判定
	int Masu;							//入力するマス目				
	int board[4][4][4] = { 0 };			//マス目
	int syouri = 0;						//勝敗が付いたかのフラグ
	int era = 0;						//エラー判定
	int GHandle;						//タイトル画像
	int GHandle2;						//丸の勝利画像
	int GHandle3;						//四角の勝利画像
	int GHandle4;						//引き分けの画像
	int x;								//列
	int y;								//行
	int z;								//高さ



	//ゲーム画面の描画
		//タイトル画像描画
	GHandle = LoadGraph("c:/画像/立体三目並べ.JPG");
	DrawExtendGraph(0, 0, 650, 450, GHandle, TRUE);
	WaitKey();								//キーを押して開始

		//バックスクリーンを描画
	DrawBox(0, 0, 640, 480, cr3, TRUE);

		//三目並べのスクリーンの描写
	DrawBox(50, 300, 200, 450, cr2, TRUE);	//下段
	DrawBox(250, 300, 400, 450, cr2, TRUE);	//中段
	DrawBox(450, 300, 600, 450, cr2, TRUE);	//上段

		//下段のマスの線の描画
	DrawLine(50,  350, 200, 350, cr3);    //横1
	DrawLine(50,  400, 200, 400, cr3);    //横2
	DrawLine(100, 300, 100, 450, cr3);    //縦1
	DrawLine(150, 300, 150, 450, cr3);    //縦2

		//中段のマスの線の描画
	DrawLine(250, 350, 400, 350, cr3);    //横1
	DrawLine(250, 400, 400, 400, cr3);    //横2
	DrawLine(300, 300, 300, 450, cr3);    //縦1
	DrawLine(350, 300, 350, 450, cr3);    //縦2

		//上段のマスの線の描画
	DrawLine(450, 350, 600, 350, cr3);    //横1
	DrawLine(450, 400, 600, 400, cr3);    //横2
	DrawLine(500, 300, 500, 450, cr3);    //縦1
	DrawLine(550, 300, 550, 450, cr3);    //縦2

		//下段中段上段の描画
	DrawString(105, 280 - 32, "1の段", cr6);
	DrawString(305, 280 - 32, "2の段", cr6);
	DrawString(505, 280 - 32, "3の段", cr6);

		//下段のマス番号の描画
	DrawString(75,  350 - 32, "1", cr6);
	DrawString(125, 350 - 32, "2", cr6);
	DrawString(175, 350 - 32, "3", cr6);
	DrawString(75,  400 - 32, "4", cr6);
	DrawString(125, 400 - 32, "5", cr6);
	DrawString(175, 400 - 32, "6", cr6);
	DrawString(75,  450 - 32, "7", cr6);
	DrawString(125, 450 - 32, "8", cr6);
	DrawString(175, 450 - 32, "9", cr6);

		//中段のマス番号の描画
	DrawString(270, 350 - 32, "10", cr6);
	DrawString(320, 350 - 32, "11", cr6);
	DrawString(370, 350 - 32, "12", cr6);
	DrawString(270, 400 - 32, "13", cr6);
	DrawString(370, 400 - 32, "15", cr6);
	DrawString(270, 450 - 32, "16", cr6);
	DrawString(320, 450 - 32, "17", cr6);
	DrawString(370, 450 - 32, "18", cr6);

		//上段のマス番号の描画
	DrawString(470, 350 - 32, "19", cr6);
	DrawString(520, 350 - 32, "20", cr6);
	DrawString(570, 350 - 32, "21", cr6);
	DrawString(470, 400 - 32, "22", cr6);
	DrawString(520, 400 - 32, "23", cr6);
	DrawString(570, 400 - 32, "24", cr6);
	DrawString(470, 450 - 32, "25", cr6);
	DrawString(520, 450 - 32, "26", cr6);
	DrawString(570, 450 - 32, "27", cr6);
	
		//二段目の真ん中の塗りつぶし
	DrawBox(300, 350, 350, 400, cr3, TRUE);



	//26マスすべて埋まるまで繰り返し
	for (turn = 0; turn < 26; turn++) {


		DrawBox(0, 20, 400, 100, cr3, TRUE);								//メッセージ消去（上書き）

		//エラーメッセージ
		if (era == 1) {
			DrawString(0, 40, "下の段から入力してください。", cr6);			//エラーメッセージ1表記
		}
		if (era == 2) {
			DrawString(0, 40, "そのマスは既に入力済みです。", cr6);			//エラーメッセージ2表記
		}

		//現在のターン表示
		if (turn % 2 == 0) {

			DrawString(0, 20, "現在のターンは丸です。", cr7);				//余りが0の場合

		}
		else {
			DrawString(0, 20, "現在のターンは四角です。", cr5);				//余りが0以外の場合
		}


		// マス入力指示
		DrawString(0, 0, "マスの数字を入力してください:", cr6);
		Masu = KeyInputNumber(250, 0, 27, 1, FALSE);



		//エラー判定
		nyuuryokuzumi[14] = 14;					//2段目中央
			//下から入力しているか判断
		if (Masu != 23) {						//Masuの値が23ではない場合（3段目の真ん中以外）
			if (Masu - 9 != nyuuryokuzumi[Masu - 9] && Masu > 9) {
				turn--;							//エラーメッセージ1としてコンティニュー
				era = 1;		
				continue;
			}
		}
		else if (nyuuryokuzumi[5] == 0) {		//Masuの値が23の場合（3段目の真ん中）
			turn--;								//エラーメッセージ1としてコンティニュー
			era = 1;					
			continue;
		}
		era = 0;								//エラーフラグの初期化


			//入力済みマス判別
		if (Masu == nyuuryokuzumi[Masu]) {		//Masuの値がnyuuryokuzumiに存在する場合
			turn--;								//エラーメッセージ2としてコンティニュー
			era = 2;
			continue;
		}

		else {									//Masuの値がnyuuryokuzumiに存在しない場合
			nyuuryokuzumi[Masu] = Masu;			//nyuuryokuzumiにMasuの値を代入
		}



		//丸四角の描画とマス目配列への代入
			//丸の描画 マス目配列への代入
		if (turn % 2 == 0) {					//余りが0の場合
			switch (Masu) {

				//１の段
			case 1:DrawCircle(75,  325, 25, cr4, TRUE); board[1][1][1] = 1; break;
			case 2:DrawCircle(125, 325, 25, cr4, TRUE); board[1][2][1] = 1; break;
			case 3:DrawCircle(175, 325, 25, cr4, TRUE); board[1][3][1] = 1; break;
			case 4:DrawCircle(75,  375, 25, cr4, TRUE); board[2][1][1] = 1; break;
			case 5:DrawCircle(125, 375, 25, cr4, TRUE); board[2][2][1] = 1; break;
			case 6:DrawCircle(175, 375, 25, cr4, TRUE); board[2][3][1] = 1; break;
			case 7:DrawCircle(75,  425, 25, cr4, TRUE); board[3][1][1] = 1; break;
			case 8:DrawCircle(125, 425, 25, cr4, TRUE); board[3][2][1] = 1; break;
			case 9:DrawCircle(175, 425, 25, cr4, TRUE); board[3][3][1] = 1; break;

				//２の段
			case 10:DrawCircle(275, 325, 25, cr4, TRUE); board[1][1][2] = 1; break;
			case 11:DrawCircle(325, 325, 25, cr4, TRUE); board[1][2][2] = 1; break;
			case 12:DrawCircle(375, 325, 25, cr4, TRUE); board[1][3][2] = 1; break;
			case 13:DrawCircle(275, 375, 25, cr4, TRUE); board[2][1][2] = 1; break;
			case 15:DrawCircle(375, 375, 25, cr4, TRUE); board[2][3][2] = 1; break;
			case 16:DrawCircle(275, 425, 25, cr4, TRUE); board[3][1][2] = 1; break;
			case 17:DrawCircle(325, 425, 25, cr4, TRUE); board[3][2][2] = 1; break;
			case 18:DrawCircle(375, 425, 25, cr4, TRUE); board[3][3][2] = 1; break;

				//３の段
			case 19:DrawCircle(475, 325, 25, cr4, TRUE); board[1][1][3] = 1; break;
			case 20:DrawCircle(525, 325, 25, cr4, TRUE); board[1][2][3] = 1; break;
			case 21:DrawCircle(575, 325, 25, cr4, TRUE); board[1][3][3] = 1; break;
			case 22:DrawCircle(475, 375, 25, cr4, TRUE); board[2][1][3] = 1; break;
			case 23:DrawCircle(525, 375, 25, cr4, TRUE); board[2][2][3] = 1; break;
			case 24:DrawCircle(575, 375, 25, cr4, TRUE); board[2][3][3] = 1; break;
			case 25:DrawCircle(475, 425, 25, cr4, TRUE); board[3][1][3] = 1; break;
			case 26:DrawCircle(525, 425, 25, cr4, TRUE); board[3][2][3] = 1; break;
			case 27:DrawCircle(575, 425, 25, cr4, TRUE); board[3][3][3] = 1; break;

			}

		}


			//四角の描画　マス目配列への代入
		else {									//余りが0では無い場合
			switch (Masu) {

				//１の段
			case 1:DrawBox(50,  300, 100, 350, cr5, TRUE); board[1][1][1] = 2; break;
			case 2:DrawBox(100, 300, 150, 350, cr5, TRUE); board[1][2][1] = 2; break;
			case 3:DrawBox(150, 300, 200, 350, cr5, TRUE); board[1][3][1] = 2; break;
			case 4:DrawBox(50,  350, 100, 400, cr5, TRUE); board[2][1][1] = 2; break;
			case 5:DrawBox(100, 350, 150, 400, cr5, TRUE); board[2][2][1] = 2; break;
			case 6:DrawBox(150, 350, 200, 400, cr5, TRUE); board[2][3][1] = 2; break;
			case 7:DrawBox(50,  400, 100, 450, cr5, TRUE); board[3][1][1] = 2; break;
			case 8:DrawBox(100, 400, 150, 450, cr5, TRUE); board[3][2][1] = 2; break;
			case 9:DrawBox(150, 400, 200, 450, cr5, TRUE); board[3][3][1] = 2; break;

				//２の段
			case 10:DrawBox(250, 300, 300, 350, cr5, TRUE); board[1][1][2] = 2; break;
			case 11:DrawBox(300, 300, 350, 350, cr5, TRUE); board[1][2][2] = 2; break;
			case 12:DrawBox(350, 300, 400, 350, cr5, TRUE); board[1][3][2] = 2; break;
			case 13:DrawBox(250, 350, 300, 400, cr5, TRUE); board[2][1][2] = 2; break;
			case 15:DrawBox(350, 350, 400, 400, cr5, TRUE); board[2][3][2] = 2; break;
			case 16:DrawBox(250, 400, 300, 450, cr5, TRUE); board[3][1][2] = 2; break;
			case 17:DrawBox(300, 400, 350, 450, cr5, TRUE); board[3][2][2] = 2; break;
			case 18:DrawBox(350, 400, 400, 450, cr5, TRUE); board[3][3][2] = 2; break;

				//３の段
			case 19:DrawBox(450, 300, 500, 350, cr5, TRUE); board[1][1][3] = 2; break;
			case 20:DrawBox(500, 300, 550, 350, cr5, TRUE); board[1][2][3] = 2; break;
			case 21:DrawBox(550, 300, 600, 350, cr5, TRUE); board[1][3][3] = 2; break;
			case 22:DrawBox(450, 350, 500, 400, cr5, TRUE); board[2][1][3] = 2; break;
			case 23:DrawBox(500, 350, 550, 400, cr5, TRUE); board[2][2][3] = 2; break;
			case 24:DrawBox(550, 350, 600, 400, cr5, TRUE); board[2][3][3] = 2; break;
			case 25:DrawBox(450, 400, 500, 450, cr5, TRUE); board[3][1][3] = 2; break;
			case 26:DrawBox(500, 400, 550, 450, cr5, TRUE); board[3][2][3] = 2; break;
			case 27:DrawBox(550, 400, 600, 450, cr5, TRUE); board[3][3][3] = 2; break;

			}

		}


		//各方向の勝敗判定
			//横方向の勝敗判定
		for (z = 1; z <= 3; z++) { // 高さ方向 (z軸) を1から3まで繰り返す
			for (x = 1; x <= 3; x++) { // 横方向 (x軸) を1から3まで繰り返す
				if (board[x][1][z] == board[x][2][z] && // y座標が1, 2の要素が同じか
					board[x][1][z] == board[x][3][z] && // y座標が1, 3の要素も同じか
					board[x][1][z] != 0) { // 0 (空マス) でないか
					syouri = 1;		//勝敗が決まったかのフラグ
				}

			}

		}


			//縦方向の勝敗判定
		for (z = 1; z <= 3; z++) { // 高さ方向 (z軸) を1から3まで繰り返す
			for (y = 1; y <= 3; y++) { // 縦方向 (y軸) を1から3まで繰り返す
				if (board[1][y][z] == board[2][y][z] && // y座標が1, 2の要素が同じか
					board[1][y][z] == board[3][y][z] && // y座標が1, 3の要素も同じか
					board[1][y][z] != 0) { // 0 (空マス) でないか
					syouri = 1;		//勝敗が決まったかのフラグ
				}

			}

		}


			//高さ方向の勝敗判定
		for (x = 1; x <= 3; x++) { // 横方向 (x軸) を1から3まで繰り返す
			for (y = 1; y <= 3; y++) { // 縦方向 (y軸) を1から3まで繰り返す
				if (board[x][y][1] == board[x][y][2] && // z座標が1, 2の要素が同じか
					board[x][y][1] == board[x][y][3] && // z座標が1, 3の要素も同じか
					board[x][y][1] != 0) { // 0 (空マス) でないか
					syouri = 1;		//勝敗が決まったかのフラグ
				}

			}

		}


			//斜め方向の勝敗判定
		for (z = 1; z <= 3; z++) { // 高さ方向 (z軸) を1から3まで繰り返す
			if (board[1][1][z] == board[2][2][z] &&	
				board[1][1][z] == board[3][3][z] &&
				board[1][1][z] != 0) { // 0 (空マス) でないか
				syouri = 1;
			}
			if (board[3][1][z] == board[2][2][z] &&
				board[3][1][z] == board[1][3][z] &&
				board[3][1][z] != 0) { // 0 (空マス) でないか
				syouri = 1;		//勝敗が決まったかのフラグ
			}

		}


			//縦方向の高さ斜めの勝敗判定
		for (y = 1; y <= 3; y++) { // 縦方向 (y軸) を1から3まで繰り返す
			if (board[1][y][1] == board[2][y][2] &&
				board[1][y][1] == board[3][y][3] &&
				board[1][y][1] != 0) { // 0 (空マス) でないか
				syouri = 1;
			}
			if (board[3][y][3] == board[2][y][2] &&
				board[3][y][3] == board[1][y][1] &&
				board[3][y][3] != 0) { // 0 (空マス) でないか
				syouri = 1;		//勝敗が決まったかのフラグ
			}


		}


			//横方向の高さ斜めの勝敗判定
		for (x = 1; x <= 3; x++) { // 横方向 (x軸) を1から3まで繰り返す
			if (board[x][1][1] == board[x][2][2] &&
				board[x][1][1] == board[x][3][3] &&
				board[x][1][1] != 0) { // 0 (空マス) でないか
				syouri = 1;
			}
			if (board[x][3][3] == board[x][2][2] &&
				board[x][3][3] == board[x][1][1] &&
				board[x][3][3] != 0) { // 0 (空マス) でないか
				syouri = 1;		//勝敗が決まったかのフラグ
			}

		}


		//どちらかが勝利した場合処理を抜ける
		if (syouri == 1) {
			break;
		}


	}



	//勝敗判定の描画
	DrawBox(0, 0, 300, 200, cr3, TRUE);
	if (syouri == 1) {

		//丸四角のどちらが勝利したか
			//丸勝利
		if (turn % 2 == 0) {										//余りが0の場合
			GHandle2 = LoadGraph("c:/画像/丸【赤】の勝ち.JPG");		//丸勝利画像描画
			DrawExtendGraph(0, 0, 650, 450, GHandle2, TRUE);

		}
			//四角勝利
		else {														//余りが0では無い場合
			GHandle3 = LoadGraph("c:/画像/四角【青】の勝ち.JPG");	//四角勝利画像描画
			DrawExtendGraph(0, 0, 650, 450, GHandle3, TRUE);
		}
	}

			//引き分け
	else if (turn <= 26) {											//turnが26以上の場合
		GHandle4 = LoadGraph("c:/画像/引き分けです.JPG");			//引き分け画像描画
		DrawExtendGraph(0, 0, 650, 450, GHandle4, TRUE);
	}

	WaitKey();														//キーを押して終了

}