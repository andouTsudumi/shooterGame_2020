
/*
* �g�̓��������G�̒e�̊֐�
*/

#include"Player.h"
#include"Enemy.h"
#include"Event.h"

//�g�̓��������G�̒e�̉摜�ǂݍ��݊֐�
void LoadEnemyWaveShot(Enemy& eWave)
{
	//�G�̒e�̉摜�ǂݍ���
	//���̒e
	eWave.waveShot[0].object.graph = LoadGraph("img/LeftTakoShot.png");
	//���̒e
	eWave.waveShot[1].object.graph = LoadGraph("img/WhiteShot.png");

}

//�g�̓��������G�̒e�̏����֐�
void InitEnemyWaveShot(Enemy& eWave)
{
	//�g�̓��������G�̒e����for������
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		//�G�̒e�̕\���t���O���I�t�ɂ���
		eWave.waveShot[i].graphFlag = false;
	}

	//�G�̒e���o���t���[���J�E���g�̏�����
	eWave.waveShot[0].shotCounter = 0;

	//�G�̒e�̉摜�T�C�Y��ǂݍ���
	//���̒e
	GetGraphSize(eWave.waveShot[0].object.graph, &eWave.waveShot[0].object.w, &eWave.waveShot[0].object.h);
	//���̒e
	GetGraphSize(eWave.waveShot[1].object.graph, &eWave.waveShot[1].object.w, &eWave.waveShot[1].object.h);

}

//�g�̓��������G�̒e�̃A�b�v�f�[�g�֐�
void UpdateEnemyWaveShot(Enemy& eWave, Player& player, int& remainP)
{
	//�g�̓��������G�̒e����for������
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		//window�̉�ʓ��ɓ����Ă�����e��\������
		if (eWave.object.x >= 0 && eWave.object.x <= SCREEN_W &&
			eWave.object.y >= 0 && eWave.object.y <= SCREEN_H)
		{
			//�G�̒e�̔��˃J�E���g���P�����₷
			++eWave.waveShot[0].shotCounter;

			//�G�̒e�̃J�E���g��30�t���[���ȏ�̎�
			if (eWave.waveShot[0].shotCounter >= ENEMY_WAVE_SHOT_COUNTER)
			{
				//�G�̕\���t���O���I���̎�
				if (eWave.graphFlag == true)
				{
					//�e�̕\���t���O���I�t�̎������ʒu��ݒ肵�ĕ\���t���O���I���ɂ���
					if (eWave.waveShot[i].graphFlag == false)
					{
						//�G�̒e�̍��W�̏����ݒ�
						eWave.waveShot[i].object.x = eWave.object.x;
						eWave.waveShot[i].object.y = (eWave.object.h - eWave.waveShot[0].object.h) / 2 + eWave.object.y;

						eWave.waveShot[i].graphFlag = true;

						//�G�̒e�̃t���[���J�E���g���O�ɂ���
						eWave.waveShot[0].shotCounter = 0;
					}
				}
			}
		}

		//�\���t���O���I�����������̏���
		if (eWave.waveShot[i].graphFlag == true)
		{
			//�G�̒e�̈ړ����x����
			eWave.waveShot[i].object.x -= (ENEMY_SHOT_SPEEDX + SCREEN_SPEEDX);

			//window�̍�������o���Ƃ��ɕ\���t���O���I�t�ɂ���
			if (eWave.waveShot[i].object.x < 0)
			{
				eWave.waveShot[i].graphFlag = false;
			}

			//���@�̕\���t���O���I���̎�
			if (player.graphFlag == true)
			{
				//�G�̒e�Ǝ��@�̓����蔻�菈��
				if (CollisionSmallRect(eWave.waveShot[i].object, player.object, remainP))
				{
					//�G�̒e�̕\���t���O���I�t�ɂ���
					eWave.waveShot[i].graphFlag = false;

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


//�g�̓��������G�̒e�̕`��֐�
void DrawEnemyWaveShot(const Enemy& eWave)
{
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		//�G�̒e�̕\���t���O���I���̎��ɕ`�悷��
		if (eWave.waveShot[i].graphFlag == true)
		{
			DrawGraph((int)eWave.waveShot[i].object.x, (int)eWave.waveShot[i].object.y, eWave.waveShot[0].object.graph, true);
		}
	}
}
