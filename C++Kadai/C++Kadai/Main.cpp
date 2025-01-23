#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Utility/ResourceManager.h"
#include "Scene/SceneManager.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	SetUseCharCodeFormat(DX_CHARCODEFORMAT_UTF8);

	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)
	{
		return -1;

	}

	SetDrawScreen(DX_SCREEN_BACK);

	SceneManager* manager = nullptr;

	try {
		manager = new SceneManager();

		manager->Initialize();

		InputControl* input = InputControl::GetInstance();

		while (ProcessMessage() != -1)
		{
			//入力情報の更新
			input->Update();

			ClearDrawScreen();

			manager->Update();


			//DrawCircle(320, 240, 15, GetColor(255, 255, 255), TRUE);

			ScreenFlip();

			if (input->GetKeyUp(KEY_INPUT_ESCAPE))
			{
				break;
			}
		}
	}
	catch (std::string& error_text)
	{
		OutputDebugString(error_text.c_str());

		return -1;
	}

	InputControl::DeleteInstance();

	if (manager != nullptr)
	{
		manager->Finalize();
		delete manager;
	}

	DxLib_End();
	return 0;

}