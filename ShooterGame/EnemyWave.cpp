
/*
* �g�̓��������G�̏����֐�
*/

#include"Enemy.h"
#include"event.h"
#include"player.h"
#include<math.h>

////�����o���J�E���g���P�����₷
//int moveCounter = 0;

//�g�̓��������G�̉摜�ǂݍ��݊֐�
void LoadEnemyWave(Enemy& eWave)
{
	//���펞�摜�ǂݍ���
	eWave.object.graph = LoadGraph("img/enemyTako.png");

	//�_���[�W�摜�ǂݍ���
	eWave.damagedGraph = LoadGraph("img/enemyDamagedTako.png");
}

//�g�̓��������G�̏����֐�
void InitEnemyWave(Enemy& eWave)
{
	//�G�̕\���t���O���I�t�ɂ���
	eWave.graphFlag = true;

	//�G�̃_���[�W�t���O���I�t�ɂ���
	eWave.damagedFlag = false;

	//�G�̕��펞�摜�T�C�Y��ǂݍ���
	GetGraphSize(eWave.object.graph, &eWave.object.w, &eWave.object.h);

	//�G�̃_���[�W�摜�T�C�Y��ǂݍ���
	GetGraphSize(eWave.damagedGraph, &eWave.object.w, &eWave.object.h);

	//���W�A���ϐ����O�ɂ���
	eWave.rad = 0;

	////�G�̓����o���J�E���g���O�ɂ���
	//eWave.moveCounter = 0;

	//�G�̍��W�̏����ݒ�
	eWave.object.x = (SCREEN_W * 3) + (SCREEN_W / 2);
	eWave.object.y = SCREEN_H / 2;

}

//�g�̓��������G�̃A�b�v�f�[�g�֐�
void UpdateEnemyWave(Enemy& eWave, Player& player, int& remainP)
{
	//���펞�t���O���_���[�W�t���O���I���̎��Ɉړ��������s��
	if (eWave.graphFlag == true || eWave.damagedFlag == true)
	{
		//�G�̈ړ�����
		eWave.object.x -= ENEMY_WAVE_SPEED;

		eWave.rad += 0.03f;

		eWave.object.y += cos(eWave.rad) * ENEMY_WAVE_SPEED;

		//�g�̓�����Ƃ���G�{�̂Ǝ��@�{�̂̓����蔻��
		if (CollisionSmallRect(eWave.object, player.object, player.hitFlag))
		{
			//���@�̃_���[�W�t���O���I���ɂ���
			player.damagedFlag = true;

			//���@�̕��펞�\���t���O���I�t�ɂ���
			player.graphFlag = false;

			//���@�̎c�@�̏������s��
			UpdateRemainPlayer(remainP);

			//���@�̃_���[�W�J�E���g���O�ɂ���
			player.damagedCount = 0;

			//���@�̓����蔻��t���O���I�t�ɂ���
			player.hitFlag = false;

		}
	}
}

//�g�̓��������G�̕`��֐�
void DrawEnemyWave(Enemy& eWave)
{
	//�G�̕��펞�\���t���O���I���̎��Ƀ_���[�W�t���O���I�t�ɂ��ĕ��펞�摜��`�悷��
	if (eWave.graphFlag == true)
	{
		DrawGraph((int)eWave.object.x, (int)eWave.object.y, eWave.object.graph, true);
	}

	//�G�̃_���[�W�t���O���I���̎����펞�\���t���O���I�t�ɂ��ă_���[�W�\���J�E���g���P�����₷
	if (eWave.damagedFlag == true)
	{
		eWave.graphFlag = false;

		++eWave.drawDamagedCounter;

		DrawGraph((int)eWave.object.x, (int)eWave.object.y, eWave.damagedGraph, true);

		//�G�̃_���[�W�\���J�E���g��15�ȏ�̂Ƃ��_���[�W�t���O���I�t�ɂ��ă_���[�W�\���J�E���g���O�ɂ���
		if (eWave.drawDamagedCounter >= ENEMY_DRAW_DAMAGED_COUNTER)
		{
			eWave.graphFlag = false;
			eWave.damagedFlag = false;
			eWave.drawDamagedCounter = 0;
		}

	}
}