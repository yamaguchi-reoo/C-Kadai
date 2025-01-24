#include "Player.h"

Player::Player() : player_state(PlayerState::eIDLE),animation_data()
{
}

Player::~Player()
{
}

void Player::Initialize(Vector2D _location, Vector2D _box_size)
{
	//box_size
}

void Player::Update()
{
}

void Player::Draw(Vector2D _camera_location) const
{
}

void Player::Finalize()
{
}

void Player::Movement()
{
}

void Player::AnimationControl()
{
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
