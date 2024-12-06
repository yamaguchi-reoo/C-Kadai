#pragma once

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

	virtual void Initialize();
	virtual eSceneType Update();
	virtual void Draw()const;
	virtual void Finalize();

	virtual eSceneType GetNowSceneType()const = 0;
protected:
};

