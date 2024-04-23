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
	
	Vector3 rotate{ 0.4f,1.43f,-0.8f };
	Matrix4x4 rotateXMatrix = ownMatrix4x4->MakeRotateXMatrix(rotate.x);
	Matrix4x4 rotateYMatrix = ownMatrix4x4->MakeRotateYMatrix(rotate.y);
	Matrix4x4 rotateZMatrix = ownMatrix4x4->MakeRotateZMatrix(rotate.z);
	Matrix4x4 RotateYZ = ownMatrix4x4->Multiply(rotateYMatrix, rotateZMatrix);
	Matrix4x4 rotateXYZMatrix = ownMatrix4x4->Multiply(rotateXMatrix, RotateYZ);
	

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
	 
		ownMatrix4x4->MatrixScreenPrintf(0, 0, rotateXMatrix, "rotateXMatrix");
		ownMatrix4x4->MatrixScreenPrintf(0, kColumnHeight * 5, rotateYMatrix, "rotateYMatrix");
		ownMatrix4x4->MatrixScreenPrintf(0, kColumnHeight * 5 * 2, rotateZMatrix, "rotateZMatrix");
		ownMatrix4x4->MatrixScreenPrintf(0, kColumnHeight * 5 * 3, rotateXYZMatrix, "rotateXYZMatrix");
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
