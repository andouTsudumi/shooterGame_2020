#pragma once
#include "common.h"

/*
* �X�R�A�̃v���g�^�C�v�錾
*/

//�X�R�A�̏����֐�
void InitScore(int& score);

//�X�R�A�̃A�b�v�f�[�g�֐�
void UpdateScore(int& score);

//�X�R�A�̕`��֐�
void DrawScore(const int score);

/*
* ���@�̎c�@�̃v���g�^�C�v�錾
*/

//���@�̎c�@�̏����֐�
void InitRemainPlayer(int& pRemain);

//���@�̎c�@�̃A�b�v�f�[�g�֐�
void UpdateRemainPlayer(int& pRemain);

//���@�̎c�@�̕`��֐�
void DrawRemainPlayer(const int pRemain);