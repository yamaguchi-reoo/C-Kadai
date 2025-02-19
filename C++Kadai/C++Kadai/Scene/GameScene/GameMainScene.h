#pragma once
#include "../SceneBase.h"
#include "../../Object/Stage/StageManager.h"
#include "../../common.h"

enum class eGameState
{
	GAME_MAIN = 0,
	GAME_CLEAR,
	GAMEO_OVER
};

class GameMainScene :
	public SceneBase
{
private:
	int stage_width_num;    //ステージの横のブロック数
	int stage_height_num;   //ステージの縦のブロック数

	//ステージデータ格納用
	int stage_data[STAGE_MAX_HEIGHT][STAGE_MAX_WIDTH];

	bool draw_data_flg;		//ステージデータの描画フラグ

	int score;

	//StageManager stage_manager;

	//ゲームメインの状態
	eGameState game_state;
	eGameState change_state;
public:
	GameMainScene();
	~GameMainScene();

	void Initialize() override;		//初期化処理
	eSceneType Update() override;	//更新処理
	void Draw() const override;		//描画処理
	void Finalize() override;		//終了時処理

	eSceneType GetNowSceneType()const override;

	//ステージデータを読み込む
	void LoadStage();

	//ステージデータを生成
	void SetStage();

	//カメラの更新
	void UpdateCamera();

	//スコア加算
	void AddScore(int _score);

	//
	void ChangeGameState(eGameState _state);

	void GameClear();
	void GameOver();

};

