
/*
* ���X�{�X�̏����֐�
*/

#include"Enemy.h"
#include"Player.h"
#include"Event.h"
#include"Map.h"

//���X�{�X�̉摜�ǂݍ��݊֐�
void LoadBoss(Enemy& boss)
{
	boss.object.graph = LoadGraph("img/Boss.png");

	boss.damagedGraph = LoadGraph("img/DamagedBoss.png");
}

//���X�{�X�̏����֐�
void InitBoss(Enemy& boss)
{
	boss.graphFlag = true;

	boss.damagedFlag = false;

	boss.drawDamagedCounter = 0;

	boss.DieCounter = 0;

	//���X�{�X�̉摜�T�C�Y��ǂݍ���
	GetGraphSize(boss.object.graph, &boss.object.w, &boss.object.h);

	//���X�{�X�̃_���[�W�摜�T�C�Y��ǂݍ���
	GetGraphSize(boss.damagedGraph, &boss.object.w, &boss.object.h);

	//�G�̍��W�̏����ݒ�
	boss.object.x = 190 * MAP_CHIP_SIZE;
	boss.object.y = 2 * MAP_CHIP_SIZE;
}

//���X�{�X�̃A�b�v�f�[�g�֐�
void UpdateBoss(Enemy& boss, Map& map, Player& player, int& remainP)
{
	if (boss.graphFlag == true || boss.damagedFlag == true)
	{
		if (map.mapChipMoveFlag == true)
		{
			boss.object.x -= MAP_SCREEN_SPEEDX;
		}

		//���@�{�̂ƃ��X�{�X�{�̂̓����蔻��֐�
		if (CollisionSmallRect(boss.object, player.object, player.hitFlag) && 
			map.mapChipMoveFlag == false)
		{
			player.damagedFlag = true;

			player.graphFlag = false;

			player.damagedCount = 0;

			player.hitFlag = false;

			UpdateRemainPlayer(remainP);
		}
	}
}

//���X�{�X�̕`��֐�
void DrawBoss(Enemy& boss)
{
	if (boss.graphFlag == true)
	{
		DrawGraph((int)boss.object.x, (int)boss.object.y, boss.object.graph, true);
	}

	if (boss.damagedFlag == true)
	{
		boss.graphFlag = false;

		++boss.drawDamagedCounter;

		//�_���[�W�摜��`�悷��
		DrawGraph((int)boss.object.x, (int)boss.object.y, boss.damagedGraph, true);

		if (boss.drawDamagedCounter >= BOSS_DRAW_DAMAGED_COUNTER)
		{
			boss.damagedFlag = false;

			boss.graphFlag = true;

			++boss.DieCounter;

			boss.drawDamagedCounter = 0;

			if (boss.DieCounter >= 25)
			{
				boss.graphFlag = false;
			}
		}
	}
}