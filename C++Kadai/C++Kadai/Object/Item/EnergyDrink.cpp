#include "EnergyDrink.h"
#include <DxLib.h>

EnergyDrink::EnergyDrink()
{
}

EnergyDrink::~EnergyDrink()
{
}

void EnergyDrink::Initialize(Vector2D _location, Vector2D _box_size)
{
	__super::Initialize(_location, _box_size);
}

void EnergyDrink::Update()
{
	__super::Update();
}

void EnergyDrink::Draw(Vector2D offset, double rate) const
{
	__super::Draw(offset, 1.0f);
	DrawString(offset.x + (box_size.x / 2) - 3, offset.y + (box_size.y / 2) - 4, "飲", GetColor(0, 255, 0), FALSE);
}

void EnergyDrink::Finalize()
{
}
