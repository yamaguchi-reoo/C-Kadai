#include "TitleScene.h"
#include "../../Utility/InputControl.h"
#include "DxLib.h"
#include "../../common.h"

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Initialize()
{
	cursor = 0;
}

eSceneType TitleScene::Update()
{
	InputControl* input = InputControl::GetInstance();
	//SPACEキーでインゲーム画面に遷移する
	//if (input->GetKeyDown(KEY_INPUT_A))
	//{
	//	return eSceneType::GAME_MAIN;
	//}
	////SPACEキーでインゲーム画面に遷移する
	//if (input->GetKeyDown(KEY_INPUT_S))
	//{
	//	return eSceneType::RESULT;
	//}

	//負の値にならないように
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
			return eSceneType::END;
		}
	}

	return GetNowSceneType();
}

void TitleScene::Draw() const
{
	SetFontSize(28);
	DrawFormatString((SCREEN_WIDTH / 2) - 90, (SCREEN_HEIGHT / 2) - 40, GetColor(255, 255, 255), "タイトル画面");

	//for (int i = 0; i < 2; i++)  //
	//{
	//	int y = (SCREEN_HEIGHT / 2) + 50 + i * (40 + 10); //四角形の間隔を考慮

	//	// 選択中は黄色
	//	int color = 0;
	//	if (i == cursor)
	//	{
	//		color = GetColor(255, 255, 0);
	//	}
	//	else
	//	{
	//		color = GetColor(255, 0, 0);
	//	}
	//	DrawBox((SCREEN_WIDTH / 2) - (120 / 2), y, (SCREEN_WIDTH / 2) + (120 / 2), y + 40, color, FALSE);


	//	// テキスト描画
	//	DrawFormatString((SCREEN_WIDTH / 2) - 40, y + 7, GetColor(255, 255, 255), i == 0 ? "START" : "END");
	// 
	//}

	int y = (SCREEN_HEIGHT / 2) + 50 +(40 + 10);
	DrawBox((SCREEN_WIDTH / 2) - (120 / 2), y, (SCREEN_WIDTH / 2) + (120 / 2), y + 40, GetColor(255, 255, 0), FALSE);

	//テキスト描画
	DrawFormatString((SCREEN_WIDTH / 2) - 40, y + 7, GetColor(255, 255, 255), "START");

	SetFontSize(12);

}

void TitleScene::Finalize()
{
}

eSceneType TitleScene::GetNowSceneType() const
{
	return eSceneType::TITLE;
}
