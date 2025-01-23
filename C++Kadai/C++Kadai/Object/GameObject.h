#pragma once
#include "../Utility/Vector2D.h"
enum class eObjectType
{
	Player,
	Enemy,
	Item,
	Gimmick,
	Block
};

class GameObject
{
protected:
	Vector2D location;
	Vector2D box_size;
	int image;
	eObjectType object_type;

public:
	GameObject();
	~GameObject();

	//初期化処理
	virtual void Initialize(Vector2D _location, Vector2D _box_size);	
	//更新処理
	virtual void Update();			
	//描画処理
	virtual void Draw(Vector2D _camera_location) const;
	//終了時処理
	virtual void Finalize();

public:

	void SetLocation(Vector2D _location);

	Vector2D GetLocation()const;

	Vector2D GetBoxSize()const;

	eObjectType GetObjctType();

	virtual void OnHitCollision(GameObject* hit_object);

private:
	void CheckBoxCollision(GameObject);

};

