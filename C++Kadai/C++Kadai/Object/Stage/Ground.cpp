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

void Ground::Draw(Vector2D _camera_location) const
{
	__super::Draw(_camera_location);
}

void Ground::Finalize()
{
}
