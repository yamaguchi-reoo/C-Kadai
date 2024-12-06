#pragma once
#include <vector>

enum eSceneType
{
	TETLE,
	GAME_MAIN,
	RESULT
};

class SceneBase
{
protected:


public:
	//コンストラクタ
	SceneBase();
	//デストラクタ
	~SceneBase();

	virtual void Initialize();		//初期化処理
	virtual eSceneType Update();	//更新処理
	virtual void Draw() const;		//描画処理
	virtual void Finalize();		//終了時処理


	virtual eSceneType GetNowSceneType()const = 0;
protected:
};

