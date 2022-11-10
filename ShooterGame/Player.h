#pragma once
#include "Common.h"
#include"Shot.h"

//���@�̍\���̕ϐ�
struct Player
{
	//���L�\���̌Ăяo��
	Object object;

	//�e�̍\���̌Ăяo��
	Shot playerShot[PLAYER_SHOT_MAX];

	//�摜�ϐ�
	int damagedGraph;

	//�摜�\���t���O
	bool damagedFlag;

	//�摜�\���̂��߂̃v���O�����f�o�b�N�p�ϐ�
	bool graphFlag;

	//�_���[�W�摜�\���t���[���J�E���g
	int drawDamagedCounter;

	//�_���[�W���󂯂�܂ł̃t���[���J�E���g
	int damagedCount;

	//�����蔻��t���O
	bool hitFlag;

	bool crushFlag;

	bool dieFlag;

};


/*
*���@�̊֐��Q�v���g�^�C�v�錾
*/

//���@�̉摜�ǂݍ��݊֐�
void LoadPlayer(Player& player);

//���@�̏����֐�
void InitPlayer(Player& player);

//���@�̃A�b�v�f�[�g�֐�
void UpdatePlayer(Player& player);

//���@�̕`��֐�
void DrawPlayer(Player& player);