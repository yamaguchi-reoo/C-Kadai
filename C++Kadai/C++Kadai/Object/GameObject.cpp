#include <DxLib.h>
#include "GameObject.h"

GameObject::GameObject() : location(),box_size(),image(NULL),object_type(), flip_flag(FALSE)
{
}

GameObject::~GameObject()
{
}

void GameObject::Initialize(Vector2D _location, Vector2D _box_size)
{
	//位置を設定
	location = _location;
	//サイズを設定
	box_size = _box_size;

	//画像を設定
	//image = NULL;
}

void GameObject::Update()
{
}

void GameObject::Draw(Vector2D _camera_location) const
{
	//メンバの情報を基に画像を描画する
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image, TRUE, flip_flag);

	Vector2D upper_left = location - (box_size / 2.0f);
	Vector2D lower_right = location + (box_size / 2.0f);

	DrawBoxAA(upper_left.x, upper_left.y, lower_right.x, lower_right.y, GetColor(255, 0, 0), TRUE);
}

void GameObject::Finalize()
{
}

void GameObject::SetLocation(Vector2D _location)
{
}

Vector2D GameObject::GetLocation() const
{
	return this->location;
}

Vector2D GameObject::GetBoxSize() const
{
	return this->box_size;
}

eObjectType GameObject::GetObjectType()
{
	return eObjectType();
}

void GameObject::OnHitCollision(GameObject* hit_object)
{
}

void GameObject::CheckBoxCollision(GameObject* obj)
{
}
