#pragma once
#include "../CharacterBase.h"
#include <vector>

enum class PlayerState
{
    eIDLE,
    eLEFT,
    eRIGHT,
    eJUMP,
    eDAMAGE,
    eDEAD
};

class Player :
    public CharacterBase
{
private:
    PlayerState player_state;       //プレイヤーの状態
    std::vector<int> animation_data;//アニメーションデータ

    int animation_count;    //アニメーションカウント
    //float g_velocity;       //重力加速度
    bool jump_flag;         //ジャンプフラグ

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
    //プレイヤーの動き
    void Movement();
    //アニメーション管理
    void AnimationControl();
    //当たった時の挙動
    void OnHitCollision(GameObject* hit_object)override;

    //無敵状態
    void InvincibleState();
    //プレイヤー状態の取得
    PlayerState GetPlayerState();
    //HPの取得
    int GetPlayerHp();
};

