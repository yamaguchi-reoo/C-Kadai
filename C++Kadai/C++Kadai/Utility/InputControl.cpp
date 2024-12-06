#include "InputControl.h"
#include "DxLib.h"

//静的メンバ変数定義
InputControl* InputControl::instance = nullptr; //クラスのインスタンスのポインタ

//入力制御クラスのインスタンス取得する処理
InputControl* InputControl::GetInstance()
{
	//インスタンスが無ければ、生成する
	if (instance == nullptr)
	{
		instance = new InputControl();
	}

	//自分自身でポインタを返却する
	return instance;
}

//入力制御クラスのインスタンス削除する処理
void InputControl::DeleteInstance()
{
	//インスタンスが存在していれば、削除する
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

void InputControl::Update()
{
	//前回のキーの更新
	memcpy(old_key, now_key, (sizeof(char) * D_KEYCODE_MAX));

	//現在のキー状態の更新
	GetHitKeyStateAll(now_key);
}

bool InputControl::GetKey(int key_code)const
{
	//キーが押されているかを確認する処理
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == TRUE) && (old_key[key_code] == TRUE));
}

bool InputControl::GetKeyDown(int key_code)const
{
	//キーが押された瞬間か確認する処理
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == TRUE) && (old_key[key_code] == FALSE));
}

bool InputControl::GetKeyUp(int key_code)const
{
	//キーが離された瞬間か確認する処理
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == FALSE) && (old_key[key_code] == TRUE));
}

bool InputControl::CheckKeyCodeRange(int key_code)
{
	//キーコードの範囲内か確認する処理
	return (0 <= key_code && key_code < D_KEYCODE_MAX);
}
