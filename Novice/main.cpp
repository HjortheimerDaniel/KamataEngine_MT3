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
	
	Sphere sphere
	{
		0,0,0, //center
		0.1f, // radius
		(int)WHITE, 
	};
	
	Vector3 position = { -0.90f,0.3f,0.0f, };
	float angle = 0;

	
	Vector3 cameraRotate{ 0.0f,0.0f,0.0f };

	Vector3 cameraTranslate{ 0.0f,0.0f,0.0f };


	float radius = 10.0f;
	float theta = -3.46f;
	float phi = 1.5f;
	bool start = false;
	
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
		
		Vector3 cameraPosition = ownMatrix4x4->SphericalToCartesian(radius, theta, phi);
		Vector3 cameraTarget = { 0.0f, 0.0f, 0.0f };
		Vector3 cameraUp = { 0.0f, 1.0f, 0.0f };


		Matrix4x4 viewMatrix = ownMatrix4x4->MakeLookAtMatrix4x4(cameraPosition, cameraTarget, cameraUp);
		Matrix4x4 worldMatrix = ownMatrix4x4->MakeAffineMatrix({ 1.0f,1.0f,1.0f }, cameraRotate, cameraTranslate);
		Matrix4x4 projectionMatrix = ownMatrix4x4->MakePerspectiveFovMatrix(0.45f, float(kWindowWidth) / float(kWindowHeight), 0.1f, 100.0f);
		Matrix4x4 worldViewProjectionMatrix = ownMatrix4x4->Multiply(worldMatrix, ownMatrix4x4->Multiply(viewMatrix, projectionMatrix));
		Matrix4x4 viewProjectionMatrix = ownMatrix4x4->Multiply(viewMatrix, projectionMatrix);
		Matrix4x4 viewportMatrix = ownMatrix4x4->MakeViewportMatrix(0, 0, float(kWindowWidth), float(kWindowHeight), 0.0f, 1.0f);
		ownMatrix4x4->Transform(ownMatrix4x4->Transform(position, viewProjectionMatrix), viewMatrix);
		if (start)
		{
			ownMatrix4x4->RotateInCircle(sphere, position, angle);
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
	
		ownMatrix4x4->DrawSphere({position,sphere.radius}, viewProjectionMatrix, viewportMatrix, sphere.color);
	
		ownMatrix4x4->DrawGrid(viewProjectionMatrix, viewportMatrix);
		
		ImGui::Begin("Window");
		//ImGui::DragFloat("theta", &theta, 0.01f);
		//ImGui::DragFloat("phi", &phi, 0.01f);
		//ImGui::DragFloat3("CameraTranslate", &cameraTranslate.x, 0.01f);
		//ImGui::DragFloat3("CameraRotate", &cameraRotate.x, 0.01f);
		if (ImGui::Button("Start"))
		{
			start = true;
		}
		//ImGui::DragFloat3("sphere", &sphere.center.x, 0.01f);
		//ImGui::DragFloat3("pos", &position.x, 0.01f);
		
		ImGui::End();
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
