#include "Coin.h"
#include <DxLib.h>

Coin::Coin()
{
}

Coin::~Coin()
{
}

void Coin::Initialize(Vector2D _location, Vector2D _box_size)
{
	__super::Initialize(_location, _box_size);

	object_type = ITEM_COIN;
	score = 100;
}

void Coin::Update()
{
	__super::Update();
}

void Coin::Draw(Vector2D offset, double rate) const
{
	__super::Draw(offset, 1.0f);
	DrawString(offset.x + (box_size.x / 2) - 17, offset.y + (box_size.y / 2) - 4, "コイン", GetColor(255, 255, 0) , FALSE);
}

void Coin::Finalize()
{
}
