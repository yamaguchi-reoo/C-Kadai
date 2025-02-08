#include "EnemyBase.h"

EnemyBase::EnemyBase():enemy_state(eEnemyState::eIDLE), animation_data()
{
}

EnemyBase::~EnemyBase()
{
}

void EnemyBase::Initialize(Vector2D _location, Vector2D _box_size)
{
	__super::Initialize(_location, _box_size);
	object_type = ENEMY;
}

void EnemyBase::Update()
{
	__super::Update();
}

void EnemyBase::Draw(Vector2D _camera_location) const
{
	//親クラスに書かれた描画処理の内容を実行する
	__super::Draw(_camera_location);
}

void EnemyBase::Finalize()
{
}

void EnemyBase::Movement()
{
}

void EnemyBase::AnimationControl()
{
}

void EnemyBase::OnHitCollision(GameObject* hit_object)
{
	__super::OnHitCollision(hit_object);
}
