#pragma once
#include "../SceneBase.h"
class TitleScene :
    public SceneBase
{
public:
	TitleScene();
	~TitleScene();

	void Initialize() override;		//初期化処理
	eSceneType Update() override;	//更新処理
	void Draw() const override;		//描画処理
	void Finalize() override;		//終了時処理
};
