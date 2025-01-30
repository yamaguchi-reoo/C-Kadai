#include "CharacterBase.h"
#define GRAVITY (9.087f)

void CharacterBase::Initialize(Vector2D _location, Vector2D _box_size)
{
	__super::Initialize(_location, _box_size);
}

void CharacterBase::Update()
{
	//重力加速度
	g_velocity += GRAVITY / 444.0f;
	velocity.y += g_velocity;// 重力を加算
	location.y += velocity.y;


	//!!!地面との当たり判定ができ次第削除!!!!
	if (location.y >= 400.0f)
	{
		location.y = 400.0f;
		velocity.y = 0.0f;
		g_velocity = 0.0f;
	}
}

void CharacterBase::Draw(Vector2D _camera_location) const
{
	//親クラスに書かれた描画処理の内容を実行する
	__super::Draw(_camera_location);
}

void CharacterBase::Finalize()
{
}

void CharacterBase::ApplyDamage(int _damage)
{
}

void CharacterBase::OnDamaged(int _damage)
{
}

void CharacterBase::OnHitCollision(GameObject* hit_object)
{
}
