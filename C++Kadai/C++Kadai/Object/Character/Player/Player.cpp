#include <DxLib.h>
#include "Player.h"
#include "../../../Utility/UtilityList.h"
#include"../../../Object/Stage/Ground.h"
#include "../../../Scene/SceneManager.h"
#include "../../../Scene/GameScene/GameMainScene.h"

#include <iostream>
#include <algorithm>

#define MAX_INVINCIBLE_TIME 300

Player::Player() : player_state(PlayerState::eIDLE),animation_data(), invincible_flg(),invincible_time()
{
}

Player::~Player()
{
}

void Player::Initialize(Vector2D _location, Vector2D _box_size)
{
	__super::Initialize(_location, _box_size);

	object_type = PLAYER;
	hp = 5;
	velocity = { 0.0f };
	g_velocity = 0.0f;
	//jump_flag = false;
	invincible_flg = false;
	invincible_time = 0;


	//アニメーション画像の読み込み
	ResourceManager* rm = ResourceManager::GetInstance();
	std::vector<int> tmp;
	tmp = rm->GetImages("Resource/Images/Tri-pilot/1.png");
	animation_data.push_back(tmp[0]);
	tmp = rm->GetImages("Resource/Images/Tri-pilot/2.png");
	animation_data.push_back(tmp[0]);

	image = animation_data[0];
	//image = NULL;

	animation_count = 0;
}

void Player::Update()
{
	__super::Update();

	//移動処理
	Movement();

	//アニメーション管理
	AnimationControl();

	//無敵時間
	if (invincible_flg)
	{
		invincible_time++;
		if (invincible_time >= MAX_INVINCIBLE_TIME)
		{
			invincible_flg = false;
			invincible_time = 0;
		}
	}
}

void Player::Draw(Vector2D offset, double rate) const
{
	//ダメージを受けたら点滅するように
	if (damage_flg) {
		if (count % 5 == 0) {
			//親クラスに書かれた描画処理の内容を実行する
			__super::Draw(offset, 1.0);
		}
	}
	//無敵時間中はあり得んくらいチカチカさせる
	else if (invincible_flg)
	{
		if (invincible_time % 2 == 0)
		{
			//親クラスに書かれた描画処理の内容を実行する
			__super::Draw(offset, 1.0);
		}
	}
	else
	{
		//親クラスに書かれた描画処理の内容を実行する
		__super::Draw(offset, 1.0);
	}

	//一時的にフォントサイズを変更する
	int oldFontSize = GetFontSize();

	//残機描画
	SetFontSize(28);
	DrawFormatString(62, 20, GetColor(255, 255, 255), "x %d", hp);
	//メンバの情報を基に画像を描画する
	DrawRotaGraphF(35,32, 0.5, 0.0, image, TRUE, FALSE);

	//元のフォントサイズに戻す
	SetFontSize(oldFontSize);


	DebugInfomation::Add("flg", jump_flag);
	DebugInfomation::Add("camera", offset.x);
	DebugInfomation::Add("damage_flg", damage_flg);
	DebugInfomation::Add("velo", velocity.x);
	DebugInfomation::Add("invincible_flg", invincible_flg);
	DebugInfomation::Add("invincible_time", invincible_time);

}

void Player::Finalize()
{
	__super::Finalize();
	animation_data.clear();
}

void Player::Movement()
{
	//入力情報の取得
	InputControl* input = InputControl::GetInstance();

	switch (player_state)
	{		
		//何も動いていない状態（待機）
	case PlayerState::eIDLE:

		// 待機状態（キーが押されていないときの減速処理）
		if (velocity.x < -1e-6f) // 左向きの速度を減らす
		{
			velocity.x = Min<float>(velocity.x + 0.15f, 0.0f); // 徐々に0に近づける
		}
		else if (velocity.x > 1e-6f) // 右向きの速度を減らす
		{
			velocity.x = Max<float>(velocity.x - 0.15f, 0.0f); // 徐々に0に近づける
		}

		//左右移動
		if (input->GetKey(KEY_INPUT_LEFT))player_state = PlayerState::eLEFT;
		else if (input->GetKey(KEY_INPUT_RIGHT))player_state = PlayerState::eRIGHT;

		//ジャンプ
		if (!jump_flag) {
			if (input->GetKeyDown(KEY_INPUT_UP) || input->GetKeyDown(KEY_INPUT_SPACE))
			{
				player_state = PlayerState::eJUMP;
			}
		}
		break;
		//左矢印キーを押したら
	case PlayerState::eLEFT:
		velocity.x -= 0.25;
		flip_flg = TRUE;      // 左向きフラグをセット

		//左キーが離されたら
		if (!input->GetKey(KEY_INPUT_LEFT))player_state = PlayerState::eIDLE;

		//ジャンプ
		if (!jump_flag) {
			if (input->GetKeyDown(KEY_INPUT_UP) || input->GetKeyDown(KEY_INPUT_SPACE))
			{
				player_state = PlayerState::eJUMP;
			}
		}
		break;
		//右矢印キーを押したら
	case PlayerState::eRIGHT:
		velocity.x += 0.25;
		flip_flg = FALSE;      // 右向きフラグをセット

		//左キーが離されたら
		if (!input->GetKey(KEY_INPUT_RIGHT))player_state = PlayerState::eIDLE;

		//ジャンプ
		if (!jump_flag) {
			if (input->GetKeyDown(KEY_INPUT_UP) || input->GetKeyDown(KEY_INPUT_SPACE))
			{
				player_state = PlayerState::eJUMP;
			}
		}
		break;
		//ジャンプキー押したら
	case PlayerState::eJUMP:
		jump_flag = true;
		velocity.y -= 4.0f;
		//ジャンプキーが離されたら
		if (!input->GetKeyDown(KEY_INPUT_UP))player_state = PlayerState::eIDLE;
		break;
	case PlayerState::eDAMAGE:
		break;
	case PlayerState::eDEAD:
		break;
	default:
		break;
	}

	//最大速度を制限
	float max_speed = 5.0f;  // 最大速度
	velocity.x = Min<float>(Max<float>(velocity.x, -max_speed), max_speed);


	//位置を更新
	location += velocity;
}

void Player::AnimationControl()
{
	//カウントの更新
	animation_count++;

	//
	if (animation_count >= 10)
	{
		//カウントを0クリアする
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

void Player::OnHitCollision(GameObject* hit_object)
{
	__super::OnHitCollision(hit_object);

	if (hit_object->GetObjectType() == ENEMY_RED || hit_object->GetObjectType() == ENEMY_PURPLE)
	{
		//ダメージ受けて一定時間は無敵に
		if (damage_flg)
		{
			return;
		}

		float enemy_velocity = hit_object->GetVelocity().x;
		//ノックバック
		//プレイヤーが右にいるなら右にノックバック
		if (this->location.x > hit_object->GetLocation().x)
		{
			// 敵が左に移動中なら、プレイヤーは右にノックバック
			//if (enemy_velocity < 0.0f)
			//{
			//	velocity.x = 5.0f;  // ノックバックの力を右に設定
			//}
			velocity.x = 5.0f;
		}
		//プレイヤーが左にいるなら左にノックバック
		else if(this->location.x < hit_object->GetLocation().x)
		{
			// 敵が右に移動中なら、プレイヤーは左にノックバック
			//if (enemy_velocity > 0.0f)
			//{
			//	velocity.x = -5.0f;  // ノックバックの力を左に設定
			//}
			velocity.x = -5.0f;
		}

		__super::ApplyDamage(1);
	}

	//ゲームメイン取得
	SceneManager* scene_manager = SceneManager::GetInstance();
	GameMainScene* game_main = scene_manager->GetGameMainScene();

	//エナジードリンクを拾ったとき
	if (hit_object->GetObjectType() == ITEM_DRINK)
	{
		InvincibleState();
	}
	//コインを拾ったとき
	else if(hit_object->GetObjectType() == ITEM_COIN)
	{
		if (game_main != nullptr) {
			game_main->AddScore(100);
		}
	}

	//ギミックに当たった時
	if (hit_object->GetObjectType() == GIMMICK)
	{
		game_main->ChangeGameState(eGameState::GAME_CLEAR);
	}
}

void Player::InvincibleState()
{
	invincible_flg = true;
}

PlayerState Player::GetPlayerState()
{
	return PlayerState();
}

int Player::GetPlayerHp()
{
	return 0;
}
