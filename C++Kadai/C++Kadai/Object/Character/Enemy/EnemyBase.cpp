#include "EnemyBase.h"
#include <DxLib.h>

EnemyBase::EnemyBase():enemy_state(eEnemyState::eIDLE), animation_data()
{
}

EnemyBase::~EnemyBase()
{
}

void EnemyBase::Initialize(Vector2D _location, Vector2D _box_size)
{
	__super::Initialize(_location, _box_size);
	//object_type = ENEMY;

	velocity = { 0.0f };
	g_velocity = 0.0f;

	enemy_state = eEnemyState::eLEFT;
	flip_flg = TRUE;      //左向きフラグをセット
}

void EnemyBase::Update()
{
	__super::Update();

	Movement();
	//AnimationControl();
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
	//床と接触している時しか動けないように
	if (on_ground_flg) {
		switch (enemy_state)
		{
		case eEnemyState::eIDLE:

			break;
		case eEnemyState::eLEFT:
			flip_flg = TRUE;      //左向きフラグをセット
			velocity.x -= 0.2;
			break;
		case eEnemyState::eRIGHT:
			flip_flg = FALSE;      //右向きフラグをセット
			velocity.x += 0.2;
			break;
		case eEnemyState::eATTACK:
			break;
		case eEnemyState::eDEAD:
			break;
		default:
			break;
		}
	}

	// 最大速度を制限
	float max_speed = 2.5f;  // 最大速度
	velocity.x = Min<float>(Max<float>(velocity.x, -max_speed), max_speed);

	// 位置を更新
	location += velocity;
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
	//__super::OnHitCollision(hit_object);

	//当たったオブジェクトがプレイヤーだった場合
	if (hit_object->GetObjectType() == PLAYER) {
		//真正面でぶつかったら反対方向に進むように
		float player_x = hit_object->GetLocation().x;

		// プレイヤーが敵の右側にいる場合
		if (player_x > location.x) {
			if (enemy_state == eEnemyState::eRIGHT) {
				enemy_state = eEnemyState::eLEFT; // 右向きに変更
			}
		}
		// プレイヤーが敵の左側にいる場合
		else {
			if (enemy_state == eEnemyState::eLEFT) {
				enemy_state = eEnemyState::eRIGHT; // 左向きに変更
			}
		}

	}
	//当たったオブジェクトがブロックだった場合の処理
	if (hit_object->GetObjectType() == BLOCK)
	{
		//プレイヤーとオブジェクトの情報を取得
		Vector2D obj_location = location;
		Vector2D obj_size = location + box_size;

		Vector2D target_location = hit_object->GetLocation();
		Vector2D target_size = target_location + hit_object->GetBoxSize();

		//AABB衝突判定
		if (obj_size.x > target_location.x && obj_location.x < target_size.x &&
			obj_size.y > target_location.y && obj_location.y < target_size.y)
		{
			//押し戻し用のベクトル
			Vector2D push{ 0.0f, 0.0f };

			//めり込みの計算
			float depth_x = Min<float>(obj_size.x - target_location.x, target_size.x - obj_location.x);
			float depth_y = Min<float>(obj_size.y - target_location.y, target_size.y - obj_location.y);


			//衝突の深さ（めり込み量）を計算
			if (depth_x < depth_y)
			{
				// 横方向の衝突処理
				if (obj_location.x < target_location.x)
				{
					push.x = -depth_x;	//左側から衝突
					//向きを左向きに
					enemy_state = eEnemyState::eLEFT;
				}
				else
				{
					push.x = depth_x;	//右側から衝突
					//向きを右向きに
					enemy_state = eEnemyState::eRIGHT;
				}
				velocity.x = 0.0f;
			}
			else
			{
				//縦方向の衝突処理
				if (obj_location.y < target_location.y)
				{
					push.y = -depth_y;	  //上から衝突
					jump_flag = false;	  //ジャンプフラグをfalseにする
					on_ground_flg = true; //床と接触	

				}
				else
				{
					push.y = depth_y;	//下から衝突
					on_ground_flg = false;
				}
				velocity.y = 0.0f;
				g_velocity = 0.0f;
			}
			// 位置を修正
			location += push;
		}
	}
}
