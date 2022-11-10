#pragma once

#include "DxLib.h"

//���@�̃O���[�o���ϐ�
const float PLAYER_SPEED = 5.0f;							//���@�̈ړ����x
const int PLAYER_SHOT_MAX = 10;								//���@�̒e�̐�
const float PLAYER_SHOT_SPEED = 5.0f;						//���@�̒e�̑��x
const int PLAYER_SHOT_COUNTER = 30;							//�X�y�[�X�L�[�����������̎��@�̒e���o���܂ł̃t���[���J�E���g
const int PLAYER_DAMAGED_COUNTER = 100;						//���@�̃_���[�W���󂯂�܂ł̃t���[���J�E���g
const int PLAYER_DRAW_DAMAGED_COUNTER = 100;				//���@�̃_���[�W���󂯂��Ƃ��̉摜�\���t���[���J�E���g
const int PLAYER_REMAIN = 100;								//���@�̎c�@�̐�
const int PLAYER_SHORT_COLLISION = 16;						//���@�̓����蔻���Z�k����h�b�g�͈͐�


//�Œ�G�̃O���[�o���ϐ�
const int ENEMY_LEFT_WARD_MAX = 3;							//�������̓G�̐�
const int ENEMY_DOWN_WARD_MAX = 10;							//�������̓G�̐�
const int ENEMY_WAVE_MAX = 1;								//�g�̓���������G�̐�
const float ENEMY_FIX_SPEED = 2.5f;							//�Œ�G�̈ړ����x
const float ENEMY_WAVE_SPEED = 3.0f;						//�g�̓��������G�̈ړ����x
const int ENEMY_SHOT_MAX = 15;								//�G�̒e�̐�
const float ENEMY_SHOT_SPEEDX = 5.0f;						//�G�̒e��x���̑���
const float ENEMY_SHOT_SPEEDY = 5.0f;						//�G�̒e��y���̑���
const int ENEMY_SHOT_COUNTER = 80;							//�G���e�𔭎˂���܂ł̃t���[���J�E���g
const int ENEMY_WAVE_SHOT_COUNTER = 150;					//�g�̓��������G�̒e�����˂���܂ł̃t���[���J�E���g
const int ENEMY_DRAW_DAMAGED_COUNTER = 15;					//�G�̃_���[�W�摜�\���t���[���J�E���g��
const float ENEMY_RAD = 0.03f;								//�G�̃��W�A���̑�����
const int BOSS_DRAW_DAMAGED_COUNTER = 10;
const float BOSS_MOVE_SHOT = 5;

//�}�b�v�`�b�v�̃O���[�o���ϐ�
const int MAP_CHIP_SIZE = 32;								//�}�b�v�`�b�v�̃T�C�Y
const int MAP_WIDTH = 20;									//�}�b�v�`�b�v�̉���
const int MAP_HEIGHT = 15;									//�}�b�v�`�b�v�̏c��
const int MAP_SCROLL_MAX = 10;								//�}�b�v�`�b�v�̍ő�X�N���[����
const float MAP_SCREEN_SPEEDX = 2.0f;						//�}�b�v�`�b�v�̃X�N���[�����x
const int MAX_OVERLAP_CAPACITY = 10;						// �Ǎő�߂荞�ݗ�

//�X�N���[���̃O���[�o���ϐ�
const int SCREEN_W = MAP_CHIP_SIZE * MAP_WIDTH;				//�X�N���[���̕�
const int SCREEN_H = MAP_CHIP_SIZE * MAP_HEIGHT;			//�X�N���[���̍���
const float SCREEN_SPEEDX = 1.0f;							//�w�i�̈ړ����x


////�C�x���g�̃O���[�o���ϐ�
//const int CLEAR_SCORE = 20000;								//�X�R�A�̏��

enum { LOAD, INIT, TITLE, PLAY, OVER, CLEAR };				//�Q�[����ԊǗ�

//���L�ϐ��\����
struct Object
{
	//���W�ϐ�
	float x;
	float y;

	//�摜�T�C�Y�ϐ�
	int w, h;

	//�摜�ϐ�
	int graph;

	//�ړ����x�ϐ�
	float vx, vy;
};

//�v���g�^�C�v�錾�N���p�̃X�g���N�g
struct Player;
struct Enemy;
struct Shot;
struct Map;
struct Block;

//��{�ݒ�֐�
void Configuration();

//���@���󂯂�e�A�u���b�N�A�܂��͓G�{�̂Ƃ̓����蔻��֐�
bool CollisionSmallRect(const Object& player, const Object& rect2, const bool hitFlag);

//���@�ȊO���󂯂�e�A�u���b�N�A�܂��͓G�{�̂Ƃ̓����蔻��֐�
bool CollisionHitFlagRect(const Object& rect1, const Object& rect2, const bool hitFlag);

//�e���G�A�܂��̓u���b�N�ɓ����铖���蔻��
bool CollisionRect(const Object& rect1, const Object& rect2);
