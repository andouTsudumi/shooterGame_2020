#pragma once

#include"BackGround.h"
#include"Player.h"
#include"Enemy.h"
#include"Event.h"
#include"Map.h"

/*
* �e�\���̕ϐ���`
*/

//���@�ϐ���`
Player player;

//�������̌Œ�G�ϐ���`
Enemy eLeftWard[ENEMY_LEFT_WARD_MAX];

//�������̌Œ�G�ϐ���`
Enemy eDownWard[ENEMY_DOWN_WARD_MAX];

//�g�̓��������G�ϐ���`
Enemy eWave[ENEMY_WAVE_MAX];

Enemy boss;

//�w�i�ϐ���`
BackGround leftBack;
BackGround rightBack;

Map map;
Block block[1500];

//���ꂼ��̃Q�[���X�e�[�^�X�ϐ���`
DrawImg startImg;
DrawImg loseImg;
DrawImg clearImg;

//�C�x���g
//�X�R�A�ϐ���`
int score = 0;

//���@�̎c�@�ϐ���`
int remainPlayer = PLAYER_REMAIN;

//�Q�[���X�e�[�^�X�ێ��ϐ���`
int gameStatus = LOAD;

