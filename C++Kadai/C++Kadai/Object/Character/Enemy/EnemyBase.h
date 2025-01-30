#pragma once
#include "../CharacterBase.h"
#include <vector>

enum class eEnemyState
{
    eIDLE,
    eMOVE,
    eATTACK,
    eDEAD
};

class EnemyBase :
    public CharacterBase
{
protected:
    eEnemyState enemy_state;
    std::vector<int> animation_data;

public:
    EnemyBase();
    ~EnemyBase();

    //初期化処理
    virtual void Initialize(Vector2D _location, Vector2D _box_size) override;
    //更新処理
    virtual void Update()override;
    //描画処理
    virtual void Draw(Vector2D _camera_location) const override;
    //終了時処理
    virtual void Finalize()override;

public:
    virtual void Movement();
    virtual void AnimationControl();
    virtual void OnHitCollision(GameObject* hit_object) override;

};

