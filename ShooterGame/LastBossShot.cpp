
/*
*���X�{�X�̒e�̊֐� 
*/

#include"Enemy.h"
#include"Player.h"
#include"Event.h"
#include"Map.h"

//���X�{�X�̒e�̉摜�ǂݍ��݊֐�
void LoadBossShot(Enemy& boss)
{
	//�e1�̉摜��ǂݍ���
	boss.bossFirstShot[0].object.graph = LoadGraph("img/LeftTakoShot.png");

	//�e�Q�̉摜��ǂݍ���
	boss.bossSecondShot[0].object.graph = LoadGraph("img/ikaShot.png");
}

//���X�{�X�̒e�̏����֐�
void InitBossShot(Enemy& boss)
{
	//�{�X�̒e�̐���for������
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		/*
		*�{�X�̒e�P�̏�����
		*/
		//�e1�̕\���t���O���I�t�ɂ���
		boss.bossFirstShot[i].graphFlag = false;

		//�e1�̉摜�T�C�Y��ǂݍ���
		GetGraphSize(boss.bossFirstShot[0].object.graph, &boss.bossFirstShot[i].object.w, &boss.bossFirstShot[i].object.h);

		//�e1�̈ړ����x�ϐ���ݒ�
		boss.bossFirstShot[i].object.vx = ENEMY_SHOT_SPEEDX;
		boss.bossFirstShot[i].object.vy = BOSS_MOVE_SHOT;

		/*
		*�{�X�̒e�Q�̏�����
		*/
		//�e�Q�̕\���t���O���I�t����
		boss.bossSecondShot[i].graphFlag = false;

		//�e2�̉摜�T�C�Y��ǂݍ���
		GetGraphSize(boss.bossSecondShot[0].object.graph, &boss.bossSecondShot[i].object.h, &boss.bossSecondShot[i].object.h);

		//�e2�̈ړ����x�ϐ���ݒ�
		boss.bossSecondShot[i].object.vx = ENEMY_SHOT_SPEEDX;
		boss.bossSecondShot[i].object.vy = BOSS_MOVE_SHOT;
	}

	//�{�X�̒e1���o���t���[���J�E���g�̏�����
	boss.bossFirstShot[0].shotCounter = 0;

	//�{�X�̒e�Q���o���t���[���J�E���g�̏�����
	boss.bossSecondShot[0].shotCounter = 0;
}

//���X�{�X�̒e�̃A�b�v�f�[�g�֐�
void UpdateBossShot(Enemy& boss, const Map& map, Player& player, int& remainP)
{
	//�{�X�̒e�̐���for������
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		//�}�b�v�`�b�v�̈ړ��t���O���I�t�ɂȂ����Ƃ�
		if (map.mapChipMoveFlag == false)
		{
			//���ꂼ��̒e�̔��˃J�E���g��1�����₷
			boss.bossFirstShot[0].shotCounter++;
			boss.bossSecondShot[0].shotCounter++;

			//�e�P�̔��˃J�E���g��80�t���[���ȏ�̂Ƃ�
			if (boss.bossFirstShot[0].shotCounter >= ENEMY_SHOT_COUNTER)
			{
				//�e1�̍��W�̏����ݒ�
				boss.bossFirstShot[i].object.x = boss.object.x;
				boss.bossFirstShot[i].object.y = boss.object.y + (boss.bossFirstShot[i].object.vy * i);

				//�����{�X����ɍ��W���ݒ�A�܂��̓{�X��艺�ɍ��W���ݒ肳�ꂽ�Ƃ��ړ��̕����𔽓]����
				if (boss.bossFirstShot[i].object.y <= boss.object.y ||
					(boss.bossFirstShot[i].object.y + boss.bossFirstShot[i].object.h) >= (boss.object.y + boss.object.h))
				{
					boss.bossFirstShot[i].object.vy *= -1;
				}

				//�e�P�̕\���t���O���I���ɂ���
				boss.bossFirstShot[i].graphFlag = true;

				//�e1�̔��˃J�E���g���O�ɂ���
				boss.bossFirstShot[0].shotCounter = 0;
			}
			
			if (boss.bossSecondShot[0].shotCounter >= ENEMY_SHOT_COUNTER)
			{
				boss.bossSecondShot[i].object.x = boss.object.x;
				boss.bossSecondShot[i].object.y = (boss.object.y + boss.object.h) - (boss.bossSecondShot[i].object.vy * i);

				if (boss.bossSecondShot[i].object.y <= boss.object.y ||
					(boss.bossSecondShot[i].object.y + boss.bossSecondShot[i].object.h) >= (boss.object.y + boss.object.h))
				{
					boss.bossSecondShot[i].object.vy *= -1;
				}

				boss.bossSecondShot[i].graphFlag = true;

				boss.bossSecondShot[0].shotCounter = 0;
			}

		}

		//�{�X�̒e�P�̕\���t���O���I�����������̏���
		if (boss.bossFirstShot[i].graphFlag == true)
		{
			boss.bossFirstShot[i].object.x -= boss.bossFirstShot[i].object.vx;

			if (boss.bossFirstShot[i].object.x < 0)
			{
				boss.bossFirstShot[i].graphFlag = false;
			}

			if (player.graphFlag == true)
			{
				if (CollisionSmallRect(player.object, boss.bossFirstShot[i].object, player.hitFlag))
				{
					boss.bossFirstShot[i].graphFlag = false;

					player.damagedFlag = true;

					player.graphFlag = false;

					UpdateRemainPlayer(remainP);
				}
			}
		}
		
		//�{�X�̒e2�̕\���t���O���I�����������̏���
		if (boss.bossSecondShot[i].graphFlag == true)
		{
			boss.bossSecondShot[i].object.x -= boss.bossSecondShot[i].object.vx;

			if (boss.bossSecondShot[i].object.x < 0)
			{
				boss.bossSecondShot[i].graphFlag = false;
			}

			if (player.graphFlag == true)
			{
				if (CollisionSmallRect(player.object, boss.object, player.hitFlag))
				{
					boss.bossSecondShot[i].graphFlag = false;

					player.damagedFlag = true;

					player.graphFlag = false;

					UpdateRemainPlayer(remainP);
				}
			}
		}
	}
}

//���X�{�X�̒e�̕`��֐�
void DrawBossShot(const Enemy& boss)
{
	//�{�X�̒e�̐���for������
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		if (boss.bossFirstShot[i].graphFlag == true)
		{
			DrawGraph((int)boss.bossFirstShot[i].object.x, (int)boss.bossFirstShot[i].object.y, boss.bossFirstShot[0].object.graph, true);
		}

		if (boss.bossSecondShot[i].graphFlag == true)
		{
			DrawGraph((int)boss.bossSecondShot[i].object.x, (int)boss.bossSecondShot[i].object.y, boss.bossSecondShot[0].object.graph, true);
		}
	}
}