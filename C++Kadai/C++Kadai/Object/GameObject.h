#pragma once
#include "../Utility/Vector2D.h"
enum eObjectType
{
	PLAYER,
	ENEMY,
	ITEM,
	GIMMICK,
	BLOCK
};

class GameObject
{
protected:
	Vector2D location;	//オブジェクトの位置
	Vector2D box_size;	//オブジェクトのサイズ
	int image;			//描画する画像データ
	int flip_flag;		//描画する反転フラグ

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
	//座標を設定
	void SetLocation(Vector2D _location);
	//座標を取得
	Vector2D GetLocation()const;
	//ボックスサイズを取得
	Vector2D GetBoxSize()const;

	eObjectType GetObjectType();

	virtual void OnHitCollision(GameObject* hit_object);

//private:
	//当たり判定
	bool CheckBoxCollision(GameObject* obj);

};

