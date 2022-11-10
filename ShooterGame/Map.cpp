
/*
* �}�b�v�̏����֐�
*/

#include"Map.h"

//�}�b�v�̉摜�ǂݍ��݊֐�
void LoadMap(Map& map)
{
	//�}�b�v�̉摜�ǂݍ���
	map.object.graph = LoadGraph("img/darkDirtBlock.png");
}

//�}�b�v�̏����֐�
void InitMap(Map& map, Block* block)
{
	//�u���b�N�J�E���g�̏�����
	map.blockCounter = 0;

	map.mapChipMoveFlag = true;

	//�}�b�v��y���W��for��
	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		//�}�b�v��x���W��for��
		for (int x = 0; x < MAP_WIDTH * MAP_SCROLL_MAX; x++)
		{
			//�}�b�v�`�b�v�̓񎟌��z��̒l�ǂݍ���
			int mapChipBlockNum = mapChipBlock[y][x];

			//�}�b�v�`�b�v�̒l���O�ȊO�������ꍇ
			if (mapChipBlockNum != 0)
			{
				//�u���b�N�̍��W���擾����
				float blockPosX = (float)(x * MAP_CHIP_SIZE);
				float blockPosY = (float)(y * MAP_CHIP_SIZE);

				//�u���b�N�̏����֐����Ăяo��
				InitBlock(block, map.blockCounter, map.object.graph, blockPosX, blockPosY, MAP_CHIP_SIZE, MAP_CHIP_SIZE);
				//�u���b�N�J�E���g���P���₷
				++map.blockCounter;
			}
		}
	}
}

//�}�b�v�̃A�b�v�f�[�g�֐�
void UpdateMap(Block* block, Map& map, Enemy* eLeftWard, Enemy* eDownWard, Enemy* eWave, Player& player, int& remainP)
{
	UpdateBlock(block, map, eLeftWard, eDownWard, eWave, player, remainP);
}

//�}�b�v�̕`��֐�
void DrawMap(const Map& map, Block* block)
{
	//for���Ńu���b�N���Ɋ֐����Ăяo��
	for (int i = 0; i < map.blockCounter; i++)
	{
		//�u���b�N�̕`��֐����Ăяo��
		DrawBlock(block, i);
	}
}