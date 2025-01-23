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
	auto it = std::find(objects.begin(), objects.end(), obj);

	if (it != objects.end()) {
		//見つかった場合、オブジェクトを削除
		(*it)->Finalize(); //終了処理
		delete* it;         //メモリ解放
		objects.erase(it);  //リストから削除
	}
}
