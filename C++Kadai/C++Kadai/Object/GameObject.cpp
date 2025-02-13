#include <DxLib.h>
#include "GameObject.h"
#include <math.h>
#include "../common.h"

GameObject::GameObject() : location(), box_size(), image(NULL), object_type(), flip_flg(FALSE), move(), stage_hit_flg()
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

void GameObject::Draw(Vector2D offset, double rate) const
{
	// 描画範囲の判定
	if (offset.x + box_size.x >= 0 && offset.x < SCREEN_WIDTH) 
	{
		//メンバの情報を基に画像を描画する
		DrawRotaGraphF(offset.x + (box_size.x / 2), offset.y + (box_size.y / 2), rate, 0.0, image, TRUE, flip_flg);
		// デバッグ用の当たり判定ボックス描画
		DrawBoxAA(offset.x, offset.y, offset.x + box_size.x, offset.y + box_size.y, GetColor(255, 0, 0), FALSE);
	}

	//描画範囲の可視化
	DrawBoxAA(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, GetColor(255, 0, 0), FALSE);
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
	return this->object_type;
}

void GameObject::OnHitCollision(GameObject* hit_object)
{
	
}

bool GameObject::CheckBoxCollision(GameObject* obj)
{
	//自分の左上座標
	Vector2D my_pos = location;
	//自分の幅と高さの半分
	Vector2D my_size = box_size / 2.0f;

	//相手の左上座標
	Vector2D sub_pos = obj->GetLocation();
	//相手の幅と高さの半分
	Vector2D sub_size = obj->GetBoxSize() / 2.0f;

	//中心座標の差分
	Vector2D diff = (my_pos + my_size) - (sub_pos + sub_size);

	//当たり判定の演算
	return (fabsf(diff.x) <= my_size.x + sub_size.x &&
			fabsf(diff.y) <= my_size.y + sub_size.y);

}
