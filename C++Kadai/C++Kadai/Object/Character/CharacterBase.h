#pragma once
#include "../GameObject.h"
class CharacterBase :
    public GameObject
{
protected:
    int hp;
    Vector2D velocity;

public:
	CharacterBase();
	~CharacterBase();

	//初期化処理
	virtual void Initialize(Vector2D _location, Vector2D _box_size) override;
	//更新処理
	virtual void Update()override;
	//描画処理
	virtual void Draw(Vector2D _camera_location) const override;
	//終了時処理
	virtual void Finalize()override;

public:
	virtual void ApplyDamage(int _damage);

	virtual void OnDamaged(int _damege);

	virtual void OnHitCollision(GameObject* hit_object)override;
};

