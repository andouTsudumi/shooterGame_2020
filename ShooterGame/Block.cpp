
/*
* �u���b�N�̏����֐�
*/

#include"Map.h"
#include"Player.h"
#include"Enemy.h"
#include"Event.h"

//�u���b�N�̏����֐�
void InitBlock(Block* block, int blockNum, int graph, float x, float y, int w, int h)
{
	//�u���b�N�̔z��ɍ��W��ǂݍ���
	block[blockNum].object.x = x;
	block[blockNum].object.y = y;

	//�u���b�N�̔z��ɃT�C�Y��ǂݍ���
	block[blockNum].object.w = w;
	block[blockNum].object.h = h;

	//�u���b�N�̔z��ɉ摜��ǂݍ���
	block[blockNum].object.graph = graph;

}

//�u���b�N�̃A�b�v�f�[�g�֐�
void UpdateBlock(Block* block, Map& map, Enemy* eLeftWard, Enemy* eDownWard,
	Enemy* eWave, Player& player, int& remainP)
{
	for (int i = 0; i < map.blockCounter; i++)
	{
		//�}�b�v�`�b�v���E�[�ɗ���܂ŃX�N���[��������
		if (block[0].object.x >= -(SCREEN_W * MAP_SCROLL_MAX - SCREEN_W) && map.mapChipMoveFlag == true)
		{
			block[i].object.x -= MAP_SCREEN_SPEEDX;
		}
		else
		{
			map.mapChipMoveFlag = false;
		}

		if (CollisionRect(player.object, block[i].object))
		{
			//�u���b�N�̏㕔���ƂԂ�����
			if (((player.object.y + player.object.h) - block[i].object.y > 0) &&
				((player.object.y + player.object.h) - block[i].object.y <=
					MAX_OVERLAP_CAPACITY) && player.object.vy > 0.0f)
			{
				player.object.y = block[i].object.y - player.object.h;
			}

			//�u���b�N�̉������ƂԂ�����
			if ((block[i].object.y + block[i].object.h) - player.object.y <=
				MAX_OVERLAP_CAPACITY && player.object.vy > 0.0f)
			{
				player.object.y = block[i].object.y + block[i].object.h;
			}

			//�u���b�N�̍������ƂԂ�����
			if ((player.object.x + player.object.w) - block[i].object.x <
				MAX_OVERLAP_CAPACITY && player.object.vx > 0.0f)
			{
				player.object.x = block[i].object.x - player.object.w;

				player.crushFlag = true;
			}

			//�u���b�N�̉E���ƂԂ�����
			if ((block[i].object.x + block[i].object.w) - player.object.x <
				MAX_OVERLAP_CAPACITY && player.object.vx > 0.0f)
			{
				player.object.x = block[i].object.x + block[i].object.w;
			}
		}

		HitPlayerShot(block[i], player);

		for (int j = 0; j < ENEMY_LEFT_WARD_MAX; j++)
		{
			HitEnemyLeftWardShot(block[i], eLeftWard[j]);
		}

		for (int j = 0; j < ENEMY_DOWN_WARD_MAX; j++)
		{
			HitEnemyDownWardShot(block[i], eDownWard[j]);
		}

		for (int j = 0; j < ENEMY_WAVE_MAX; j++)
		{
			HitEnemyWaveShot(block[i], eWave[j]);
		}
	}
}

//���@�̒e�ƃu���b�N�̓����蔻��֐�
void HitPlayerShot(Block& block, Player& player)
{
	for (int i = 0; i < PLAYER_SHOT_MAX; i++)
	{
		if (CollisionRect(block.object, player.playerShot[i].object))
		{
			player.playerShot[i].graphFlag = false;
		}
	}
}

//�������̌Œ�G�̒e�ƃu���b�N�̓����蔻��֐�
void HitEnemyLeftWardShot(Block& block, Enemy& eLeftWard)
{
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		if (CollisionRect(block.object, eLeftWard.leftShot[i].object))
		{
			eLeftWard.leftShot[i].graphFlag = false;
		}
	}
}

//�������̌Œ�G�̒e�ƃu���b�N�̓����蔻��֐�
void HitEnemyDownWardShot(Block& block, Enemy& eDownWard)
{
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		if (CollisionRect(block.object, eDownWard.downShot[i].object))
		{
			eDownWard.downShot[i].graphFlag = false;
		}
	}
}

//�g�̓��������G�̒e�ƃu���b�N�̓����蔻��֐�
void HitEnemyWaveShot(Block& block, Enemy& eWave)
{
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		if (CollisionRect(block.object, eWave.waveShot[i].object))
		{
			eWave.waveShot[i].graphFlag = false;
		}
	}
}

//�{�X�̒e�ƃu���b�N�̓����蔻��֐�
void HitBossShot(Block& block, Enemy& boss)
{
	for (int i = 0; i < ENEMY_SHOT_MAX; i++)
	{
		if (CollisionRect(block.object, boss.bossFirstShot[i].object))
		{
			boss.bossFirstShot[i].graphFlag = false;
		}

		if (CollisionRect(block.object, boss.bossSecondShot[i].object))
		{
			boss.bossSecondShot[i].graphFlag = false;
		}
	}
}

//�u���b�N�̕`��֐�
void DrawBlock(const Block* block, const int blockNum)
{
	//�u���b�N�̕`�������
	DrawGraph((int)block[blockNum].object.x, (int)block[blockNum].object.y, block[blockNum].object.graph, true);
}