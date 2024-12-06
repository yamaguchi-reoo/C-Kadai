#pragma once
#include "../CharacterBase.h"
#include <vector>

enum eEnemyState
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

    virtual void Movement();
    virtual void AnimationControl();
    virtual void OnHitCollision(GameObject* hit_object) override;

};

