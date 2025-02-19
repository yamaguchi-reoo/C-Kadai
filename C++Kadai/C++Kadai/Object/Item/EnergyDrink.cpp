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
	object_type = ITEM_DRINK;
}

void EnergyDrink::Update()
{
	__super::Update();
}

void EnergyDrink::Draw(Vector2D offset, double rate) const
{
	__super::Draw(offset, 1.0f);
	//DrawString(offset.x + (box_size.x / 2) - 3, offset.y + (box_size.y / 2) - 4, "飲", GetColor(0, 255, 0), FALSE);
	DrawBox(offset.x, offset.y, offset.x + box_size.x, offset.y + box_size.y, GetColor(0, 255, 180), TRUE);

	//DrawFormatString(20, 300, GetColor(255, 255, 255), "%d", delete_flg);
}

void EnergyDrink::Finalize()
{
	__super::Finalize();
}
