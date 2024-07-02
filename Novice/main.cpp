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
	
	//Sphere sphere
	//{
	//	0,0,0, //center
	//	1, // radius
	//	(int)WHITE, 
	//};

	/*Sphere sphere2
	{
		1.6f, 0,0,
		0.3f,
		(int)WHITE
	};*/

	/*Plane plane
	{
		0.0f,1.0f,0.0f,
		1.0f
	};*/

	/*Vector3 controlPoints[3]
	{
		{-0.8f, 0.58f, 1.0f},
		{1.76f, 1.0f, -0.3f},
		{0.94f, -0.7f, 2.3f}
	};*/

	/*Vector3 controlPoints[4]
	{
		{-0.8f, 0.58f, 1.0f},
		{1.76f, 1.0f, -0.3f},
		{0.94f, -0.7f, 2.3f},
		{-0.53f, -0.26f, -0.15f}
	};*/

	Vector3 cameraRotate{ 0.26f, 0.0f, 0.0f };
	Vector3 cameraTranslate{ 0.0f,1.9f, -6.49f };
	Vector3 cameraPosition = { 0,0,-10.0f };

	//Segment segment
	//{
	//	{-0.7f, 0.3f, 0.0f}, //origin
	//	{2.0f, -0.5f, 0.0f}, //diff
	//	(int)WHITE
	//
	//};
	//
	//Triangle triangle
	//{
	//	{0.0f,1.0f,0.0f,
	//	1.0f,-1.0f,0.0f,
	//	-1.0f,-1.0f,0.0f},
	//	(int)WHITE
	//};

	//Vector3 point{ -1.5f, 0.6f, 0.6f };
	
	/*AABB aabb1{
		.min{-0.5f, -0.5f, -0.5f},
		.max{0.5f, 0.5f, 0.5f}
	};*/

	//AABB aabb2{
	//	.min{0.2f, 0.2f, 0.2f},
	//	.max{1.0f, 1.0f, 1.0f},
	//	.color{(int)WHITE}
	//};

	Vector3 translates[3] = //0 = shoulder, 1 = elbow, 2 = hand
	{
		{0.2f, 1.0f, 0.0f},
		{0.4f, 0.0f, 0.0f},
		{0.3f, 0.0f, 0.0f}
	};

	Vector3 rotates[3] =
	{
		{0.0f, 0.0f, -6.8f},
		{0.0f, 0.0f, -1.4f},
		{0.0f, 0.0f, 0.0f}
	};

	Vector3 scales[3] =
	{
		{1.0f, 1.0f, 1.0f},
		{1.0f, 0.0f, 1.0f},
		{1.0f, 1.0f, 1.0f}
	};
	
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
		Matrix4x4 worldMatrix = ownMatrix4x4->MakeAffineMatrix({ 1.0f, 1.0f,1.0f }, {0,0,0}, {0,0,0});
		Matrix4x4 cameraMatrix = ownMatrix4x4->MakeAffineMatrix({ 1.0f,1.0f,1.0f }, cameraRotate, cameraTranslate);
		Matrix4x4 shoulderMatrix = ownMatrix4x4->MakeAffineMatrix(scales[0], rotates[0], translates[0]);
		Matrix4x4 elbowMatrix = ownMatrix4x4->Multiply(shoulderMatrix, ownMatrix4x4->MakeAffineMatrix(scales[1], rotates[1], translates[1]));
		Matrix4x4 handMatrix = ownMatrix4x4->Multiply(elbowMatrix, ownMatrix4x4->MakeAffineMatrix(scales[2], rotates[2], translates[2]));
		Matrix4x4 viewMatrix = ownMatrix4x4->Inverse(cameraMatrix);
		Matrix4x4 projectionMatrix = ownMatrix4x4->MakePerspectiveFovMatrix(0.45f, float(kWindowWidth) / float(kWindowHeight), 0.1f, 100.f);
		Matrix4x4 viewMatrixProjectionMatrix = ownMatrix4x4->Multiply(viewMatrix, projectionMatrix);
		Matrix4x4 worldViewProjectionMatrix = ownMatrix4x4->Multiply(worldMatrix, viewMatrixProjectionMatrix);
		Matrix4x4 viewportMatrix = ownMatrix4x4->MakeViewportMatrix(0, 0, float(kWindowWidth), float(kWindowHeight), 0.0f, 1.0f);
		//Vector3 start = ownMatrix4x4->Transform(ownMatrix4x4->Transform(segment.origin, viewMatrixProjectionMatrix), viewportMatrix);
		//Vector3 end =ownMatrix4x4->Transform(ownMatrix4x4->Transform(ownMatrix4x4->Add(segment.origin, segment.diff), viewMatrixProjectionMatrix), viewportMatrix);


		//Vector3 project = ownMatrix4x4->Project(ownMatrix4x4->Subtract(point, segment.origin), segment.diff);
		//Vector3 closestPoint = ownMatrix4x4->ClosestPoint(point, segment);
		//Sphere pointSphere{ point, 0.01f };
		//Sphere closestPointSphere{ closestPoint, 0.01f };
		
		Vector3 shoulderPos = ownMatrix4x4->Transform({ 0, 0, 0 }, shoulderMatrix);
		Vector3 elbowPos = ownMatrix4x4->Transform({ 0, 0, 0 },elbowMatrix);
		Vector3 handPos = ownMatrix4x4->Transform({ 0, 0, 0 }, handMatrix);


		/*if(ownMatrix4x4->IsCollision(aabb1, segment))
		{
			aabb1.color = RED;
		}
		else 
		{
			aabb1.color = WHITE;
		}*/

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		//ownMatrix4x4->DrawGrid(viewMatrixProjectionMatrix, viewportMatrix);

		//ownMatrix4x4->DrawSphere(sphere, viewMatrixProjectionMatrix, viewportMatrix, sphere.color);
		//ownMatrix4x4->DrawSphere(closestPointSphere, viewMatrixProjectionMatrix, viewportMatrix, WHITE);
		//ownMatrix4x4->DrawSphere(sphere, viewMatrixProjectionMatrix, viewportMatrix, sphere.color);
		//ownMatrix4x4->DrawSphere(sphere2, viewMatrixProjectionMatrix, viewportMatrix, sphere2.color);
		/*if(ownMatrix4x4->IsCollision(sphere, plane))
		{
			sphere.color = RED;
		}
		else {
			sphere.color = WHITE;

		}*/
		//ownMatrix4x4->DrawTriangle(triangle, viewMatrixProjectionMatrix, viewportMatrix, triangle.color);
		//Novice::DrawLine((int)start.x, (int)start.y, (int)end.x, (int)end.y, segment.color);

		//ownMatrix4x4->DrawAABB(aabb1, viewMatrixProjectionMatrix, viewportMatrix, aabb1.color);

		//ownMatrix4x4->DrawBezier(controlPoints[0], controlPoints[1], controlPoints[2], viewMatrixProjectionMatrix, viewportMatrix, BLUE);
		//ownMatrix4x4->DrawCatmullRom(controlPoints[0], controlPoints[1], controlPoints[2], controlPoints[3], viewMatrixProjectionMatrix, viewportMatrix, BLUE);
		ownMatrix4x4->DrawSphere({ shoulderPos, 0.1f }, viewMatrixProjectionMatrix, viewportMatrix, RED);
		ownMatrix4x4->DrawSphere({ elbowPos, 0.1f }, viewMatrixProjectionMatrix, viewportMatrix, BLUE);
		ownMatrix4x4->DrawSphere({ handPos, 0.1f }, viewMatrixProjectionMatrix, viewportMatrix, GREEN);

		Novice::DrawLine((int)shoulderPos.x, (int)shoulderPos.y, (int)elbowPos.x, (int)elbowPos.y, WHITE);
		Novice::DrawLine((int)elbowPos.x, (int)elbowPos.y, (int)handPos.x, (int)handPos.y, WHITE);
		//Novice::DrawLine(1, 1, 300, 300, WHITE);


		
		ImGui::Begin("Window");
		ImGui::DragFloat3("CameraTranslate", &cameraTranslate.x, 0.01f);
		ImGui::DragFloat3("CameraRotate", &cameraRotate.x, 0.01f);
		ImGui::DragFloat3("Shoulder Translate", &translates[0].x, 0.01f);
		ImGui::DragFloat3("Shoulder Rotate", &rotates[0].x, 0.01f);
		ImGui::DragFloat3("Shoulder Scale", &scales[0].x, 0.01f);
		ImGui::DragFloat3("Elbow Translate", &translates[1].x, 0.01f);
		ImGui::DragFloat3("Elbow Rotate", &rotates[1].x, 0.01f);
		ImGui::DragFloat3("Elbow Scale", &scales[1].x, 0.01f);
		ImGui::DragFloat3("Hand Translate", &translates[2].x, 0.01f);
		ImGui::DragFloat3("Hand Rotate", &rotates[2].x, 0.01f);
		ImGui::DragFloat3("Hand Scale", &scales[2].x, 0.01f);
		ImGui::DragFloat3("shoulder pos", &shoulderPos.x, 0.01f);
		ImGui::DragFloat3("elbow pos", &elbowPos.x, 0.01f);
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
