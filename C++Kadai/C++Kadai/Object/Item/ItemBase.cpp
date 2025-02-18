#include "ItemBase.h"

ItemBase::ItemBase()
{

}

ItemBase::~ItemBase()
{
}

void ItemBase::Initialize(Vector2D _location, Vector2D _box_size)
{
	__super::Initialize(_location, _box_size);
}

void ItemBase::Update()
{
	__super::Update();
}

void ItemBase::Draw(Vector2D offset, double rate) const
{
	__super::Draw(offset, rate);
}

void ItemBase::Finalize()
{
	__super::Finalize();
}

void ItemBase::OnHitCollision(GameObject* hit_object)
{
	//ƒvƒŒƒCƒ„[‚É“–‚½‚Á‚½‚çíœ
	if (hit_object->GetObjectType() == PLAYER)
	{
		this->SetDeleteFlg();
	}
}
