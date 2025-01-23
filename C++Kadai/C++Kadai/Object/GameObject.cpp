#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::Initialize(Vector2D _location, Vector2D _box_size)
{
}

void GameObject::Update()
{
}

void GameObject::Draw(Vector2D _camera_location) const
{
}

void GameObject::Finalize()
{
}

void GameObject::SetLocation(Vector2D _location)
{
}

Vector2D GameObject::GetLocation() const
{
	return Vector2D();
}

Vector2D GameObject::GetBoxSize() const
{
	return Vector2D();
}

eObjectType GameObject::GetObjctType()
{
	return eObjectType();
}

void GameObject::OnHitCollision(GameObject* hit_object)
{
}

void GameObject::CheckBoxCollision(GameObject)
{
}
