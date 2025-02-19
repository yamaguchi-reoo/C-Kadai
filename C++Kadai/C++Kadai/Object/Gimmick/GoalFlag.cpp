#include "GoalFlag.h"
#include <DxLib.h>
#include "../../Utility/ResourceManager.h"

GoalFlag::GoalFlag():animation_data()
{
	
}

GoalFlag::~GoalFlag()
{
}

void GoalFlag::Initialize(Vector2D _location, Vector2D _box_size)
{
	__super::Initialize(_location, _box_size);
	object_type = GIMMICK;

	ResourceManager* rm = ResourceManager::GetInstance();
	std::vector<int> tmp;
	tmp = rm->GetImages("Resource/Images/Goal.png");
	animation_data.push_back(tmp[0]);

	image = animation_data[0];

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
