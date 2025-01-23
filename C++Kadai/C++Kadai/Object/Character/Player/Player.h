#pragma once
#include "../CharacterBase.h"
#include <vector>

enum class PlayerState
{
    eIDLE,
    eMOVE,
    eJump,
    eDamege,
    eDEAD
};

class Player :
    public CharacterBase
{
private:
    PlayerState player_state;
    std::vector<int> animation_data;

public:
    Player();
    ~Player();

    //初期化処理
    void Initialize(Vector2D _location, Vector2D _box_size) override;
    //更新処理
    void Update()override;
    //描画処理
    void Draw(Vector2D _camera_location) const override;
    //終了時処理
    void Finalize()override;

public:

    void Movement();
    void AnimationControl();
    void OnHitCollision(GameObject* hit_object)override;


    void InvincibleState();
    PlayerState GetPlayerState();
    int GetPlayerHp();
};

