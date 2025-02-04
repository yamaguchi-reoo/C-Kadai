#pragma once
#include "../SceneBase.h"
#include "../../Object/Character/Player/Player.h"
#include "../../Object/Character/Enemy/EnemyRed.h"
#include "../../Object/Stage/StageManager.h"

class GameMainScene : 
	public SceneBase
{
private:
	//Player* player;
	//EnemyRed* enemy_r;

	StageManager stage_manager;
public:
	GameMainScene();
	~GameMainScene();

	void Initialize() override;		//初期化処理
	eSceneType Update() override;	//更新処理
	void Draw() const override;		//描画処理
	void Finalize() override;		//終了時処理

	eSceneType GetNowSceneType()const override;

	void LoadStage();
	void SetStage(const StageData& block);
};

