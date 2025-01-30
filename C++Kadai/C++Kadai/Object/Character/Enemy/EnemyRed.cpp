#include "EnemyRed.h"

EnemyRed::EnemyRed()
{
}

EnemyRed::~EnemyRed()
{
}

void EnemyRed::Initialize(Vector2D _location, Vector2D _box_size)
{
	__super::Initialize(_location, _box_size);

	hp = 5;
	velocity = { 0.0f };
	g_velocity = 0.0f;
}

void EnemyRed::Update()
{
	__super::Update();

	//!!!地面との当たり判定ができ次第削除!!!!
	if (location.y >= 400.0f)
	{
		location.y = 400.0f;
	}
}

void EnemyRed::Draw(Vector2D _camera_location) const
{
	//親クラスに書かれた描画処理の内容を実行する
	__super::Draw(_camera_location);

}

void EnemyRed::Finalize()
{
}
