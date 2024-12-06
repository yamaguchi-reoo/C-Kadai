#include "SceneBase.h"

SceneBase::SceneBase()
{
}

SceneBase::~SceneBase()
{
}

void SceneBase::Initialize()
{
}

eSceneType SceneBase::Update()
{
	return GetNowSceneType();
}

void SceneBase::Draw() const
{
}

void SceneBase::Finalize()
{
}
