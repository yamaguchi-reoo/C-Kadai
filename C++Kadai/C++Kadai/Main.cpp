#include "DxLib.h"
#include "Utility/FpsController.h"
#include "Utility/DebugInfomation.h"
#include "Utility/InputControl.h"
#include "Utility/ResourceManager.h"
#include "Scene/SceneManager.h"

#define FRAMERATE 60.0 //フレームレート

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

	//fps制御
	FpsController* FPSC = new FpsController(FRAMERATE, 800);

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


			FPSC->All();
#ifdef _DEBUG
			FPSC->Disp();
#endif

			//デバッグ表示の更新
			DebugInfomation::Draw();


			if (input->GetKeyUp(KEY_INPUT_ESCAPE))
			{
				break;
			}
			ScreenFlip();
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