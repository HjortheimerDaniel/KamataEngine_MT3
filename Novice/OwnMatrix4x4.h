#pragma once
#include "Functions.h"
#include <Novice.h>
#include <assert.h>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
#include <imgui.h>

class OwnMatrix4x4 {
public:
	void DrawGrid(const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix);

	void DrawSphere(const Sphere& sphere, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);

	Matrix4x4 Add(Matrix4x4& m1, Matrix4x4& m2);

	Matrix4x4 Subtract(Matrix4x4& m1, Matrix4x4& m2);

	Matrix4x4 Multiply(Matrix4x4& m1, Matrix4x4& m2);

	Matrix4x4 Inverse(Matrix4x4& m1);

	Matrix4x4 Transpose(Matrix4x4& m1);

	Matrix4x4 MakeIdentify4x4();

	Matrix4x4 MakeScaleMatrix(Vector3& scale);

	Matrix4x4 MakeTranslateMatrix(Vector3& transform);

	Vector3 Transform(const Vector3& vector, const Matrix4x4& Matrix);

	void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label);

	void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label);

	Matrix4x4 MakeRotateXMatrix(float radian);

	Matrix4x4 MakeRotateYMatrix(float radian);

	Matrix4x4 MakeRotateZMatrix(float radian);

	Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rot, const Vector3& translate);

	Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip);

	Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip);

	Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth);

	Vector3 Cross(const Vector3& v1, const Vector3& v2);
};
