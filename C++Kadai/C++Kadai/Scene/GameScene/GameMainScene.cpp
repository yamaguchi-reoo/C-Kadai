#include "GameMainScene.h"
#include "../../Utility/InputControl.h"
#include <DxLib.h>
#include "../../Object/Character/Player/Player.h"
#include "../../Object/Character/Enemy/EnemyRed.h"

GameMainScene::GameMainScene()
{
	player = new Player();
	enemy_r = new EnemyRed();
}

GameMainScene::~GameMainScene()
{
}

void GameMainScene::Initialize()
{
	CreateObject<Player>(Vector2D(32.0f,300.0f), Vector2D(64.0f));
	CreateObject<EnemyRed>(Vector2D(500.0f,300.0f), Vector2D(64.0f));
}

eSceneType GameMainScene::Update()
{
	InputControl* input = InputControl::GetInstance();
	//SPACEキーでインゲーム画面に遷移する
	if (input->GetKeyDown(KEY_INPUT_D))
	{
		return eSceneType::TITLE;
	}
	//SPACEキーでインゲーム画面に遷移する
	if (input->GetKeyDown(KEY_INPUT_S))
	{
		return eSceneType::RESULT;
	}

	/*if (player->CheckBoxCollision(enemy_r))
	{
		player->OnHitCollision(enemy_r);
	}*/

	return __super::Update();
}

void GameMainScene::Draw() const
{
	__super::Draw();
	DrawFormatString(10, 10, GetColor(255, 255, 255), "メイン画面");
}

void GameMainScene::Finalize()
{
}

eSceneType GameMainScene::GetNowSceneType() const
{
	return eSceneType::GAME_MAIN;
}
