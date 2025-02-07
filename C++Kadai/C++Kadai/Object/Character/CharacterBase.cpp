#include "CharacterBase.h"
#include <iostream>
#include <algorithm>
#define GRAVITY (9.087f)

void CharacterBase::Initialize(Vector2D _location, Vector2D _box_size)
{
	__super::Initialize(_location, _box_size);
}

void CharacterBase::Update()
{
	//重力加速度
	g_velocity += GRAVITY / 444.0f;
	velocity.y += g_velocity;// 重力を加算
	location.y += velocity.y;


	//!!!地面との当たり判定ができ次第削除!!!!
	if (location.y >= 400.0f)
	{
		location.y = 400.0f;
		velocity.y = 0.0f;
		g_velocity = 0.0f;
	}
}

void CharacterBase::Draw(Vector2D _camera_location) const
{
	//親クラスに書かれた描画処理の内容を実行する
	__super::Draw(_camera_location);
}

void CharacterBase::Finalize()
{
}

void CharacterBase::ApplyDamage(int _damage)
{
}

void CharacterBase::OnDamaged(int _damage)
{
}

void CharacterBase::OnHitCollision(GameObject* hit_object)
{
	//if (hit_object->GetObjectType() == BLOCK)
	{
		// プレイヤーとオブジェクトのAABB情報を取得
		Vector2D playerMin = location;
		Vector2D playerMax = location + box_size;

		Vector2D objectMin = hit_object->GetLocation();
		Vector2D objectMax = objectMin + hit_object->GetBoxSize();

		// AABB衝突判定
		if (playerMax.x > objectMin.x && playerMin.x < objectMax.x &&
			playerMax.y > objectMin.y && playerMin.y < objectMax.y)
		{
			Vector2D pushBack(0, 0);

			// 衝突深度を計算
			float depthX = std::min(playerMax.x - objectMin.x, objectMax.x - playerMin.x);
			float depthY = std::min(playerMax.y - objectMin.y, objectMax.y - playerMin.y);

			// 一番浅い方向に押し戻す
			if (depthX < depthY)
			{
				if (playerMin.x < objectMin.x) pushBack.x = -depthX;	//左側から衝突
				else  pushBack.x = depthX;	//右側から衝突

				velocity.x = 0.0f;
			}
			else
			{
				if (playerMin.y < objectMin.y) {
					pushBack.y = -depthY; //上から衝突
					jump_flag = false;
				}
				else  pushBack.y = depthY;	//下から衝突
				velocity.y = 0.0f;
				g_velocity = 0.0f;
			}
			// 位置を修正
			location += pushBack;
		}

	}
}
