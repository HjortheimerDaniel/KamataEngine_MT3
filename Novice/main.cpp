#include <Novice.h>
#include "OwnMatrix4x4.h"

const char kWindowTitle[] = "GC2A_05_ジュットハイマー_ダニエル_MT3";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	OwnMatrix4x4* ownMatrix4x4 = new OwnMatrix4x4();
	
	Matrix4x4 m1 = {
		3.2f, 0.7f, 9.6f, 4.4f,
		5.5f, 1.3f, 7.8f, 2.1f,
		6.9f, 8.0f, 2.6f, 1.0f,
		0.5f, 7.2f, 5.1f, 3.3f
	};

	Matrix4x4 m2 = {
		4.1f, 6.5f, 3.3f, 2.2f,
		8.8f, 0.6f, 9.9f, 7.7f,
		1.1f, 5.5f, 6.6f, 0.0f,
		3.3f, 9.9f, 8.8f, 2.2f
	};

	Matrix4x4 resultAdd = ownMatrix4x4->Add(m1, m2);
	Matrix4x4 resultSubtract = ownMatrix4x4->Subtract(m1, m2);
	Matrix4x4 resultMultiply = ownMatrix4x4->Multiply(m1, m2);
	Matrix4x4 inverseM1 = ownMatrix4x4->Inverse(m1);
	Matrix4x4 inverseM2 = ownMatrix4x4->Inverse(m2);
	Matrix4x4 transposeM1 = ownMatrix4x4->Transpose(m1);
	Matrix4x4 transposeM2 = ownMatrix4x4->Transpose(m2);
	Matrix4x4 identify = ownMatrix4x4->MakeIdentify4x4();
	
	
	

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		ownMatrix4x4->MatrixScreenPrintf(0, 0, resultAdd, "Add");
		ownMatrix4x4->MatrixScreenPrintf(0, kColumnHeight * 5, resultSubtract, "Subtract");
		ownMatrix4x4->MatrixScreenPrintf(0, kColumnHeight * 5 * 2, resultMultiply, "Multiply");
		ownMatrix4x4->MatrixScreenPrintf(0, kColumnHeight * 5 * 3, inverseM1, "InverseM1");
		ownMatrix4x4->MatrixScreenPrintf(0, kColumnHeight * 5 * 4, inverseM2, "InverseM2");
		ownMatrix4x4->MatrixScreenPrintf(kColumnWidth * 5, 0, transposeM1, "TransposeM1");
		ownMatrix4x4->MatrixScreenPrintf(kColumnWidth * 5, kColumnHeight * 5, transposeM2, "TransposeM2");
		ownMatrix4x4->MatrixScreenPrintf(kColumnWidth * 5, kColumnHeight * 5 * 2, identify, "Identify");
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
