#pragma once
#include "common.h"
#include"Shot.h"

//�G�̍\����
struct Enemy
{
	//���L�\���̌Ăяo��
	Object object;

	//���ꂼ��̒e�̍\���̂̌Ăяo��
	Shot leftShot[ENEMY_SHOT_MAX];
	Shot downShot[ENEMY_SHOT_MAX];
	Shot waveShot[ENEMY_SHOT_MAX];
	Shot bossFirstShot[ENEMY_SHOT_MAX];
	Shot bossSecondShot[ENEMY_SHOT_MAX];

	//�摜�ϐ�
	int damagedGraph;

	//�摜�\���t���O
	bool graphFlag, damagedFlag;

	//�G�̃_���[�W�摜�\���t���[���J�E���g
	int drawDamagedCounter;

	//�G�����ʂ܂ł̃_���[�W�t���[���J�E���g
	int DieCounter;

	//�g�̓��������G�̈ړ�radian
	float rad;
};

/*
* 
* �G�֐��Q�v���g�^�C�v�錾
* 
*/

/*
* �������̌Œ�G
*/

//�������̌Œ�G�̉摜�ǂݍ��݊֐�
void LoadEnemyLeftWard(Enemy& eLeftWard);

//�������̌Œ�G�̏����֐�
void InitEnemyLeftWard(Enemy& eLeftWard, int forSize);

//�������̌Œ�G�̃A�b�v�f�[�g�֐�
void UpdateEnemyLeftWard(Enemy& eLeftWard, Player& player, int& remainP);

//�������̌Œ�G�̕`��֐�
void DrawEnemyLeftWard(Enemy& eLeftWard);

/*
* �������̌Œ�G
*/

//�������̌Œ�G�̉摜�ǂݍ��݊֐�
void LoadEnemyDownWard(Enemy& eDownWard);

//�������̌Œ�G�̏����֐�
void InitEnemyDownWard(Enemy& eDownWard, int forSize);

//�������̌Œ�G�̃A�b�v�f�[�g�֐�
void UpdateEnemyDownWard(Enemy& eDownWard, Player& player, int& remainP);

//�������̌Œ�G�̕`��֐�
void DrawEnemyDownWard(Enemy& eDownWard);

/*
* �g�̓��������G
*/

//�g�̓��������G�̉摜�ǂݍ��݊֐�
void LoadEnemyWave(Enemy& eWave);

//�g�̓��������G�̏����֐�
void InitEnemyWave(Enemy& eWave);

//�g�̓��������G�̃A�b�v�f�[�g�֐�
void UpdateEnemyWave(Enemy& eWave, Player& player, int& remainP);

//�g�̓��������G�̕`��֐�
void DrawEnemyWave(Enemy& eWave);

/*
* ���X�{�X
*/

//���X�{�X�̉摜�ǂݍ��݊֐�
void LoadBoss(Enemy& boss);

//���X�{�X�̏����֐�
void InitBoss(Enemy& boss);

//���X�{�X�̃A�b�v�f�[�g�֐�
void UpdateBoss(Enemy& boss, Map& map, Player& player, int& remainP);

//���X�{�X�̕`��֐�
void DrawBoss(Enemy& boss);