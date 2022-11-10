
/*
* �������̌Œ�G�̏����֐�
*/

#include"Enemy.h"
#include"Player.h"
#include"Event.h"

//�������̌Œ�G�̉摜�ǂݍ��݊֐�
void LoadEnemyDownWard(Enemy& eDownWard)
{
	//�G�̉摜�ǂݍ���
	eDownWard.object.graph = LoadGraph("img/enemyIka.png");

	//�_���[�W�摜�ǂݍ���
	eDownWard.damagedGraph = LoadGraph("img/enemyDamagedIka.png");
}

//�������̌Œ�G�̏����֐�
void InitEnemyDownWard(Enemy& eDownWard, int forSize)
{
	//�G�̕���̕\���t���O���I���ɂ���
	eDownWard.graphFlag = true;

	//�G�̃_���[�W�t���O���I�t�ɂ���
	eDownWard.damagedFlag = false;

	//�_���[�W�摜�\���J�E���g
	eDownWard.drawDamagedCounter = 0;

	//�G�̉摜�T�C�Y��ǂݍ���
	GetGraphSize(eDownWard.object.graph, &eDownWard.object.w, &eDownWard.object.h);

	//�G�̃_���[�W�摜�T�C�Y��ǂݍ���
	GetGraphSize(eDownWard.damagedGraph, &eDownWard.object.w, &eDownWard.object.h);

	//�G�̍��W�̏����ݒ�
	eDownWard.object.x = (float)(SCREEN_W + 100 + eDownWard.object.w * forSize);
	eDownWard.object.y = 20.0f;
}

//�������̌Œ�G�̃A�b�v�f�[�g�֐�
void UpdateEnemyDownWard(Enemy& eDownWard, Player& player, int& remainP)
{
	//�G�̕\���t���O�܂��̓_���[�W�t���O���I���̎�
	if (eDownWard.graphFlag == true || eDownWard.damagedFlag == true)
	{
		//�ړ�����
		eDownWard.object.x -= MAP_SCREEN_SPEEDX;

		//�G�{�̂Ǝ��@�{�̂̓����蔻��
		if (CollisionSmallRect(eDownWard.object, player.object, player.hitFlag))
		{
			//���@�̃_���[�W�t���O���I���ɂ���
			player.damagedFlag = true;

			//���@�̕��펞�t���O���I�t�ɂ���
			player.graphFlag = false;

			//���@�̃_���[�W���󂯂�܂ł̃t���[���J�E���g���O�ɂ���
			player.damagedCount = 0;

			//���@�̓����蔻��t���O���I�t�ɂ���
			player.hitFlag = false;

			//���@�̎c�@�̃A�b�v�f�[�g�֐����Ăяo��
			UpdateRemainPlayer(remainP);
		}
	}
}

//�������̌Œ�G�̕`��֐�
void DrawEnemyDownWard(Enemy& eDownWard)
{
	//�G�̕\���t���O���I���̎����펞�摜��`�悷��
	if (eDownWard.graphFlag == true)
	{
		DrawGraph((int)eDownWard.object.x, (int)eDownWard.object.y, eDownWard.object.graph, true);
	}

	//�G�̃_���[�W�t���O���I���̎����펞�\���t���O���I�t�ɂ��ă_���[�W�\���J�E���g���P�����₷
	if (eDownWard.damagedFlag == true)
	{
		eDownWard.graphFlag = false;

		++eDownWard.drawDamagedCounter;

		//�_���[�W�摜��`�悷��
		DrawGraph((int)eDownWard.object.x, (int)eDownWard.object.y, eDownWard.damagedGraph, true);

		//�G�̃_���[�W�\���J�E���g���P�T�ȏ�̎��_���[�W�t���O���I�t�ɂ��ă_���[�W�\���J�E���g���O�ɂ���
		if (eDownWard.drawDamagedCounter >= ENEMY_DRAW_DAMAGED_COUNTER)
		{
			eDownWard.damagedFlag = false;
			eDownWard.drawDamagedCounter = 0;
		}
	}
}
