#include "GameMainScene.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "../../Utility/InputControl.h"
#include <DxLib.h>
#include "../../Object/Character/Player/Player.h"
#include "../../Object/Character/Enemy/EnemyRed.h"
#include "../../Object/Stage/Ground.h"

GameMainScene::GameMainScene():stage_width_num(0), stage_height_num(0), stage_data{ 0 }
{
}

GameMainScene::~GameMainScene()
{
}

void GameMainScene::Initialize()
{
	//CreateObject<Player>(Vector2D(32.0f,300.0f), Vector2D(64.0f));
	//CreateObject<EnemyRed>(Vector2D(500.0f,300.0f), Vector2D(64.0f));

	LoadStage();
	//SetStage();
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

	//ステージデータの描画
	for (int i = 0; i < stage_height_num; i++) {
		for (int j = 0; j < stage_width_num; j++) {
			std::cout << stage_data[i][j] << " ";
			DrawFormatString(j * 32,i * 32, GetColor(255, 255, 255), "%d", stage_data[i][j]);
			//DrawFormatString(0, 30, GetColor(255, 255, 255), "幅 %d  高さ %d", stage_width_num, stage_height_num);
		}
		
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
	std::ifstream file("Resource/file/stage.csv");

	if (!file) {
		std::cerr << "ファイルを開けませんでした: " << std::endl;
		return;
	}
	// 1行目を読み込んでステージ幅と高さを取得
	std::string line;

	//fileから1行読み込んで、line に格納。
	if (std::getline(file, line)) {
		//文字列を解析するためのストリームを作成。
		std::stringstream ss(line);
		std::string width, height;

		// カンマで分割して幅と高さを取得
		std::getline(ss, width, ',');
		std::getline(ss, height, ',');

		//文字列を整数に変換
		stage_width_num = std::stoi(width);   // ステージ幅
		stage_height_num = std::stoi(height); // ステージ高さ
	}

	//ステージデータの読み込み（CSVの2行目以降）
	for (int i = 0; i < stage_height_num; i++) {
		//1行ずつ読み込む
		if (std::getline(file, line)) {
			std::stringstream ss(line);
			for (int j = 0; j < stage_width_num; j++) {
				//カンマ区切りでデータを取得
				std::string value;
				if (std::getline(ss, value, ',')) {
					//文字列を整数に変換してステージデータに格納
					stage_data[i][j] = std::stoi(value);
				}
			}
		}
	}

	file.close();

	SetStage();
}

void GameMainScene::SetStage()
{

	for (int i = 0; i < stage_height_num; i++) {
		for (int j = 0; j < stage_width_num; j++) {
			switch (stage_data[i][j])
			{
			case 0:
				break;
			case BLOCK:
				CreateObject<Ground>(Vector2D(j * BOX_SIZE, i * BOX_SIZE), Vector2D(32.0f));
				break;
			case PLAYER:
				CreateObject<Player>(Vector2D(j * BOX_SIZE, i * BOX_SIZE), Vector2D(64.0f));
				break;
			case ENEMY:
				CreateObject<EnemyRed>(Vector2D(j * BOX_SIZE, i * BOX_SIZE), Vector2D(64.0f));
				break;
			default:
				break;
			}
		}
	}
}
