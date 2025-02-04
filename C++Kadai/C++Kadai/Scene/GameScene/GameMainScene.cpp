#include "GameMainScene.h"
#include "../../Utility/InputControl.h"
#include <DxLib.h>
#include "../../Object/Character/Player/Player.h"
#include "../../Object/Character/Enemy/EnemyRed.h"
#include "../../Object/Stage/Ground.h"

GameMainScene::GameMainScene()
{
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

	return __super::Update();
}

void GameMainScene::Draw() const
{
	__super::Draw();
	DrawFormatString(10, 10, GetColor(255, 255, 255), "メイン画面");

	for (const auto& block : stage_manager.GetBlock())
	{
		DrawBox(block.x, block.y, block.x + 32, block.y + 32, GetColor(255, 255, 255), TRUE);
	}
}

void GameMainScene::Finalize()
{
}

eSceneType GameMainScene::GetNowSceneType() const
{
	return eSceneType::GAME_MAIN;
}

void GameMainScene::LoadStage()
{
	stage_manager.LoadCSV("Resource/file/stage.csv");

	// ここで読み込んだブロックデータを元にオブジェクト生成
	for (const auto& data : stage_manager.GetBlock()) {
		SetStage(data);
	}
}

void GameMainScene::SetStage(const StageData& data)
{
	switch (data.type)
	{
	case PLAYER:
		CreateObject<Player>(Vector2D(data.x, data.y), Vector2D(64.0f));
		break;
	case ENEMY:
		CreateObject<EnemyRed>(Vector2D(data.x, data.y), Vector2D(64.0f));
		break;
	case BLOCK:
		CreateObject<Ground>(Vector2D(data.x, data.y), Vector2D(64.0f));
		break;
	default:
		break;
	}
}
