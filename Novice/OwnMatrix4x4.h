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

	Vector3 Add(const Vector3& v1, const Vector3& v2);

	Matrix4x4 Subtract(Matrix4x4& m1, Matrix4x4& m2);

	Vector3 Subtract(const Vector3& v1, const Vector3& v2);

	Matrix4x4 Multiply(Matrix4x4& m1, Matrix4x4& m2);

	Vector3 Multiply(Vector3& v1, Vector3& v2);

	Vector3 Multiply(const float& f, const Vector3& v1);

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

	Vector3 Project(const Vector3& v1,const Vector3& v2);

	Vector3 ClosestPoint(const Vector3& point, const Segment& segment);

	bool IsCollision(const Sphere& s1, const Sphere& s2);

	bool IsCollision(const Sphere& sphere, const Plane& plane);

	bool IsCollision(const Segment& segment, const Plane& plane);

	float Length(const Vector3& point1, const Vector3& point2);

	Vector3 Perpendicular(const Vector3& vector);

	void DrawPlane(const Plane& plane, const Matrix4x4& viewProjectionMatrix, const Matrix4x4 viewPortMatrix, uint32_t color, uint32_t color2, uint32_t color3, uint32_t color4);

	Vector3 Normalize(Vector3 v);

	float Dot(Vector3 v1, Vector3 v2);



};
