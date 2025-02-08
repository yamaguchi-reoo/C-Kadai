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

}

void EnemyRed::Draw(Vector2D offset) const
{
	//親クラスに書かれた描画処理の内容を実行する
	__super::Draw(offset);

}

void EnemyRed::Finalize()
{
}
