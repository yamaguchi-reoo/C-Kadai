#pragma once
#include "../SceneBase.h"
#include "../../Object/Character/Player/Player.h"
#include "../../Object/Character/Enemy/EnemyRed.h"
#include "../../Object/Stage/StageManager.h"

#define STAGE_MAX_WIDTH 700
#define STAGE_MAX_HEIGHT 700


class GameMainScene :
	public SceneBase
{
private:
	//Player* player;
	//EnemyRed* enemy_r;

	int stage_width_num;    //ステージの横のブロック数
	int stage_height_num;   //ステージの縦のブロック数

	int stage_data[STAGE_MAX_HEIGHT][STAGE_MAX_WIDTH];

	StageManager stage_manager;
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

	void UpdateCamera();
};

