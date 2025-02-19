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
	__super::Draw(offset, 1.0f);

	//DrawBox(offset.x, offset.y, offset.x + box_size.x, offset.y + box_size.y, GetColor(255, 255, 255), TRUE);
	DrawString(offset.x + (box_size.x / 2), offset.y + (box_size.y / 2), "‚²", GetColor(255, 0, 0), FALSE);
}

void GoalFlag::Finalize()
{
}
