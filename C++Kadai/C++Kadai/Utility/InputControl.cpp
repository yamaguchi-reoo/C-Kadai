#include "InputControl.h"

InputControl* InputControl::GetInstance()
{
    return nullptr;
}

void InputControl::DeleteInstance()
{
}

void InputControl::Update()
{
}

bool InputControl::GetKey(int key_code) const
{
    return false;
}

bool InputControl::GetKeyDown(int key_code) const
{
    return false;
}

bool InputControl::GetKeyUp(int key_code) const
{
    return false;
}

bool InputControl::CheckKeyCodeRange(int key_code)
{
    return false;
}
