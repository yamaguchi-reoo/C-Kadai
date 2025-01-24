#include <DxLib.h>
#include "Player.h"
#include "../../../Utility/InputControl.h"
#include "../../../Utility/ResourceManager.h"

Player::Player() : player_state(PlayerState::eIDLE),animation_data(),animation_count()
{
}

Player::~Player()
{
}

void Player::Initialize(Vector2D _location, Vector2D _box_size)
{
	__super::Initialize(_location, _box_size);

	hp = 5;
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

void Player::Update()
{
	//移動処理
	Movement();

	//アニメーション管理
	AnimationControl();
}

void Player::Draw(Vector2D _camera_location) const
{
	//親クラスに書かれた描画処理の内容を実行する
	__super::Draw(_camera_location);
}

void Player::Finalize()
{
	animation_data.clear();
}

void Player::Movement()
{
	//入力情報の取得
	InputControl* input = InputControl::GetInstance();

	//左右移動
	if (input->GetKey(KEY_INPUT_LEFT))player_state = PlayerState::eLEFT;
	if (input->GetKey(KEY_INPUT_RIGHT))player_state = PlayerState::eRIGHT;

	//ジャンプ
	if (input->GetKey(KEY_INPUT_UP))player_state = PlayerState::eJump;

	switch (player_state)
	{		
		//何も動いていない状態（待機）
	case PlayerState::eIDLE:
		//左右移動
		if (input->GetKey(KEY_INPUT_LEFT))player_state = PlayerState::eLEFT;
		else if (input->GetKey(KEY_INPUT_RIGHT))player_state = PlayerState::eRIGHT;
		//ジャンプ
		else if (input->GetKey(KEY_INPUT_UP))player_state = PlayerState::eJump;

		break;
	case PlayerState::eLEFT:
		velocity.x -= 0.5;
		//左キーが離されたら
		if (!input->GetKey(KEY_INPUT_LEFT))player_state = PlayerState::eIDLE;
		break;
	case PlayerState::eRIGHT:
		velocity.x += 0.5;
		//左キーが離されたら
		if (!input->GetKey(KEY_INPUT_RIGHT))player_state = PlayerState::eIDLE;
		break;
	case PlayerState::eJump:
		break;
	case PlayerState::eDamege:
		break;
	case PlayerState::eDEAD:
		break;
	default:
		break;
	}

	// 位置を更新
	location += velocity;
}


void Player::AnimationControl()
{
	//カウントの更新
	animation_count++;

	//
	if (animation_count >= 30)
	{
		//
		animation_count = 0;
		//
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
}

void Player::InvincibleState()
{
}

PlayerState Player::GetPlayerState()
{
	return PlayerState();
}

int Player::GetPlayerHp()
{
	return 0;
}
