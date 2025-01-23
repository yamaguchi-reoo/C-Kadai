#pragma once
#include "../GameObject.h"

class GimmickBase : 
	public GameObject
{
public:
	//コンストラクタ
	GimmickBase();
	//デストラクタ
	~GimmickBase();

	//初期化処理
	virtual void Initialize(Vector2D _location, Vector2D _box_size) override;
	//更新処理
	virtual void Update()override;
	//描画処理
	virtual void Draw(Vector2D _camera_location) const override;
	//終了時処理
	virtual void Finalize()override;
};

