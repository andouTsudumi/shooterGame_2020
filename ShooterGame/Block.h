#pragma once
#include"Common.h"

//�u���b�N�̍\���̕ϐ�
struct Block
{
	//���L�\���̌Ăяo��
	Object object;
};

/*
* �}�b�v�`�b�v�̃u���b�N�̊֐��̃v���g�^�C�v�錾
*/

//�u���b�N�̏����֐�
void InitBlock(Block* block, int blockNum, int graph, float x, float y, int w, int h);

//�u���b�N�̃A�b�v�f�[�g�֐�
void UpdateBlock(Block* block, Map& map, Enemy* eLeftWard, Enemy* eDownWard, Enemy* eWave, Player& player, int& remainP);

/*
* �u���b�N�̓����蔻��֐�
*/

////���@�{�̂ƃu���b�N�̓����蔻��֐�
//void HitPlayer(Block& block, Player& player, int& remainP);

//���@�̒e�ƃu���b�N�̓����蔻��֐�
void HitPlayerShot(Block& block, Player& player);

//�������̌Œ�G�̒e�ƃu���b�N�̓����蔻��֐�
void HitEnemyLeftWardShot(Block& block, Enemy& eLeftWard);

//�������̌Œ�G�̒e�ƃu���b�N�̓����蔻��֐�
void HitEnemyDownWardShot(Block& block, Enemy& eDownWard);

//�g�̓��������G�̒e�ƃu���b�N�̓����蔻��֐�
void HitEnemyWaveShot(Block& block, Enemy& eWave);

//�{�X�̒e�ƃu���b�N�̓����蔻��֐�
void HitBossShot(Block& block, Enemy& boss);

//�u���b�N�̕`��֐�
void DrawBlock(const Block* block, const int blockNum);