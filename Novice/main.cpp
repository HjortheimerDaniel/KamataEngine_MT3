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

	Vector3 rotate{};
	Vector3 translate{};
	Vector3 cameraPosition = { 0,0,-10.0f };
	Vector3 kLocalVertices[3]{ { 0, 1, 0 }, {1,-1,0}, {-1,-1,0} };

	Vector3 v1{ 1.2f, -3.9f, 2.5f };
	Vector3 v2{ 2.8f, 0.4f, -1.3f };
	Vector3 cross = ownMatrix4x4->Cross(v1, v2);
	
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
		Matrix4x4 worldMatrix = ownMatrix4x4->MakeAffineMatrix({ 1.0f, 1.0f,1.0f }, rotate, translate);
		Matrix4x4 cameraMatrix = ownMatrix4x4->MakeAffineMatrix({ 1.0f,1.0f,1.0f }, { 0.0f,0.0f,0.0f }, cameraPosition);
		Matrix4x4 viewMatrix = ownMatrix4x4->Inverse(cameraMatrix);
		Matrix4x4 projectionMatrix = ownMatrix4x4->MakePerspectiveFovMatrix(0.45f, float(kWindowWidth) / float(kWindowHeight), 0.1f, 100.f);
		Matrix4x4 viewMatrixProjectionMatrix = ownMatrix4x4->Multiply(viewMatrix, projectionMatrix);
		Matrix4x4 worldViewProjectionMatrix = ownMatrix4x4->Multiply(worldMatrix, viewMatrixProjectionMatrix);
		Matrix4x4 viewportMatrix = ownMatrix4x4->MakeViewportMatrix(0, 0, float(kWindowWidth), float(kWindowHeight), 0.0f, 1.0f);
		Vector3 screenVertices[3];
		for (uint32_t i = 0; i < 3; i++)
		{
			Vector3 ndcVertex = ownMatrix4x4->Transform(kLocalVertices[i], worldViewProjectionMatrix);
			screenVertices[i] = ownMatrix4x4->Transform(ndcVertex, viewportMatrix);
		}
		rotate.y+= 0.05f;

		if (keys[DIK_W]) {;
			translate.z += 0.05f;
		}

		if (keys[DIK_S]) {
			;
			translate.z -= 0.05f;
		}

		if (keys[DIK_D]) {
			translate.x += 0.05f;
		}

		if (keys[DIK_A]) {
			translate.x -= 0.05f;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		Novice::DrawTriangle((int)screenVertices[0].x, (int)screenVertices[0].y, (int)screenVertices[1].x, (int)screenVertices[1].y, (int)screenVertices[2].x, (int)screenVertices[2].y, RED, kFillModeSolid);
		ownMatrix4x4->VectorScreenPrintf(0, 0, cross, "Cross");

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
