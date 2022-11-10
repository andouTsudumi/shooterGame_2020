
/*
* �w�i�֐�����
*/

#include"backGround.h"

/*
* �w�i�P
*/

//�摜�ǂݍ��݊֐�
void LoadLeftBackGround(BackGround& back1)
{
	//�摜�ǂݍ���
	back1.object.graph = LoadGraph("img/bgsea.png");

}

//�����֐�
void InitLeftBackGround(BackGround& back1)
{
	//�w�i�����ʒu
	back1.object.x = 0;
	back1.object.y = 0;

	//�摜�̃T�C�Y��ǂݍ���
	GetGraphSize(back1.object.graph, &back1.object.w, &back1.object.h);

}

//�A�b�v�f�[�g�֐�
void UpdateLeftBackGround(BackGround& back1)
{
	//�w�i�̈ړ����x
	back1.object.x -= SCREEN_SPEEDX;

	//���X�N���[������
	if (back1.object.x <= -back1.object.w)
	{
		back1.object.x = (float)back1.object.w;
	}
}

//�`��֐�
void DrawLeftBackGround(const BackGround& back1)
{
	DrawGraph((int)back1.object.x, (int)back1.object.y, back1.object.graph, true);

}

/*
* �w�i�Q
*/

//�摜�ǂݍ��݊֐�
void LoadRightBackGround(BackGround& back2)
{
	//�摜�ǂݍ���
	back2.object.graph = LoadGraph("img/bgsea.png");

}

//�������֐�
void InitRightBackGround(BackGround& back2, BackGround& back1)
{
	//�����ʒu
	back2.object.x = (float)back1.object.w;
	back2.object.y = 0;

	//�摜�̃T�C�Y��ǂݍ���
	GetGraphSize(back2.object.graph, &back2.object.w, &back2.object.h);

}

//�A�b�v�f�[�g�֐�
void UpdateRightBackGround(BackGround& back2)
{
	//�ړ����x
	back2.object.x -= SCREEN_SPEEDX;

	//�S�Ă�
	if (back2.object.x <= -back2.object.w)
	{
		back2.object.x = (float)back2.object.w;
	}
}

//�`��֐�
void DrawRightBackGround(const BackGround& back2)
{
	DrawGraph((int)back2.object.x, (int)back2.object.y, back2.object.graph, true);
}

/*
* �Q�[���J�n��
*/

//�摜�ǂݍ��݊֐�
void LoadStart(DrawImg& start)
{
	start.object.graph = LoadGraph("img/start.png");
}

//�����֐�
void InitStart(DrawImg& start)
{
	start.object.x = 0;
	start.object.y = 0;
}

//�`��֐�
void DrawStart(const DrawImg& start)
{
	DrawGraph((int)start.object.x, (int)start.object.y, start.object.graph, true);
	DrawString(SCREEN_W / 3, SCREEN_H / 2, "�C�J�^�R��푈",GetColor(255, 255, 255));
}

/*
* �Q�[���N���A��
*/

//�摜�ǂݍ��݊֐�
void LoadClear(DrawImg& clear)
{
	clear.object.graph = LoadGraph("img/win.png");
}

//�����֐�
void InitClear(DrawImg& clear)
{
	clear.object.x = 0;
	clear.object.y = 0;
}

////�A�b�v���[�h�֐�
//void UpdataClear(ClearImg& clear)
//{
//}

//�`��֐�
void DrawClear(const DrawImg& clear)
{
	DrawGraph((int)clear.object.x, (int)clear.object.y, clear.object.graph, true);
	DrawString(340, 230, "GAME CLEAR", GetColor(255, 0, 0));
	DrawString(280, 360, "�X�y�[�X�L�[�Ń^�C�g����", GetColor(255, 255, 255));
}

/*
* �Q�[���I�[�o�[��
*/

//�摜�ǂݍ��݊֐�
void LoadLose(DrawImg& lose)
{
	lose.object.graph = LoadGraph("img/loose.png");
}

//�����֐�
void InitLose(DrawImg& lose)
{
	lose.object.x = 0;
	lose.object.y = 0;
}

////�A�b�v���[�h�֐�
//void UpdataLose(LoseImg& lose)
//{
//	
//}

//�`��֐�
void DrawLose(const DrawImg& lose)
{
	DrawGraph((int)lose.object.x, (int)lose.object.y, lose.object.graph, true);
	DrawString(340, 230, "GAME OVER", GetColor(255, 0, 0));
	DrawString(280, 360, "�X�y�[�X�L�[�Ń^�C�g����", GetColor(255, 255, 255));
}