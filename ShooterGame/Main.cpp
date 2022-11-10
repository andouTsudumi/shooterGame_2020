
//�����E�X�N���[���V���[�e�B���O�Q�[��

#include"main.h"

/*
* main.cpp�Ɏg�p����֐��v���g�^�C�v�錾
*/

//�S�̂̉摜�ǂݍ��݊֐�
void Load();

//�S�̂̏����֐�
void Init();

//�^�C�g�������s�֐�
void Title();

//�v���C�����s�֐�
void Play();

//�N���A�����s�֐�
void Clear();

//�Q�[���I�[�o�[�����s�֐�
void Over();

//�S�̂̃A�b�v�f�[�g�֐�
void Update();

//�S�̂̕`��֐�
void Draw();


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//��{�ݒ�֐�
	Configuration();

	//�Q�[���X�e�[�^�X��LOAD�̎�
	Load();

	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0 && !ProcessMessage())
	{
		switch (gameStatus)
		{
		case INIT:
			Init();
			break;

		//�Q�[���X�e�[�^�X���^�C�g���̎�
		case TITLE:
			Title();

			break;

		//�Q�[���X�e�[�^�X���v���C�̎�
		case PLAY:
			Play();

			break;

		//�Q�[���X�e�[�^�X���I�[�o�[�̎�
		case OVER:
			Over();

			break;

		//�Q�[���X�e�[�^�X���N���A�̎�
		case CLEAR:
			Clear();

			break;

		default:
			break;
		}

	}

	DxLib_End();
	return 0;
}

//�S�̂̉摜�ǂݍ��݊֐�
void Load()
{
	//�Q�[���X�e�[�^�X��LOAD�̎�
	if (gameStatus == LOAD)
	{
		//�w�i�̉摜�ǂݍ��݊֐�
		LoadLeftBackGround(leftBack);
		LoadRightBackGround(rightBack);

		//���ꂼ��̃Q�[���X�e�[�^�X���̉摜�ǂݍ��݊֐�
		LoadStart(startImg);
		LoadClear(clearImg);
		LoadLose(loseImg);

		//���@�̉摜�ǂݍ��݊֐�
		LoadPlayer(player);

		//���@�̒e�̉摜�ǂݍ��݊֐�
		LoadPlayerShot(player);

		//�}�b�v�̉摜�ǂݍ��݊֐�
		LoadMap(map);

		//�������̌Œ�G��for��
		for (int i = 0; i < ENEMY_LEFT_WARD_MAX; i++)
		{
			//�������̌Œ�G�̉摜�ǂݍ��݊֐�
			LoadEnemyLeftWard(eLeftWard[i]);

			//�������̌Œ�G�̒e�̉摜�ǂݍ��݊֐�
			LoadEnemyLeftShot(eLeftWard[i]);
		}

		//�������̌Œ�G��for��
		for (int i = 0; i < ENEMY_DOWN_WARD_MAX; i++)
		{
			//�������̌Œ�G�̉摜�ǂݍ��݊֐�
			LoadEnemyDownWard(eDownWard[i]);

			//�������̌Œ�G�̒e�̉摜�ǂݍ��݊֐�
			LoadEnemyDownShot(eDownWard[i]);
		}

		//�g�̓��������G��for��
		for (int i = 0; i < ENEMY_WAVE_MAX; i++)
		{
			//�g�̓��������G�̉摜�ǂݍ��݊֐�
			LoadEnemyWave(eWave[i]);

			//�g�̓��������G�̒e�̉摜�ǂݍ��݊֐�
			LoadEnemyWaveShot(eWave[i]);
		}

		LoadBoss(boss);
		LoadBossShot(boss);

		//�Q�[���X�e�[�^�X��INIT�ɂ���
		gameStatus = INIT;
	}
}

//�S�̂̏����֐�
void Init()
{
	//���@�����֐�
	InitPlayer(player);

	//���@�̒e�����֐�
	InitPlayerShot(player);

	//�������̌Œ�G
	for (int i = 0; i < ENEMY_LEFT_WARD_MAX; i++)
	{
		//�������̌Œ�G�����֐�
		InitEnemyLeftWard(eLeftWard[i], i);

		//�������̌Œ�G�̒e�����֐�
		InitEnemyLeftShot(eLeftWard[i]);
	}

	//�������̌Œ�G
	for (int i = 0; i < ENEMY_DOWN_WARD_MAX; i++)
	{
		//�������̌Œ�G�����֐�
		InitEnemyDownWard(eDownWard[i], i);

		//�������̌Œ�G�̒e�����֐�
		InitEnemyDownShot(eDownWard[i]);
	}

	for (int i = 0; i < ENEMY_WAVE_MAX; i++)
	{
		//�g�̓��������G�̏����֐�
		InitEnemyWave(eWave[i]);

		//�g�̓��������G�̒e�̏����֐�
		InitEnemyWaveShot(eWave[i]);
	}

	InitBoss(boss);
	InitBossShot(boss);

	//�w�i�����֐�
	InitLeftBackGround(leftBack);
	InitRightBackGround(rightBack, leftBack);

	//�}�b�v�̏����֐�
	InitMap(map, block);

	//�Q�[���X�e�[�^�X��ʏ����֐�
	InitStart(startImg);
	InitClear(clearImg);
	InitLose(loseImg);

	//�X�R�A�����֐�
	InitScore(score);

	//���@�̎c�@�����֐�
	InitRemainPlayer(remainPlayer);

	//�Q�[���X�e�[�^�X���^�C�g����
	gameStatus = TITLE;
}

//�^�C�g�������s�֐�
void Title()
{
		ClearDrawScreen();

		//�X�^�[�g��ʕ\��
		DrawStart(startImg);
		SetFontSize(24);


		//�G���^�[�L�[����������Q�[���X�e�[�^�X��PLAY�ɂ���
		if (CheckHitKey(KEY_INPUT_RETURN))
		{
			gameStatus = PLAY;

			WaitTimer(300);
		}

		ScreenFlip();

}

//�v���C�����s�֐�
void Play()
{
		//�S�̂̃A�b�v�f�[�g�֐�
		Update();

		//�S�̂̕`��֐�
		Draw();
}

//�Q�[���I�[�o�[�����s�֐�
void Over()
{
		ClearDrawScreen();

		//�Q�[���I�[�o�[��ʕ\��
		DrawLose(loseImg);

		//�X�y�[�X�L�[����������Q�[���X�e�[�^�X��INIT�ɂ���
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			gameStatus = INIT;

			WaitTimer(300);

		}

		ScreenFlip();

}

//�N���A�����s�֐�
void Clear()
{
		ClearDrawScreen();

		//�Q�[���N���A��ʕ\��
		DrawClear(clearImg);

		//�X�y�[�X�L�[����������Q�[���X�e�[�^�X��INIT�ɂ���
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			gameStatus = INIT;

			WaitTimer(300);
		}

		ScreenFlip();
}

//�S�̂̃A�b�v�f�[�g�֐�
void Update()
{
	/*
	�e�A�b�v�f�[�g�֐����Ăяo��
	*/

	//�w�i�A�b�v�f�[�g�֐�
	UpdateLeftBackGround(leftBack);
	UpdateRightBackGround(rightBack);

	//�}�b�v�̃A�b�v�f�[�g�֐�
	UpdateMap(block, map, eLeftWard, eDownWard, eWave, player, remainPlayer);

	//���@�A�b�v�f�[�g�֐�
	UpdatePlayer(player);

	//���@�̒e�A�b�v�f�[�g�֐�
	//�΍������̌Œ�G
	UpdatePlayerShotVSEnemyLeftWard(player, eLeftWard, score);

	//�Ή������̌Œ�G
	UpdatePlayerShotVSEnemyDownWard(player, eDownWard, score);

	//�Δg�̓��������G
	UpdatePlayerShotVSEnemyWave(player, eWave, score);

	//UpdatePlayerShotVSEnemies(player,elef)

	//�΃��X�{�X
	UpdatePlayerShotVSboss(player, boss, map, score);
	

	//�������̓G�ƒe�̃A�b�v�f�[�g�֐�
	for (int i = 0; i < ENEMY_LEFT_WARD_MAX; i++)
	{
		//�������̌Œ�G
		UpdateEnemyLeftWard(eLeftWard[i], player, remainPlayer);

		//�������̌Œ�G�̒e
		UpdateEnemyLeftShot(eLeftWard[i], player, remainPlayer);
	}

	//�������̓G�ƒe�̃A�b�v�f�[�g�֐�
	for (int i = 0; i < ENEMY_DOWN_WARD_MAX; i++)
	{
		//�������̌Œ�G
		UpdateEnemyDownWard(eDownWard[i], player, remainPlayer);

		//�������̌Œ�G�̒e
		UpdateEnemyDownShot(eDownWard[i], player, remainPlayer);
	}

	//�g�̓��������G�ƒe�̃A�b�v�f�[�g�֐�
	for (int i = 0; i < ENEMY_WAVE_MAX; i++)
	{
		//�g�̓��������G
		UpdateEnemyWave(eWave[i], player, remainPlayer);

		//�g�̓��������G�̒e
		UpdateEnemyWaveShot(eWave[i], player, remainPlayer);

	}

	UpdateBoss(boss, map, player, remainPlayer);
	UpdateBossShot(boss, map, player, remainPlayer);

	//�{�X��|�����Ƃ��ɃQ�[���X�e�[�^�X��CLEAR�ɂ���
	if (boss.graphFlag == false && boss.damagedFlag == false)
	{
		WaitTimer(300);

		gameStatus = CLEAR;
	}

	if (player.dieFlag)
	{
		WaitTimer(300);

		gameStatus = OVER;
	}

	//���@�̎c�@���O��艺�ŃQ�[���X�e�[�^�X��OVER�ɂ���
	if (remainPlayer <= 0)
	{
		WaitTimer(300);

		gameStatus = OVER;
	}

}

//�S�̂̕`��֐�
void Draw()
{
	ClearDrawScreen();

	/*
	�`��֐����Ăяo��
	*/

	//�w�i�`��֐�
	DrawLeftBackGround(leftBack);
	DrawRightBackGround(rightBack);

	//�}�b�v�̕`��֐�
	DrawMap(map, block);

	////��ʃX�N���[�����W�����p�v���O����
	//DrawFormatString(0, 100, GetColor(0, 0, 0), "�v���C���[�F%f�A%f", player.object.x, player.object.y);
	//DrawFormatString(0, 150, GetColor(0, 0, 0), "�w�i�P�F%f", leftBack.object.x);
	//DrawFormatString(0, 200, GetColor(0, 0, 0), "�w�i�Q�F%f", rightBack.object.x);
	//DrawFormatString(0, 250, GetColor(0, 0, 0), "�������G�P�F%f", eLeftCannon[0].object.x);
	//DrawFormatString(0, 50, GetColor(0, 0, 0), "�g�̓��������G�F%f", eWave.object.x);
	//DrawFormatString(0, 100, GetColor(0, 0, 0), "�}�b�v�`�b�v[0]�F%f", block[0].object.x);
	DrawFormatString(0, 100, GetColor(0, 0, 0), "���X�{�X�̍��W�F(%f,%f)", boss.object.x, boss.object.y);

	//���@�`��֐�
	DrawPlayer(player);

	//���@�̒e�`��֐�
	DrawPlayerShot(player);

	//�G�`��֐�
	for (int i = 0; i < ENEMY_LEFT_WARD_MAX; i++)
	{
		//�������̌Œ�G
		DrawEnemyLeftWard(eLeftWard[i]);

		//�������̌Œ�G�̒e
		DrawEnemyLeftShot(eLeftWard[i]);
	}

	//�G�`��֐�
	for (int i = 0; i < ENEMY_DOWN_WARD_MAX; i++)
	{
		//�������̌Œ�G
		DrawEnemyDownWard(eDownWard[i]);

		//�������̌Œ�G�̒e
		DrawEnemyDownShot(eDownWard[i]);
	}

	//�G�`��֐�
	for (int i = 0; i < ENEMY_WAVE_MAX; i++)
	{
		//�g�̓��������G
		DrawEnemyWave(eWave[i]);

		//�g�̓��������G�̒e
		DrawEnemyWaveShot(eWave[i]);

	}

	DrawBoss(boss);
	DrawBossShot(boss);

	////�X�R�A�`��֐�
	//DrawScore(score);

	//���@�̎c�@�`��֐�
	DrawRemainPlayer(remainPlayer);

	ScreenFlip();

}