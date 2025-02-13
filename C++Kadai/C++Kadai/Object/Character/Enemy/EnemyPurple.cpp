#include "EnemyPurple.h"
#include <DxLib.h>

EnemyPurple::EnemyPurple()
{
}

EnemyPurple::~EnemyPurple()
{
}

void EnemyPurple::Initialize(Vector2D _location, Vector2D _box_size)
{
	__super::Initialize(_location, _box_size);
	object_type = ENEMY_PURPLE;

}

void EnemyPurple::Update()
{
	__super::Update();
}

void EnemyPurple::Draw(Vector2D offset, double rate) const
{
	//親クラスに書かれた描画処理の内容を実行する
	__super::Draw(offset, 0.7);
	DrawString(offset.x + (box_size.x / 2) - 4, offset.y + (box_size.y / 2) - 3, "紫", GetColor(255, 0, 255),FALSE);
}

void EnemyPurple::Finalize()
{
}
