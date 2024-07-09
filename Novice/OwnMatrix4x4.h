#pragma once
#include "Functions.h"
#include <Novice.h>
#include <assert.h>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
#include <imgui.h>
#include "Vector2.h"

class OwnMatrix4x4 {
public:
	Vector3 Add(const Vector3& v1, const Vector3& v2);
	Vector3 Subtract(const Vector3& v1, const Vector3& v2);
	Vector3 Multiply(const float a, const Vector3& vector);
	float Length(Vector3 distance);
	Vector3 Normalize(Vector3 distance);
	float Dot(Vector3 c, Vector3 d);
	Vector3 Cross(const Vector3& u, const Vector3& v);
	Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);
	Matrix4x4 MakeRotateXMatrix(float radian);
	Matrix4x4 MakeRotateYMatrix(float radian);
	Matrix4x4 MakeRotateZMatrix(float radian);
	Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);
	Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip);
	Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip);
	Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth);
	Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix);
	Matrix4x4 Inverse(const Matrix4x4& m);
	Matrix4x4 MakeLookAtMatrix4x4(const Vector3& eye, const Vector3& target, const Vector3& up);
	Vector3 SphericalToCartesian(float radius, float theta, float phi);
	Vector3 Project(const Vector3& v1, const Vector3& v2);
	Vector3 ClosestPoint(const Vector3& point, const Segment& segment);
	Vector3 Perpendicular(const Vector3& vector);
	void DrawPlane(const Plane& plane, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewMatrix, uint32_t color);
	void DrawSphere(const Sphere& sphere, const Matrix4x4& viewProjection, const Matrix4x4 viewportMatrix, uint32_t color);
	void EnsureAABB(AABB& aabb);
	void DrawTriangle(const Triangle& triangle, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix);
	void DrawGrid(const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix);
	void DrawAABB(const AABB& aabb, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewMatrix, uint32_t color);
	Vector3 ClosestPointOnAABB(const Vector3& point, const AABB& aabb);
	Vector3 Lerp(const Vector3& a, const Vector3& b, float t);
	//Vector3 Bezier(const Vector3& p0, const Vector3& p1, const Vector3& p2, float t);
	void RotateInCircle(const Sphere& sphere, Vector3& position, float &angle);
};