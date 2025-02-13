#pragma once
#include "../GameObject.h"
#include "../../Utility/Vector2D.h"

class CharacterBase :
    public GameObject
{
protected:
    int hp = 0;
	Vector2D velocity = { 0.0f };
	float g_velocity = 0.0f;       //重力加速度

	bool jump_flag = false;        //ジャンプフラグ
	bool damage_flg = false;	//ダメージを受けたかどうか

	int animation_count = 0;    //アニメーションカウント
	int count = 0;

public:
	//初期化処理
	virtual void Initialize(Vector2D _location, Vector2D _box_size) override;
	//更新処理
	virtual void Update()override;
	//描画処理
	virtual void Draw(Vector2D offset, double rate) const override;
	//終了時処理
	virtual void Finalize()override;

public:
	virtual void ApplyDamage(int _damage);

	virtual void OnDamaged(int _damege);

	virtual void OnHitCollision(GameObject* hit_object)override;
};

