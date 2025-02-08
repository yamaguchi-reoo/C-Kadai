#pragma once
#include "../GameObject.h"
class ItemBase :
    public GameObject
{
protected:
    int score;
public:
    //コンストラクタ
    ItemBase();
    //デストラクタ
    ~ItemBase();

    //初期化処理
    virtual void Initialize(Vector2D _location, Vector2D _box_size) override;
    //更新処理
    virtual void Update()override;
    //描画処理
    virtual void Draw(Vector2D offset) const override;
    //終了時処理
    virtual void Finalize()override;
};

