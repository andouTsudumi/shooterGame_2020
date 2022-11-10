
#include"event.h"

//�X�R�A�̏����֐�
void InitScore(int& score)
{
	score = 0;
}

//�X�R�A�̃A�b�v�f�[�g�֐�
void UpdateScore(int& score)
{
	score += 50;
}


//�X�R�A�̕`��֐�
void DrawScore(const int score)
{
	DrawFormatString(0, 0, GetColor(0, 0, 0), "SCORE : %d", score);
}

//���@�̎c�@�̏����֐�
void InitRemainPlayer(int& pRemain)
{
	pRemain = PLAYER_REMAIN;
}

//���@�̎c�@�̃A�b�v�f�[�g�֐�
void UpdateRemainPlayer(int& pRemain)
{
	pRemain--;
}

//���@�̎c�@�̕`��֐�
void DrawRemainPlayer(const int pRemain)
{
	DrawFormatString(SCREEN_W / 3, 0, GetColor(0, 0, 0), "�c�@�F%d", pRemain);
}