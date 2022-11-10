#pragma once
#include "Common.h"

struct BackGround
{
	//���L�\���̌Ăяo��
	Object object;
};

struct DrawImg
{
	//���L�\���̌Ăяo��
	Object object;
};


/*
* �w�i�P
*/

//�摜�ǂݍ��݊֐�
void LoadLeftBackGround(BackGround& back1);

//�����֐�
void InitLeftBackGround(BackGround& back1);

//�A�b�v�f�[�g�֐�
void UpdateLeftBackGround(BackGround& back1);

//�`��֐�
void DrawLeftBackGround(const BackGround& back1);

/*
* �w�i�Q
*/

//�摜�ǂݍ��݊֐�
void LoadRightBackGround(BackGround& back2);

//�����֐�
void InitRightBackGround(BackGround& back2, BackGround& back1);

//�A�b�v�f�[�g�֐�
void UpdateRightBackGround(BackGround& back2);

//�`��֐�
void DrawRightBackGround(const BackGround& back2);

/*
* �Q�[���J�n��
*/

//�摜�ǂݍ��݊֐�
void LoadStart(DrawImg& start);

//�����֐�
void InitStart(DrawImg& start);

//�`��֐�
void DrawStart(const DrawImg& start);

/*
* �Q�[���N���A��
*/

//�摜�ǂݍ��݊֐�
void LoadClear(DrawImg& clear);

//�����֐�
void InitClear(DrawImg& clear);

//�`��֐�
void DrawClear(const DrawImg& clear);

/*
* �Q�[���I�[�o�[��
*/

//�摜�ǂݍ��݊֐�
void LoadLose(DrawImg& lose);

//�����֐�
void InitLose(DrawImg& lose);

//�`��֐�
void DrawLose(const DrawImg& lose);