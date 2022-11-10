#pragma once
#include "Common.h"

//�e�̍\����
struct Shot
{
	//���L�\���̌Ăяo��
	Object object;

	//�摜�\���t���O
	bool graphFlag;

	//�e���˃J�E���g
	int shotCounter;
};

/*
* ���@�̒e�̊֐��̃v���g�^�C�v�錾
*/

//���@�̒e�̉摜�ǂݍ��݊֐�
void LoadPlayerShot(Player& player);

//���@�̒e�̏����֐�
void InitPlayerShot(Player& player);

//���@�̒e�̃A�b�v�f�[�g�֐�
//�΍������̌Œ�G
void UpdatePlayerShotVSEnemyLeftWard(Player& player, Enemy* eLeftWard, int& score);

//�Ή������̌Œ�G
void UpdatePlayerShotVSEnemyDownWard(Player& player, Enemy* eDownWard, int& score);

//�Δg�̓��������G
void UpdatePlayerShotVSEnemyWave(Player& player, Enemy* eWave, int& score);

//�΃��X�{�X
void UpdatePlayerShotVSboss(Player& player, Enemy& boss, const Map& map, int& score);

//���@�̒e�̕`��֐�
void DrawPlayerShot(const Player& player);



/*
* �Œ�G�̒e�̊֐��̃v���g�^�C�v�錾
*/


////////������//////////

//�������̌Œ�G�̒e�̉摜�ǂݍ��݊֐�
void LoadEnemyLeftShot(Enemy& eLeftWard);

//�������̌Œ�G�̒e�̏����֐�
void InitEnemyLeftShot(Enemy& eLeftWard);

//�������̌Œ�G�̒e�̃A�b�v�f�[�g�֐�
void UpdateEnemyLeftShot(Enemy& eLeftWard, Player& player, int& remainP);

//�������̌Œ�G�̒e�̕`��֐�
void DrawEnemyLeftShot(const Enemy& eLeftWard);


//////////������//////////

//�������̌Œ�G�̒e�̉摜�ǂݍ��݊֐�
void LoadEnemyDownShot(Enemy& eDownWard);

//�������̌Œ�G�̒e�̊֏����֐�
void InitEnemyDownShot(Enemy& eDownWard);

//�������̌Œ�G�̒e�̃A�b�v�f�[�g�֐�
void UpdateEnemyDownShot(Enemy& eDownWard, Player& player, int& remainP);

//�������̌Œ�G�̒e�̕`��֐�
void DrawEnemyDownShot(const Enemy& eDownWard);



/*
* �g�̓��������G�̒e�̊֐�
*/

//�g�̓��������G�̒e�̉摜�ǂݍ��݊֐�
void LoadEnemyWaveShot(Enemy& eWave);

//�g�̓��������G�̒e�̏����֐�
void InitEnemyWaveShot(Enemy& eWave);

//�g�̓��������G�̒e�̃A�b�v�f�[�g�֐�
void UpdateEnemyWaveShot(Enemy& eWave, Player& player, int& remainP);

//�g�̓��������G�̒e�̕`��֐�
void DrawEnemyWaveShot(const Enemy& eWave);

/*
* ���X�{�X�̒e�̊֐�
*/

//���X�{�X�̒e�̉摜�ǂݍ��݊֐�
void LoadBossShot(Enemy& boss);

//���X�{�X�̒e�̏����֐�
void InitBossShot(Enemy& boss);

//���X�{�X�̒e�̃A�b�v�f�[�g�֐�
void UpdateBossShot(Enemy& boss, const Map& map, Player& player, int& remainP);

//���X�{�X�̒e�̕`��֐�
void DrawBossShot(const Enemy& boss);