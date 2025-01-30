#include "SceneBase.h"

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

	return GetNowSceneType();
}

void SceneBase::Draw() const
{
	for (GameObject* obj : objects)
	{
		obj->Draw(camera_location);
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
	if (obj == nullptr) return; // 安全対策

	auto it = std::find(objects.begin(), objects.end(), obj);

	if (it != objects.end()) {
		//見つかった場合、オブジェクトを削除
		(*it)->Finalize(); //終了処理
		delete* it;         //メモリ解放
		objects.erase(it);  //リストから削除
	}
}
