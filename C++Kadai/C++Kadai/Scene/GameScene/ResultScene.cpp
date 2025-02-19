#include "ResultScene.h"
#include "../../Utility/InputControl.h"
#include <DxLib.h>
#include "../../common.h"
#include "../../Scene/SceneManager.h"

ResultScene::ResultScene():final_score()
{
}

ResultScene::~ResultScene()
{
}

void ResultScene::Initialize()
{
	final_score = SceneManager::GetInstance()->GetScore();
}

eSceneType ResultScene::Update()
{
	InputControl* input = InputControl::GetInstance();
	//上キーで移動
	if (input->GetKeyDown(KEY_INPUT_UP))cursor = (cursor - 1 + 2) % 2;
	//下キーで移動
	if (input->GetKeyDown(KEY_INPUT_DOWN))cursor = (cursor + 1) % 2;


	//決定
	if (input->GetKeyDown(KEY_INPUT_Z)) {
		if (cursor == 0)
		{
			return eSceneType::GAME_MAIN;
		}
		else
		{
			return eSceneType::TITLE;
		}
	}

	return GetNowSceneType();
}

void ResultScene::Draw() const
{
	SetFontSize(28);
	DrawFormatString((SCREEN_WIDTH / 2) - 90, (SCREEN_HEIGHT / 2) - 200, GetColor(255, 255, 255), "リザルト画面");
	DrawFormatString((SCREEN_WIDTH / 2) - 90, (SCREEN_HEIGHT / 2) - 170, GetColor(255, 255, 255), "SCORE : %d",final_score);

	for (int i = 0; i < 2; i++)  // i は 0 から始める
	{
		int y = (SCREEN_HEIGHT / 2) + 50 + i * (40 + 10); // 四角形の間隔を考慮

		// 選択中は黄色
		int color = 0;
		if (i == cursor)
		{
			color = GetColor(255, 255, 0);
		}
		else
		{
			color = GetColor(255, 0, 0);
		}
		DrawBox((SCREEN_WIDTH / 2) - (120 / 2), y, (SCREEN_WIDTH / 2) + (120 / 2), y + 40, color, FALSE);


		// テキスト描画
		DrawFormatString((SCREEN_WIDTH / 2) - 40, y + 7, GetColor(255, 255, 255), i == 0 ? "MAIN" : "TITLE");
	}
}

void ResultScene::Finalize()
{
}

eSceneType ResultScene::GetNowSceneType() const
{
	return eSceneType::RESULT;
}
