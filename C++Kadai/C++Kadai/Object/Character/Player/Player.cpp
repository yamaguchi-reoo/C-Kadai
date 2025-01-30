#include <DxLib.h>
#include "Player.h"
#include "../../../Utility/InputControl.h"
#include "../../../Utility/ResourceManager.h"
#include "../../../Utility/UserTemplate.h"
#include "../../../Utility/DebugInfomation.h"

#define GRAVITY (9.087f)

PLAYER::PLAYER() : player_state(PlayerState::eIDLE),animation_data(),animation_count(),g_velocity(0.0f),jump_flag(false)
{
}

PLAYER::~PLAYER()
{
}

void PLAYER::Initialize(Vector2D _location, Vector2D _box_size)
{
	__super::Initialize(_location, _box_size);

	object_type = eObjectType::PLAYER;
	hp = 5;
	velocity = { 0.0f };
	g_velocity = 0.0f;

	//アニメーション画像の読み込み
	ResourceManager* rm = ResourceManager::GetInstance();
	std::vector<int> tmp;
	tmp = rm->GetImages("Resource/Images/Tri-pilot/1.png");
	animation_data.push_back(tmp[0]);
	tmp = rm->GetImages("Resource/Images/Tri-pilot/2.png");
	animation_data.push_back(tmp[0]);

	image = animation_data[0];

	animation_count = 0;
}

void PLAYER::Update()
{
	//移動処理
	Movement();

	//アニメーション管理
	AnimationControl();
}

void PLAYER::Draw(Vector2D _camera_location) const
{
	//親クラスに書かれた描画処理の内容を実行する
	__super::Draw(_camera_location);

	DebugInfomation::Add("flg", jump_flag);
}

void PLAYER::Finalize()
{
	animation_data.clear();
}

void PLAYER::Movement()
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
			velocity.x = Min<float>(velocity.x + 0.1f, 0.0f); // 徐々に0に近づける
		}
		else if (velocity.x > 1e-6f) // 右向きの速度を減らす
		{
			velocity.x = Max<float>(velocity.x - 0.1f, 0.0f); // 徐々に0に近づける
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
		flip_flag = TRUE;      // 左向きフラグをセット

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
		flip_flag = FALSE;      // 左向きフラグをセット

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

	// 最大速度を制限
	float max_speed = 5.0f;  // 最大速度
	velocity.x = Min<float>(Max<float>(velocity.x, -max_speed), max_speed);

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
		jump_flag = false;
	}

	// 位置を更新
	location += velocity;
}


void PLAYER::AnimationControl()
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

void PLAYER::OnHitCollision(GameObject* hit_object)
{
}

void PLAYER::InvincibleState()
{
}

PlayerState PLAYER::GetPlayerState()
{
	return PlayerState();
}

int PLAYER::GetPlayerHp()
{
	return 0;
}
