#pragma once
#include <vector>
#include "../Object/GameObject.h"

enum class eSceneType
{
	TITLE = 0,
	GAME_MAIN,
	RESULT,
	END
};

class SceneBase
{
protected:
	std::vector<GameObject*>objects;
	Vector2D camera_location;

	int cursor = 0;

public:
	//コンストラクタ
	SceneBase();
	//デストラクタ
	virtual ~SceneBase();

	virtual void Initialize();		//初期化処理
	virtual eSceneType Update();	//更新処理
	virtual void Draw() const;		//描画処理
	virtual void Finalize();		//終了時処理

	//現在のシーンタイプを取得する
	virtual eSceneType GetNowSceneType()const = 0;

protected:
	//ゲームオブジェクトを生成するテンプレート関数
	template <class T>
	T* CreateObject(const Vector2D& _location, const Vector2D& _box_size)
	{
		//新しいインスタンスを生成
		T* new_instance = new T();

		GameObject* new_object = dynamic_cast<GameObject*>(new_instance);

		if (new_object == nullptr)
		{
			delete new_instance;
			throw("ゲームオブジェクトが生成できませんでした\n");
		}

		new_object->SetLocation(_location);

		new_object->Initialize(_location, _box_size);

		objects.push_back(new_object);

		//生成したインスタンスを返す
		return new_instance;
	}

public:
	void DeleteObject(GameObject* obj);
};

