#include "KamataEngine.h"
#include <Windows.h>
#include <d3dcompiler.h>

using namespace KamataEngine;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	
	//エンジンの初期化
	KamataEngine::Initialize(L"LE3C_07_オノ_ケンジピエール");

	//DirectXCommonのインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	//メインループ
	while (true) {
		if (KamataEngine::Update()) {
			break;
		}

	//描画開始
	dxCommon->PreDraw();

	//描画終了
	dxCommon->PostDraw();

	}

	//エンジンの終了処理
	KamataEngine::Finalize();

	return 0;
}
