#include "GimmickBase.h"

GimmickBase::GimmickBase()
{
}

GimmickBase::~GimmickBase()
{
}

void GimmickBase::Initialize(Vector2D _location, Vector2D _box_size)
{
	__super::Initialize(_location, _box_size);
}

void GimmickBase::Update()
{
	__super::Update();
}

void GimmickBase::Draw(Vector2D offset, double rate) const
{
	__super::Draw(offset, rate);
}

void GimmickBase::Finalize()
{
}
