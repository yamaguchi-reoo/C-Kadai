#include "ItemBase.h"
#include "../../Scene/GameScene/GameMainScene.h"


ItemBase::ItemBase()
{

}

ItemBase::~ItemBase()
{
}

void ItemBase::Initialize(Vector2D _location, Vector2D _box_size)
{
	__super::Initialize(_location, _box_size);
}

void ItemBase::Update()
{
	__super::Update();
}

void ItemBase::Draw(Vector2D offset, double rate) const
{
	__super::Draw(offset, rate);
}

void ItemBase::Finalize()
{
	__super::Finalize();
}

void ItemBase::OnHitCollision(GameObject* hit_object)
{
	//プレイヤーに当たったら削除
	if (hit_object->GetObjectType() == PLAYER)
	{
		this->SetDeleteFlg();
		//もしプレイヤーに当たったのがコインなら
		if (this->object_type == ITEM_COIN)
		{
			SceneManager* scene_manager = SceneManager::GetInstance();
			GameMainScene* game_main = dynamic_cast<GameMainScene*>(scene_manager->GetCurrentScene());

			if (game_main != nullptr) {
				game_main->AddScore(score);
			}


		}
	}
}
