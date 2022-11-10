
/*
* ���@�̊֐�����
*/

#include"Player.h"

//���@�̉摜�ǂݍ��݊֐�
void LoadPlayer(Player& player)
{
	player.object.graph = LoadGraph("img/playerIka.png");
	player.damagedGraph = LoadGraph("img/playerDamagedIka.png");
}

//���@�̏����֐�
void InitPlayer(Player& player)
{
	//���@�̍��W�̏����ݒ�
	player.object.x = SCREEN_W / 2;
	player.object.y = SCREEN_H / 2;

	//���@�̉摜�T�C�Y��ǂݍ���
	GetGraphSize(player.object.graph, &player.object.w, &player.object.h);

	//���@�̕��펞�摜�t���O���I���ɂ���
	player.graphFlag = true;

	//���@�̃_���[�W�t���O���I�t�ɂ���
	player.damagedFlag = false;

	//���@�̃_���[�W�摜�\���J�E���g�������ݒ�
	player.drawDamagedCounter = 0;

	//���@�̑��x�x�N�g���̏����ݒ�
	player.object.vx = PLAYER_SPEED;
	player.object.vy = PLAYER_SPEED;

	//���@�̃_���[�W���󂯂�܂ł̃t���[���J�E���g�����l�ݒ�
	player.damagedCount = PLAYER_DAMAGED_COUNTER;

	//�����蔻��t���O���I���ɂ���
	player.hitFlag = true;

	//���@�ׂ̒����t���O���I�t�ɂ���
	player.crushFlag = false;

	player.dieFlag = false;
}

//���@�̃A�b�v�f�[�g�֐�
void UpdatePlayer(Player& player)
{
	//���@�̓����蔻��t���O���I�t�̎�
	if (player.hitFlag == false)
	{
		//�_���[�W���󂯂�܂ł̃t���[���J�E���g���P���₷
		++player.damagedCount;

		//�_���[�W���󂯂�܂ł̃J�E���g��480�ȏ�̎��ɓ����蔻��t���O���I���ɂ���
		if (player.damagedCount >= PLAYER_DAMAGED_COUNTER)
		{
			player.hitFlag = true;
		}
	}


	//���ꂼ��̃L�[���v���C���[�������Ă����玩�@�𓮂���
	//��L�[
	if (CheckHitKey(KEY_INPUT_UP) == true /*&& player.moveFlag == true*/)
	{
		player.object.y -= player.object.vy;
	}
	//���L�[
	if (CheckHitKey(KEY_INPUT_DOWN) == true /*&& player.moveFlag == true*/)
	{
		player.object.y += player.object.vy;
	}
	//���L�[
	if (CheckHitKey(KEY_INPUT_LEFT) == true /*&& player.moveFlag == true*/)
	{
		player.object.x -= player.object.vx;
	}
	//�E�L�[
	if (CheckHitKey(KEY_INPUT_RIGHT) == true /*&& player.moveFlag == true*/)
	{
		player.object.x += player.object.vx;
	}



	//���@���͂ݏo�����ɂȂ������ʂ̒��ɖ߂�����
	//window�̍��[
	if (player.object.x < 0 && player.crushFlag == false)
	{
		player.object.x = 0;

	}

	if (player.object.x < -(MAP_CHIP_SIZE * 2) && player.crushFlag)
	{
		player.dieFlag = true;
	}
	else
	{
		player.crushFlag = false;
	}

	//window�̉E�[
	if (player.object.x > SCREEN_W - player.object.w)
	{
		player.object.x = (float)(SCREEN_W) - player.object.w;
	}
	//window�̏�
	if (player.object.y < 0)
	{
		player.object.y = 0;
	}
	//window�̉�
	if (player.object.y > SCREEN_H - player.object.h)
	{
		player.object.y = (float)(SCREEN_H) - player.object.h;
	}

}


//���@�̕`��֐�
void DrawPlayer(Player& player)
{
	//���@�̕��펞�\���t���O���I���̎����펞�̉摜��`�悷��
	if (player.graphFlag == true)
	{
		DrawGraph((int)player.object.x, (int)player.object.y, player.object.graph, true);
	}

	//���@�̃_���[�W�t���O���I���̎��_���[�W���󂯂Ă���摜��`�悷��
	if (player.damagedFlag == true)
	{
		player.graphFlag = false;

		++player.drawDamagedCounter;

		//�_���[�W�摜��`�悷��
		DrawGraph((int)player.object.x, (int)player.object.y, player.damagedGraph, true);

		//���@�̃_���[�W�J�E���g���T�ȏ�̎��_���[�W�t���O���I�t�ɂ��ă_���[�W�J�E���g���O�ɂ��ĕ��펞�̕\���t���O���I���ɂ���
		if (player.drawDamagedCounter >= PLAYER_DRAW_DAMAGED_COUNTER)
		{
			player.damagedFlag = false;
			player.drawDamagedCounter = 0;
			player.graphFlag = true;
		}
	}
}