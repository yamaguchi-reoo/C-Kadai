#include "CharacterBase.h"

CharacterBase::CharacterBase()
{
}

CharacterBase::~CharacterBase()
{
}

void CharacterBase::Initialize(Vector2D _location, Vector2D _box_size)
{
	__super::Initialize(_location, _box_size);
}

void CharacterBase::Update()
{
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

void CharacterBase::OnDamaged(int _damege)
{
}

void CharacterBase::OnHitCollision(GameObject* hit_object)
{
}
