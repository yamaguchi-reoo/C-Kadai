#pragma once
#include "EnemyBase.h"
class EnemyPurple :
    public EnemyBase
{
private:
public:
	EnemyPurple();
	~EnemyPurple();

	//初期化処理
	void Initialize(Vector2D _location, Vector2D _box_size) override;
	//更新処理
	void Update()override;
	//描画処理
	void Draw(Vector2D _camera_location) const override;
	//終了時処理
	void Finalize()override;
};

