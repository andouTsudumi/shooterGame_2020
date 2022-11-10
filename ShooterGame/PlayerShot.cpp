/*
* ���@�̒e�̊֐�����
*/

#include"Player.h"
#include"Enemy.h"
#include"Event.h"
#include"Map.h"

//���@�̒e�̉摜�ǂݍ��݊֐�
void LoadPlayerShot(Player& player)
{
	//���@�̒e�̉摜�ǂݍ���
	//���̒e
	player.playerShot[0].object.graph = LoadGraph("img/IkaShot.png");
	//���̒e
	player.playerShot[1].object.graph = LoadGraph("img/RightTakoShot.png");

}

//���@�̒e�̏����֐�
void InitPlayerShot(Player& player)
{
	for (int i = 0; i < PLAYER_SHOT_MAX; i++)
	{
		//���@�̒e�̕\���t���O���I�t�ɂ���
		player.playerShot[i].graphFlag = false;

		//���@�̒e�̉摜�T�C�Y��ǂݍ���
		//���̒e
		GetGraphSize(player.playerShot[0].object.graph, &player.playerShot[i].object.w, &player.playerShot[i].object.h);
		//���̒e
		GetGraphSize(player.playerShot[1].object.graph, &player.playerShot[i].object.w, &player.playerShot[i].object.h);
	}

	//���̒e���o���܂ł̃t���[���J�E���g������
	player.playerShot[0].shotCounter = PLAYER_SHOT_COUNTER;

}

//���@�̒e�̃A�b�v�f�[�g�֐�
//�����蔻�葊��F�������̓G
void UpdatePlayerShotVSEnemyLeftWard(Player& player, Enemy* eLeftWard, int& score)
{
	for (int i = 0; i < PLAYER_SHOT_MAX; i++)
	{
		//�v���C���[���X�y�[�X�L�[�����������̏���
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			//���@�̒e�̕\���t���O���I�t�̎��e�̈ʒu��ݒ肷��
			if (player.playerShot[i].graphFlag == false)
			{
				player.playerShot[i].object.x = player.object.w + player.object.x;
				player.playerShot[i].object.y = (player.object.h - player.playerShot[0].object.h) / 2 + player.object.y;

				//���@�̒e���˃J�E���g���P�����₷
				player.playerShot[0].shotCounter++;

				//���@�̒e���˃J�E���g��30�ȏ�̎��ɕ\���t���O���I���ɂ��ăJ�E���g���O�ɂ���
				if (player.playerShot[0].shotCounter >= PLAYER_SHOT_COUNTER)
				{
					player.playerShot[i].graphFlag = true;
					player.playerShot[0].shotCounter = 0;
				}
			}
		}

		//���@�̒e�̕��펞�̃t���O���I���̎�
		if (player.playerShot[i].graphFlag == true)
		{
			//���@�̒e�̈ړ����x����
			player.playerShot[i].object.x += PLAYER_SHOT_SPEED;

			//window�̉E������o���Ƃ��Ƀt���O���I�t�ɂ���
			if (player.playerShot[i].object.x > SCREEN_W)
			{
				player.playerShot[i].graphFlag = false;
			}

			for (int j = 0; j < ENEMY_LEFT_WARD_MAX; j++)
			{
				//�G�̕\���t���O���I���̎�
				if (eLeftWard[j].graphFlag == true)
				{
					//���@�̒e�ƍ������Œ�G�̓����蔻�菈��
					if (CollisionRect(player.playerShot[i].object, eLeftWard[j].object))
					{
						//���������̂Ŏ��@�̒e��\��������t���O���I�t�ɂ���(���݂��Ȃ�)
						player.playerShot[i].graphFlag = false;

						//�G���_���[�W���󂯂��̂Ń_���[�W���󂯂����Ƃ�\������t���O���I���ɂ���
						eLeftWard[j].damagedFlag = true;

						//�_���[�W�t���O�𗧂Ă��̂ŕ��ʂ̃t���O���I�t�ɂ���
						eLeftWard[j].graphFlag = false;

						//�X�R�A�̃A�b�v�f�[�g�֐����Ăяo��
						UpdateScore(score);

					}
				}
			}
		}
	}
}

//���@�̒e�̃A�b�v�f�[�g�֐�
//�����蔻�葊��F�������̓G
void UpdatePlayerShotVSEnemyDownWard(Player& player, Enemy* eDownWard, int& score)
{
	for (int i = 0; i < PLAYER_SHOT_MAX; i++)
	{
		//���@�̒e�̕\���t���O���I���̎�
		if (player.playerShot[i].graphFlag == true)
		{
			//���@�̒e�̈ړ����x����
			player.playerShot[i].object.x += PLAYER_SHOT_SPEED;

			//window�̉E������o���Ƃ��ɕ\���t���O���I�t�ɂ���
			if (player.playerShot[i].object.x > SCREEN_W)
			{
				player.playerShot[i].graphFlag = false;
			}

			//�������̓G�̐���for���ł܂킷
			for (int j = 0; j < ENEMY_DOWN_WARD_MAX; j++)
			{
				//�G�̕��펞�\���t���O���I���̎�
				if (eDownWard[j].graphFlag == true)
				{
					//���@�̒e�Ɖ������Œ�G�̓����蔻�菈��
					if (CollisionRect(player.playerShot[i].object, eDownWard[j].object))
					{
						//���@�̒e�̕\���t���O���I�t�ɂ���
						player.playerShot[i].graphFlag = false;

						//�G�̃_���[�W�t���O���I���ɂ���
						eDownWard[j].damagedFlag = true;

						//�G�̕\���t���O���I�t�ɂ���
						eDownWard[j].graphFlag = false;

						//�X�R�A�̃A�b�v�f�[�g�֐����Ăяo��
						UpdateScore(score);

					}
				}
			}
		}
	}
}

//���@�̒e�̃A�b�v�f�[�g�֐�
//�����蔻�葊��F�g�̓��������G
void UpdatePlayerShotVSEnemyWave(Player& player, Enemy* eWave, int& score)
{
	for (int i = 0; i < PLAYER_SHOT_MAX; i++)
	{
		//���@�̒e�̕\���t���O���I���̎�
		if (player.playerShot[i].graphFlag == true)
		{
			//�g�̓��������G�̐���for���ł܂킷
			for (int j = 0; j < ENEMY_WAVE_MAX; j++)
			{
				//�G�̕\���t���O���I���̎�
				if (eWave[j].graphFlag == true)
				{
					//���@�̒e�Ɣg�̓��������G�̓����蔻�菈��
					if (CollisionRect(player.playerShot[i].object, eWave[j].object))
					{
						//���@�̒e�̕\���t���O���I�t�ɂ���
						player.playerShot[i].graphFlag = false;

						//�G�̃_���[�W�t���O���I���ɂ���
						eWave[j].damagedFlag = true;

						//���鎞�\���t���O���I�t�ɂ���
						eWave[j].graphFlag = false;

						//�X�R�A�̃A�b�v�f�[�g�֐����Ăяo��
						UpdateScore(score);

					}
				}
			}
		}
	}
}

//���@�̒e�̃A�b�v�f�[�g�֐�
//�����蔻�葊��F���X�{�X
void UpdatePlayerShotVSboss(Player& player, Enemy& boss, const Map& map, int& score)
{
	for (int i = 0; i < PLAYER_SHOT_MAX; i++)
	{
		//���@�̒e�̕\���t���O���I���̎�
		if (player.playerShot[i].graphFlag == true)
		{
			//���X�{�X�̕\���t���O���I���̎�
			if (boss.graphFlag == true)
			{
				//���@�̒e�ƃ��X�{�X�̓����蔻�菈��
				if (CollisionRect(player.playerShot[i].object, boss.object) &&
					map.mapChipMoveFlag == false)
				{
					if (map.mapChipMoveFlag == true)
					{
						//���@�̒e�̕\���t���O���I�t�ɂ���
						player.playerShot[i].graphFlag = false;
					}

					//���@�̒e�̕\���t���O���I�t�ɂ���
					player.playerShot[i].graphFlag = false;

					//���X�{�X�̃_���[�W�t���O���I���ɂ���
					boss.damagedFlag = true;

					//���X�{�X���펞�\���t���O���I�t�ɂ���
					boss.graphFlag = false;

					//�X�R�A�̃A�b�v�f�[�g�֐����Ăяo��
					UpdateScore(score);

				}
			}
		}
	}
}


//���@�̒e�̕`��֐�
void DrawPlayerShot(const Player& player)
{
	for (int i = 0; i < PLAYER_SHOT_MAX; i++)
	{
		//���@�̒e�̕\���t���O���I���̎��摜��`�悷��
		if (player.playerShot[i].graphFlag == true)
		{
			DrawGraph((int)player.playerShot[i].object.x, (int)player.playerShot[i].object.y, player.playerShot[0].object.graph, true);
		}
	}
}
