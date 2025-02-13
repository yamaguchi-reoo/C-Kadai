#include "EnemyBase.h"

EnemyBase::EnemyBase():enemy_state(eEnemyState::eIDLE), animation_data()
{
}

EnemyBase::~EnemyBase()
{
}

void EnemyBase::Initialize(Vector2D _location, Vector2D _box_size)
{
	__super::Initialize(_location, _box_size);
	object_type = ENEMY;
}

void EnemyBase::Update()
{
	__super::Update();

	Movement();
	AnimationControl();
}

void EnemyBase::Draw(Vector2D offset, double rate) const
{
	//親クラスに書かれた描画処理の内容を実行する
	__super::Draw(offset,rate);
}

void EnemyBase::Finalize()
{
}

void EnemyBase::Movement()
{

}

void EnemyBase::AnimationControl()
{
	//カウントの更新
	animation_count++;

	//
	if (animation_count >= 10)
	{
		////カウントを0クリアする
		animation_count = 0;
		//画像の切替を行う
		if (image == animation_data[0])
		{
			image = animation_data[1];
		}
		else
		{
			image = animation_data[0];
		}
	}
}

void EnemyBase::OnHitCollision(GameObject* hit_object)
{
	__super::OnHitCollision(hit_object);
}
