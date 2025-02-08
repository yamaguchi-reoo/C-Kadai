#include "Ground.h"
#include <DXlib.h>

void Ground::Initialize(Vector2D _location, Vector2D _box_size)
{
	__super::Initialize(_location, _box_size);

	object_type = BLOCK;
}

void Ground::Update()
{
}

void Ground::Draw(Vector2D offset) const
{
	__super::Draw(offset);
}

void Ground::Finalize()
{
}
