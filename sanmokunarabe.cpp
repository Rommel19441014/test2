#include "DxLib.h"
#include<stdlib.h>
#include<time.h>

void gameMain();
int Cell[2][2];


// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	//�E�B���h�E���[�h
	ChangeWindowMode(true);
	SetWindowText("���̎O�ڕ���");




	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	while (CheckHitKeyAll() == 0)
	{
		// ���b�Z�[�W���[�v�ɑ��鏈��������
		if (ProcessMessage() == -1)
		{
			break;        // �G���[���N�����烋�[�v�𔲂���
		}

	}


	gameMain();

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}



void gameMain() {
	

	//�F�w��
	int cr1;
	int cr2;
	int cr3;
	int cr4;
	int cr5;
	int cr6;
	int cr7;

	cr1 = GetColor(0, 0, 255);		//��
	cr2 = GetColor(0, 255, 0);		//��
	cr3 = GetColor(100, 100, 100);	//��
	cr4 = GetColor(255, 0, 0);		//��
	cr5 = GetColor(0, 0, 255);		//��
	cr6 = GetColor(255, 255, 255);	//��
	cr7 = GetColor(255, 0, 0);		//��


	//�ϐ���`
	int nyuuryokuzumi[28] = { 0 };		//���Ɋێl�p����͂��Ă��邩����
	int turn = 0;						//�ہA�l�p�̃^�[������
	int Masu;							//���͂���}�X��				
	int board[4][4][4] = { 0 };			//�}�X��
	int syouri = 0;						//���s���t�������̃t���O
	int era = 0;						//�G���[����
	int GHandle;						//�^�C�g���摜
	int GHandle2;						//�ۂ̏����摜
	int GHandle3;						//�l�p�̏����摜
	int GHandle4;						//���������̉摜
	int x;								//��
	int y;								//�s
	int z;								//����



	//�Q�[����ʂ̕`��
		//�^�C�g���摜�`��
	GHandle = LoadGraph("c:/�摜/���̎O�ڕ���.JPG");
	DrawExtendGraph(0, 0, 650, 450, GHandle, TRUE);
	WaitKey();								//�L�[�������ĊJ�n

		//�o�b�N�X�N���[����`��
	DrawBox(0, 0, 640, 480, cr3, TRUE);

		//�O�ڕ��ׂ̃X�N���[���̕`��
	DrawBox(50, 300, 200, 450, cr2, TRUE);	//���i
	DrawBox(250, 300, 400, 450, cr2, TRUE);	//���i
	DrawBox(450, 300, 600, 450, cr2, TRUE);	//��i

		//���i�̃}�X�̐��̕`��
	DrawLine(50,  350, 200, 350, cr3);    //��1
	DrawLine(50,  400, 200, 400, cr3);    //��2
	DrawLine(100, 300, 100, 450, cr3);    //�c1
	DrawLine(150, 300, 150, 450, cr3);    //�c2

		//���i�̃}�X�̐��̕`��
	DrawLine(250, 350, 400, 350, cr3);    //��1
	DrawLine(250, 400, 400, 400, cr3);    //��2
	DrawLine(300, 300, 300, 450, cr3);    //�c1
	DrawLine(350, 300, 350, 450, cr3);    //�c2

		//��i�̃}�X�̐��̕`��
	DrawLine(450, 350, 600, 350, cr3);    //��1
	DrawLine(450, 400, 600, 400, cr3);    //��2
	DrawLine(500, 300, 500, 450, cr3);    //�c1
	DrawLine(550, 300, 550, 450, cr3);    //�c2

		//���i���i��i�̕`��
	DrawString(105, 280 - 32, "1�̒i", cr6);
	DrawString(305, 280 - 32, "2�̒i", cr6);
	DrawString(505, 280 - 32, "3�̒i", cr6);

		//���i�̃}�X�ԍ��̕`��
	DrawString(75,  350 - 32, "1", cr6);
	DrawString(125, 350 - 32, "2", cr6);
	DrawString(175, 350 - 32, "3", cr6);
	DrawString(75,  400 - 32, "4", cr6);
	DrawString(125, 400 - 32, "5", cr6);
	DrawString(175, 400 - 32, "6", cr6);
	DrawString(75,  450 - 32, "7", cr6);
	DrawString(125, 450 - 32, "8", cr6);
	DrawString(175, 450 - 32, "9", cr6);

		//���i�̃}�X�ԍ��̕`��
	DrawString(270, 350 - 32, "10", cr6);
	DrawString(320, 350 - 32, "11", cr6);
	DrawString(370, 350 - 32, "12", cr6);
	DrawString(270, 400 - 32, "13", cr6);
	DrawString(370, 400 - 32, "15", cr6);
	DrawString(270, 450 - 32, "16", cr6);
	DrawString(320, 450 - 32, "17", cr6);
	DrawString(370, 450 - 32, "18", cr6);

		//��i�̃}�X�ԍ��̕`��
	DrawString(470, 350 - 32, "19", cr6);
	DrawString(520, 350 - 32, "20", cr6);
	DrawString(570, 350 - 32, "21", cr6);
	DrawString(470, 400 - 32, "22", cr6);
	DrawString(520, 400 - 32, "23", cr6);
	DrawString(570, 400 - 32, "24", cr6);
	DrawString(470, 450 - 32, "25", cr6);
	DrawString(520, 450 - 32, "26", cr6);
	DrawString(570, 450 - 32, "27", cr6);
	
		//��i�ڂ̐^�񒆂̓h��Ԃ�
	DrawBox(300, 350, 350, 400, cr3, TRUE);



	//26�}�X���ׂĖ��܂�܂ŌJ��Ԃ�
	for (turn = 0; turn < 26; turn++) {


		DrawBox(0, 20, 400, 100, cr3, TRUE);								//���b�Z�[�W�����i�㏑���j

		//�G���[���b�Z�[�W
		if (era == 1) {
			DrawString(0, 40, "���̒i������͂��Ă��������B", cr6);			//�G���[���b�Z�[�W1�\�L
		}
		if (era == 2) {
			DrawString(0, 40, "���̃}�X�͊��ɓ��͍ς݂ł��B", cr6);			//�G���[���b�Z�[�W2�\�L
		}

		//���݂̃^�[���\��
		if (turn % 2 == 0) {

			DrawString(0, 20, "���݂̃^�[���͊ۂł��B", cr7);				//�]�肪0�̏ꍇ

		}
		else {
			DrawString(0, 20, "���݂̃^�[���͎l�p�ł��B", cr5);				//�]�肪0�ȊO�̏ꍇ
		}


		// �}�X���͎w��
		DrawString(0, 0, "�}�X�̐�������͂��Ă�������:", cr6);
		Masu = KeyInputNumber(250, 0, 27, 1, FALSE);



		//�G���[����
		nyuuryokuzumi[14] = 14;					//2�i�ڒ���
			//��������͂��Ă��邩���f
		if (Masu != 23) {						//Masu�̒l��23�ł͂Ȃ��ꍇ�i3�i�ڂ̐^�񒆈ȊO�j
			if (Masu - 9 != nyuuryokuzumi[Masu - 9] && Masu > 9) {
				turn--;							//�G���[���b�Z�[�W1�Ƃ��ăR���e�B�j���[
				era = 1;		
				continue;
			}
		}
		else if (nyuuryokuzumi[5] == 0) {		//Masu�̒l��23�̏ꍇ�i3�i�ڂ̐^�񒆁j
			turn--;								//�G���[���b�Z�[�W1�Ƃ��ăR���e�B�j���[
			era = 1;					
			continue;
		}
		era = 0;								//�G���[�t���O�̏�����


			//���͍ς݃}�X����
		if (Masu == nyuuryokuzumi[Masu]) {		//Masu�̒l��nyuuryokuzumi�ɑ��݂���ꍇ
			turn--;								//�G���[���b�Z�[�W2�Ƃ��ăR���e�B�j���[
			era = 2;
			continue;
		}

		else {									//Masu�̒l��nyuuryokuzumi�ɑ��݂��Ȃ��ꍇ
			nyuuryokuzumi[Masu] = Masu;			//nyuuryokuzumi��Masu�̒l����
		}



		//�ێl�p�̕`��ƃ}�X�ڔz��ւ̑��
			//�ۂ̕`�� �}�X�ڔz��ւ̑��
		if (turn % 2 == 0) {					//�]�肪0�̏ꍇ
			switch (Masu) {

				//�P�̒i
			case 1:DrawCircle(75,  325, 25, cr4, TRUE); board[1][1][1] = 1; break;
			case 2:DrawCircle(125, 325, 25, cr4, TRUE); board[1][2][1] = 1; break;
			case 3:DrawCircle(175, 325, 25, cr4, TRUE); board[1][3][1] = 1; break;
			case 4:DrawCircle(75,  375, 25, cr4, TRUE); board[2][1][1] = 1; break;
			case 5:DrawCircle(125, 375, 25, cr4, TRUE); board[2][2][1] = 1; break;
			case 6:DrawCircle(175, 375, 25, cr4, TRUE); board[2][3][1] = 1; break;
			case 7:DrawCircle(75,  425, 25, cr4, TRUE); board[3][1][1] = 1; break;
			case 8:DrawCircle(125, 425, 25, cr4, TRUE); board[3][2][1] = 1; break;
			case 9:DrawCircle(175, 425, 25, cr4, TRUE); board[3][3][1] = 1; break;

				//�Q�̒i
			case 10:DrawCircle(275, 325, 25, cr4, TRUE); board[1][1][2] = 1; break;
			case 11:DrawCircle(325, 325, 25, cr4, TRUE); board[1][2][2] = 1; break;
			case 12:DrawCircle(375, 325, 25, cr4, TRUE); board[1][3][2] = 1; break;
			case 13:DrawCircle(275, 375, 25, cr4, TRUE); board[2][1][2] = 1; break;
			case 15:DrawCircle(375, 375, 25, cr4, TRUE); board[2][3][2] = 1; break;
			case 16:DrawCircle(275, 425, 25, cr4, TRUE); board[3][1][2] = 1; break;
			case 17:DrawCircle(325, 425, 25, cr4, TRUE); board[3][2][2] = 1; break;
			case 18:DrawCircle(375, 425, 25, cr4, TRUE); board[3][3][2] = 1; break;

				//�R�̒i
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


			//�l�p�̕`��@�}�X�ڔz��ւ̑��
		else {									//�]�肪0�ł͖����ꍇ
			switch (Masu) {

				//�P�̒i
			case 1:DrawBox(50,  300, 100, 350, cr5, TRUE); board[1][1][1] = 2; break;
			case 2:DrawBox(100, 300, 150, 350, cr5, TRUE); board[1][2][1] = 2; break;
			case 3:DrawBox(150, 300, 200, 350, cr5, TRUE); board[1][3][1] = 2; break;
			case 4:DrawBox(50,  350, 100, 400, cr5, TRUE); board[2][1][1] = 2; break;
			case 5:DrawBox(100, 350, 150, 400, cr5, TRUE); board[2][2][1] = 2; break;
			case 6:DrawBox(150, 350, 200, 400, cr5, TRUE); board[2][3][1] = 2; break;
			case 7:DrawBox(50,  400, 100, 450, cr5, TRUE); board[3][1][1] = 2; break;
			case 8:DrawBox(100, 400, 150, 450, cr5, TRUE); board[3][2][1] = 2; break;
			case 9:DrawBox(150, 400, 200, 450, cr5, TRUE); board[3][3][1] = 2; break;

				//�Q�̒i
			case 10:DrawBox(250, 300, 300, 350, cr5, TRUE); board[1][1][2] = 2; break;
			case 11:DrawBox(300, 300, 350, 350, cr5, TRUE); board[1][2][2] = 2; break;
			case 12:DrawBox(350, 300, 400, 350, cr5, TRUE); board[1][3][2] = 2; break;
			case 13:DrawBox(250, 350, 300, 400, cr5, TRUE); board[2][1][2] = 2; break;
			case 15:DrawBox(350, 350, 400, 400, cr5, TRUE); board[2][3][2] = 2; break;
			case 16:DrawBox(250, 400, 300, 450, cr5, TRUE); board[3][1][2] = 2; break;
			case 17:DrawBox(300, 400, 350, 450, cr5, TRUE); board[3][2][2] = 2; break;
			case 18:DrawBox(350, 400, 400, 450, cr5, TRUE); board[3][3][2] = 2; break;

				//�R�̒i
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


		//�e�����̏��s����
			//�������̏��s����
		for (z = 1; z <= 3; z++) { // �������� (z��) ��1����3�܂ŌJ��Ԃ�
			for (x = 1; x <= 3; x++) { // ������ (x��) ��1����3�܂ŌJ��Ԃ�
				if (board[x][1][z] == board[x][2][z] && // y���W��1, 2�̗v�f��������
					board[x][1][z] == board[x][3][z] && // y���W��1, 3�̗v�f��������
					board[x][1][z] != 0) { // 0 (��}�X) �łȂ���
					syouri = 1;		//���s�����܂������̃t���O
				}

			}

		}


			//�c�����̏��s����
		for (z = 1; z <= 3; z++) { // �������� (z��) ��1����3�܂ŌJ��Ԃ�
			for (y = 1; y <= 3; y++) { // �c���� (y��) ��1����3�܂ŌJ��Ԃ�
				if (board[1][y][z] == board[2][y][z] && // y���W��1, 2�̗v�f��������
					board[1][y][z] == board[3][y][z] && // y���W��1, 3�̗v�f��������
					board[1][y][z] != 0) { // 0 (��}�X) �łȂ���
					syouri = 1;		//���s�����܂������̃t���O
				}

			}

		}


			//���������̏��s����
		for (x = 1; x <= 3; x++) { // ������ (x��) ��1����3�܂ŌJ��Ԃ�
			for (y = 1; y <= 3; y++) { // �c���� (y��) ��1����3�܂ŌJ��Ԃ�
				if (board[x][y][1] == board[x][y][2] && // z���W��1, 2�̗v�f��������
					board[x][y][1] == board[x][y][3] && // z���W��1, 3�̗v�f��������
					board[x][y][1] != 0) { // 0 (��}�X) �łȂ���
					syouri = 1;		//���s�����܂������̃t���O
				}

			}

		}


			//�΂ߕ����̏��s����
		for (z = 1; z <= 3; z++) { // �������� (z��) ��1����3�܂ŌJ��Ԃ�
			if (board[1][1][z] == board[2][2][z] &&	
				board[1][1][z] == board[3][3][z] &&
				board[1][1][z] != 0) { // 0 (��}�X) �łȂ���
				syouri = 1;
			}
			if (board[3][1][z] == board[2][2][z] &&
				board[3][1][z] == board[1][3][z] &&
				board[3][1][z] != 0) { // 0 (��}�X) �łȂ���
				syouri = 1;		//���s�����܂������̃t���O
			}

		}


			//�c�����̍����΂߂̏��s����
		for (y = 1; y <= 3; y++) { // �c���� (y��) ��1����3�܂ŌJ��Ԃ�
			if (board[1][y][1] == board[2][y][2] &&
				board[1][y][1] == board[3][y][3] &&
				board[1][y][1] != 0) { // 0 (��}�X) �łȂ���
				syouri = 1;
			}
			if (board[3][y][3] == board[2][y][2] &&
				board[3][y][3] == board[1][y][1] &&
				board[3][y][3] != 0) { // 0 (��}�X) �łȂ���
				syouri = 1;		//���s�����܂������̃t���O
			}


		}


			//�������̍����΂߂̏��s����
		for (x = 1; x <= 3; x++) { // ������ (x��) ��1����3�܂ŌJ��Ԃ�
			if (board[x][1][1] == board[x][2][2] &&
				board[x][1][1] == board[x][3][3] &&
				board[x][1][1] != 0) { // 0 (��}�X) �łȂ���
				syouri = 1;
			}
			if (board[x][3][3] == board[x][2][2] &&
				board[x][3][3] == board[x][1][1] &&
				board[x][3][3] != 0) { // 0 (��}�X) �łȂ���
				syouri = 1;		//���s�����܂������̃t���O
			}

		}


		//�ǂ��炩�����������ꍇ�����𔲂���
		if (syouri == 1) {
			break;
		}


	}



	//���s����̕`��
	DrawBox(0, 0, 300, 200, cr3, TRUE);
	if (syouri == 1) {

		//�ێl�p�̂ǂ��炪����������
			//�ۏ���
		if (turn % 2 == 0) {										//�]�肪0�̏ꍇ
			GHandle2 = LoadGraph("c:/�摜/�ہy�ԁz�̏���.JPG");		//�ۏ����摜�`��
			DrawExtendGraph(0, 0, 650, 450, GHandle2, TRUE);

		}
			//�l�p����
		else {														//�]�肪0�ł͖����ꍇ
			GHandle3 = LoadGraph("c:/�摜/�l�p�y�z�̏���.JPG");	//�l�p�����摜�`��
			DrawExtendGraph(0, 0, 650, 450, GHandle3, TRUE);
		}
	}

			//��������
	else if (turn <= 26) {											//turn��26�ȏ�̏ꍇ
		GHandle4 = LoadGraph("c:/�摜/���������ł�.JPG");			//���������摜�`��
		DrawExtendGraph(0, 0, 650, 450, GHandle4, TRUE);
	}

	WaitKey();														//�L�[�������ďI��

}