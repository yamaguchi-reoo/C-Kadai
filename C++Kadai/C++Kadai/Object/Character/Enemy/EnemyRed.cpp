#include "EnemyRed.h"

EnemyRed::EnemyRed()
{
}

EnemyRed::~EnemyRed()
{
}

void EnemyRed::Initialize(Vector2D _location, Vector2D _box_size)
{
	__super::Initialize(_location, _box_size);

	hp = 5;
	velocity = { 0.0f };
	g_velocity = 0.0f;

	//アニメーション画像の読み込み
	ResourceManager* rm = ResourceManager::GetInstance();
	std::vector<int> tmp;
	tmp = rm->GetImages("Resource/Images/BoxEnemy/1.png");
	animation_data.push_back(tmp[0]);
	tmp = rm->GetImages("Resource/Images/BoxEnemy/2.png");
	animation_data.push_back(tmp[0]);

	image = animation_data[0];
	//image = NULL;

	animation_count = 0;
}

void EnemyRed::Update()
{
	__super::Update();

}

void EnemyRed::Draw(Vector2D offset, double rate) const
{
	//親クラスに書かれた描画処理の内容を実行する
	__super::Draw(offset, 0.7);

}

void EnemyRed::Finalize()
{
}
