#include "DxLib.h"
#include "SceneManager.h"

SceneManager::SceneManager() :current_scene(nullptr)
{
}

SceneManager::~SceneManager()
{

}

void SceneManager::Initialize()
{
}

void SceneManager::Update()
{

}

void SceneManager::Finalize()
{
}

void SceneManager::Draw() const
{
}

void SceneManager::ChangeScene(eSceneType type)
{
}

SceneBase* SceneManager::CreateScene(eSceneType type)
{
	return nullptr;
}
