
/*
* �������̌Œ�G�̏����֐�
*/

#include"Enemy.h"
#include"Player.h"
#include"Event.h"

//�������̌Œ�G�̉摜�ǂݍ��݊֐�
void LoadEnemyLeftWard(Enemy& eLeftWard)
{
	//�G�̉摜�ǂݍ���
	eLeftWard.object.graph = LoadGraph("img/enemyTako.png");

	//�G�̃_���[�W�摜�ǂݍ���
	eLeftWard.damagedGraph = LoadGraph("img/enemyDamagedTako.png");

}

//�������̌Œ�G�̏����֐�
void InitEnemyLeftWard(Enemy& eLeftWard, int forSize)
{
	//�G�̕���̕\���t���O���I�t�ɂ���
	eLeftWard.graphFlag = true;

	//�G�̃_���[�W�t���O���I�t�ɂ���
	eLeftWard.damagedFlag = false;

	//�_���[�W�摜�\���J�E���g
	eLeftWard.drawDamagedCounter = 0;

	//�G�̉摜�T�C�Y��ǂݍ���
	GetGraphSize(eLeftWard.object.graph, &eLeftWard.object.w, &eLeftWard.object.h);

	//�G�̃_���[�W�摜�T�C�Y��ǂݍ���
	GetGraphSize(eLeftWard.damagedGraph, &eLeftWard.object.w, &eLeftWard.object.h);

	//�G�̍��W�̏����ݒ�
	eLeftWard.object.x = SCREEN_W;
	eLeftWard.object.y = (float)(200 + eLeftWard.object.h * forSize);
}


//�������̌Œ�G�̃A�b�v�f�[�g�֐�
void UpdateEnemyLeftWard(Enemy& eLeftWard, Player& player, int& remainP)
{
	//�G�̕\���t���O�܂��̓_���[�W�t���O���I���̎�
	if (eLeftWard.graphFlag == true || eLeftWard.damagedFlag == true)
	{
		//�ړ�����
		eLeftWard.object.x -= MAP_SCREEN_SPEEDX;

		//�G�{�̂Ǝ��@�{�̂̓����蔻��
		if (CollisionSmallRect(eLeftWard.object, player.object, player.hitFlag))
		{
			//���@�̃_���[�W�t���O���I���ɂ���
			player.damagedFlag = true;

			//���@�̕��펞�t���O���I�t�ɂ���
			player.graphFlag = false;

			//���@�̎c�@�̏������s��
			UpdateRemainPlayer(remainP);

			//���@�̃_���[�W���󂯂�܂ł̃t���[���J�E���g���O�ɂ���
			player.damagedCount = 0;

			//���@�̓����蔻��t���O���I�t�ɂ���
			player.hitFlag = false;
		}
	}
}


//�������̌Œ�G�̕`��֐�
void DrawEnemyLeftWard(Enemy& eLeftWard)
{
	//�G�̕\���t���O���I���̎��摜��`�悷��
	if (eLeftWard.graphFlag == true)
	{
		DrawGraph((int)eLeftWard.object.x, (int)eLeftWard.object.y, eLeftWard.object.graph, true);
	}

	//�_���[�W���󂯂��Ƃ���DamageFlag���I���ɂ��ĕ��ʂ̕\���t���O���I�t�ɂ��ă_���[�W�\���J�E���g�𐔂���
	if (eLeftWard.damagedFlag == true)
	{
		eLeftWard.graphFlag = false;

		++eLeftWard.drawDamagedCounter;

		//�_���[�W�摜��`�悷��
		DrawGraph((int)eLeftWard.object.x, (int)eLeftWard.object.y, eLeftWard.damagedGraph, true);

		//�G�̃_���[�W�J�E���g���P�T�ȏ�̎��_���[�W�t���O���I�t�ɂ��ă_���[�W�J�E���g���O�ɂ���
		if (eLeftWard.drawDamagedCounter >= ENEMY_DRAW_DAMAGED_COUNTER)
		{
			eLeftWard.graphFlag = false;
			eLeftWard.damagedFlag = false;
			eLeftWard.drawDamagedCounter = 0;
		}
	}
}
