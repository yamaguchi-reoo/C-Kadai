#include "SceneBase.h"
#include "../common.h"

SceneBase::SceneBase()
{
}

SceneBase::~SceneBase()
{
	this->Finalize();
}

void SceneBase::Initialize()
{
}

eSceneType SceneBase::Update()
{
	for (GameObject* obj : objects)
	{
		obj->Update();
	}

	// 二重ループで衝突判定
	for (int i = 0; i < objects.size(); i++)
	{
		for (int j = i + 1; j < objects.size(); j++) // j < objects.size() に修正
		{
			if (objects[i]->CheckBoxCollision(objects[j]))
			{
				objects[i]->OnHitCollision(objects[j]);
				objects[j]->OnHitCollision(objects[i]);
			}
		}
	}

	// プレイヤーの取得
	GameObject* player = nullptr;
	for (auto obj : objects)
	{
		if (obj->GetObjectType() == PLAYER)
		{
			player = obj;
			break;
		}
	}
	// プレイヤーが存在するならカメラを追従させる
	if (player)
	{
		float screen_half_width = SCREEN_WIDTH / 2;				// 画面の半分の幅
		float stage_limit_left = 0.0f;							// ステージの左端
		float stage_limit_right = 40 * BOX_SIZE - SCREEN_WIDTH; // ステージの右端 

		// プレイヤーの位置 - 画面の半分の幅 ＝ カメラ位置
		camera_location.x = player->GetLocation().x - screen_half_width;

		// 画面端ではスクロールしないよう制限
		if (camera_location.x < stage_limit_left) camera_location.x = stage_limit_left;
		if (camera_location.x > stage_limit_right) camera_location.x = stage_limit_right;
	}


	return GetNowSceneType();
}

void SceneBase::Draw() const
{
	for (GameObject* obj : objects)
	{
		Vector2D draw_location = obj->GetLocation() - camera_location;
		obj->Draw(draw_location);
	}
}

void SceneBase::Finalize()
{
	//オブジェクトが空の場合は処理をスキップ
	if (objects.empty())
	{
		return;
	}

	for (GameObject* obj : objects)
	{
		obj->Finalize();

		delete obj;
	}

	objects.clear();
}

void SceneBase::DeleteObject(GameObject* obj)
{
	if (obj == nullptr) return;

	auto it = std::find(objects.begin(), objects.end(), obj);

	if (it != objects.end()) {
		//見つかった場合、オブジェクトを削除
		(*it)->Finalize(); //終了処理
		delete* it;         //メモリ解放
		objects.erase(it);  //リストから削除
	}
}
