
/*
* �Œ�G�̒e�̊֐�
*/

#include"Enemy.h"
#include"Event.h"
#include"Player.h"

//�������̌Œ�G�̒e�̉摜�ǂݍ��݊֐�
void LoadEnemyDownShot(Enemy& eDownWard)
{
	//�G�̒e�̉摜�ǂݍ���
	//���̒e
	eDownWard.downShot[0].object.graph = LoadGraph("img/DownTakoShot.png");
	//���̒e
	eDownWard.downShot[1].object.graph = LoadGraph("img/WhiteShot.png");

}

//�������̌Œ�G�̒e�̏����֐�
void InitEnemyDownShot(Enemy& eDownWard)
{

	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		//�G�̒e�̕\���t���O���I�t�ɂ���
		eDownWard.downShot[i].graphFlag = false;

		//�G�̒e�̉摜�T�C�Y��ǂݍ���
		//���̒e
		GetGraphSize(eDownWard.downShot[0].object.graph, &eDownWard.downShot[i].object.w, &eDownWard.downShot[i].object.h);
		//���̒e
		GetGraphSize(eDownWard.downShot[1].object.graph, &eDownWard.downShot[i].object.w, &eDownWard.downShot[i].object.h);

	}

	//�G�̒e���o���t���[���J�E���g�̏�����
	eDownWard.downShot[0].shotCounter = 0;

}

//�������̌Œ�G�̒e�̃A�b�v�f�[�g�֐�
void UpdateEnemyDownShot(Enemy& eDownWard, Player& player, int& remainP)
{
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		//window�̉�ʓ��ɓ����Ă�����e��\������
		if (eDownWard.object.x >= 0 && eDownWard.object.x <= SCREEN_W &&
			eDownWard.object.y >= 0 && eDownWard.object.y <= SCREEN_H)
		{
			//�G�̒e�̃J�E���g�𐔂���
			eDownWard.downShot[0].shotCounter++;

			//�G�̒e�̃J�E���g��5�t���[���ȏ�ɂȂ����珈�����s��
			if (eDownWard.downShot[0].shotCounter >= ENEMY_SHOT_COUNTER)
			{
				if (eDownWard.graphFlag == true)
				{
					//�\���t���O���I�t���������t���O���I���ɂ���
					if (eDownWard.downShot[i].graphFlag == false)
					{
						//�G�̒e�̍��W�̏����ݒ�
						eDownWard.downShot[i].object.x = (eDownWard.object.w - eDownWard.downShot[0].object.w) / 2 + eDownWard.object.x;
						eDownWard.downShot[i].object.y = eDownWard.object.h + eDownWard.object.y;

						eDownWard.downShot[i].graphFlag = true;

						//�G�̒e�̃t���[���J�E���g���O�ɂ���
						eDownWard.downShot[0].shotCounter = 0;

					}
				}
			}
		}

		//�\���t���O���I�����������̏���
		if (eDownWard.downShot[i].graphFlag == true)
		{
			//�G�̒e�̈ړ����x����
			eDownWard.downShot[i].object.x -= SCREEN_SPEEDX;
			eDownWard.downShot[i].object.y += ENEMY_SHOT_SPEEDY;

			//window�̍�������o���Ƃ��ɕ\���t���O���I�t�ɂ���
			if (eDownWard.downShot[i].object.y > SCREEN_H)
			{
				eDownWard.downShot[i].graphFlag = false;
			}

			//���@�̕\���t���O��true�̎�
			if (player.graphFlag == true)
			{
				//�G�̒e�Ǝ��@�̓����蔻�菈��
				if (CollisionSmallRect(eDownWard.downShot[i].object, player.object, remainP))
				{
					//�G�̒e�̕\���t���O���I�t�ɂ���
					eDownWard.downShot[i].graphFlag = false;

					//���@�̃_���[�W���󂯂Ă���t���O���I���ɂ���
					player.damagedFlag = true;

					//���@�̕\���t���O���I�t�ɂ���
					player.graphFlag = false;

					//���@�̎c�@�̏������s��
					UpdateRemainPlayer(remainP);
				}
			}
		}
	}
}

//�������̌Œ�G�̒e�̕`��֐�
void DrawEnemyDownShot(const Enemy& eDownWard)
{
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		//�G�̒e�̕\���t���O���I���̎��ɕ`�悷��
		if (eDownWard.downShot[i].graphFlag == true)
		{
			DrawGraph((int)eDownWard.downShot[i].object.x, (int)eDownWard.downShot[i].object.y, eDownWard.downShot[0].object.graph, true);
		}
	}
}