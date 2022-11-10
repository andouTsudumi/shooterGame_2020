
/*
* �Œ�G�̒e�̏����֐�
*/

#include"Enemy.h"
#include"Player.h"
#include"Event.h"

//�������̌Œ�G�̒e�̉摜�ǂݍ��݊֐�
void LoadEnemyLeftShot(Enemy& eLeftWard)
{
	//�G�̒e�̉摜�ǂݍ���
	eLeftWard.leftShot[0].object.graph = LoadGraph("img/LeftTakoShot.png");
}

//�������̌Œ�G�̒e�̏����֐�
void InitEnemyLeftShot(Enemy& eLeftWard)
{
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		//�G�̒e�̕\���t���O���I�t�ɂ���
		eLeftWard.leftShot[i].graphFlag = false;

		//�G�̒e�̉摜�T�C�Y��ǂݍ���
		GetGraphSize(eLeftWard.leftShot[0].object.graph, &eLeftWard.leftShot[i].object.w, &eLeftWard.leftShot[i].object.h);
	}

	//�G�̒e���o���t���[���J�E���g�̏�����
	eLeftWard.leftShot[0].shotCounter = 0;
}


//�������̌Œ�G�̒e�̃A�b�v�f�[�g�֐�
void UpdateEnemyLeftShot(Enemy& eLeftWard, Player& player, int& remainP)
{
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		//window�̉�ʓ��ɓ����Ă�����e��\������
		if (eLeftWard.object.x >= 0 && eLeftWard.object.x <= SCREEN_W &&
			eLeftWard.object.y >= 0 && eLeftWard.object.y <= SCREEN_H)
		{
			//�G�̒e�̃J�E���g���P�����₷
			eLeftWard.leftShot[0].shotCounter++;

			//�G�̒e�̃J�E���g��80�t���[���ȏ�̎�
			if (eLeftWard.leftShot[0].shotCounter >= ENEMY_SHOT_COUNTER)
			{
				//�G�̕\���t���O���I���̎�
				if (eLeftWard.graphFlag == true)
				{
					//�e�̕\���t���O���I�t�̎������ʒu��ݒ肵�ĕ\���t���O���I���ɂ���
					if (eLeftWard.leftShot[i].graphFlag == false)
					{
						//�G�̒e�̍��W�̏����ݒ�
						eLeftWard.leftShot[i].object.x = eLeftWard.object.x;
						eLeftWard.leftShot[i].object.y = (eLeftWard.object.h - eLeftWard.leftShot[0].object.h) / 2 + eLeftWard.object.y;

						eLeftWard.leftShot[i].graphFlag = true;

						//�G�̒e�̃t���[���J�E���g���O�ɂ���
						eLeftWard.leftShot[0].shotCounter = 0;
					}
				}
			}
		}

		//�\���t���O���I�����������̏���
		if (eLeftWard.leftShot[i].graphFlag == true)
		{
			//�G�̒e�̈ړ����x����
			eLeftWard.leftShot[i].object.x -= ENEMY_SHOT_SPEEDX;

			//window�̍�������o���Ƃ��ɕ\���t���O���I�t�ɂ���
			if (eLeftWard.leftShot[i].object.x < 0)
			{
				eLeftWard.leftShot[i].graphFlag = false;
			}

			//���@�̕\���t���O���I���̎�
			if (player.graphFlag == true)
			{
				//�G�̒e�Ǝ��@�̓����蔻�菈��
				if (CollisionSmallRect(player.object, eLeftWard.leftShot[i].object, player.hitFlag))
				{
					//�G�̒e�̕\���t���O���I�t�ɂ���
					eLeftWard.leftShot[i].graphFlag = false;

					//���@�̃_���[�W�t���O���I���ɂ���
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
void DrawEnemyLeftShot(const Enemy& eLeftWard)
{
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		//�G�̒e�̕\���t���O���I���̎��ɕ`�悷��
		if (eLeftWard.leftShot[i].graphFlag == true)
		{
			DrawGraph((int)eLeftWard.leftShot[i].object.x, (int)eLeftWard.leftShot[i].object.y, eLeftWard.leftShot[0].object.graph, true);
		}
	}
}
