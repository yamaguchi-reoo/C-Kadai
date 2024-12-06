#pragma once

#define D_KEYCODE_MAX (256)		//キーコードの最大数
class InputControl
{
private:
	//自クラスのポインタ（アドレスの先にインスタンスを生成する）
	static InputControl* instance;

	//今回の入力キー
	char now_key[D_KEYCODE_MAX];
	//前回の入力キー
	char old_key[D_KEYCODE_MAX];

private:
	//コンストラクタをprivateにすることで
	//自クラスのメンバ関数でしかインスタンスを生成できないようにする
	InputControl() = default;

	//コピーガード
	//クラス外インスタンスを生成して渡すことができないようにする
	InputControl(InputControl& v) = delete;
	InputControl& operator = (const InputControl& v) = delete;
	//~コピーガード

public:
	~InputControl() = default;

public:
	//インスタンス取得する処理
	static InputControl* GetInstance();
	//インスタンスの削除
	static void DeleteInstance();

public:
	//キー入力の状態を更新
	void Update();

	//押している間
	bool GetKey(int key_code)const;
	//押した瞬間
	bool GetKeyDown(int key_code)const;
	//離した瞬間
	bool GetKeyUp(int key_code)const;

private:
	//キーコードが有効な範囲にあるかを確認
	static bool CheckKeyCodeRange(int key_code);
};

