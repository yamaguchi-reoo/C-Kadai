#include "GoalFlag.h"
#include <DxLib.h>

GoalFlag::GoalFlag()
{
	
}

GoalFlag::~GoalFlag()
{
}

void GoalFlag::Initialize(Vector2D _location, Vector2D _box_size)
{
	__super::Initialize(_location, _box_size);
	object_type = GIMMICK;
}

void GoalFlag::Update()
{
	__super::Update();
}


void GoalFlag::Draw(Vector2D offset, double rate) const
{
	__super::Draw(offset, rate);
	DrawString(offset.x + (box_size.x / 2) - 17, offset.y + (box_size.y / 2) - 4, "Ç≤Å[ÇÈ", GetColor(255, 0, 255), FALSE);
}

void GoalFlag::Finalize()
{
}
