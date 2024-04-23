#pragma once
#include "Functions.h"
#include <Novice.h>
#include <assert.h>
#include <cmath>


class OwnMatrix4x4
{
	public:


	Matrix4x4 Add(Matrix4x4& m1, Matrix4x4& m2);

	Matrix4x4 Subtract(Matrix4x4& m1, Matrix4x4& m2);

	Matrix4x4 Multiply(Matrix4x4& m1, Matrix4x4& m2);

	Matrix4x4 Inverse(Matrix4x4& m1);

	Matrix4x4 Transpose(Matrix4x4& m1);

	Matrix4x4 MakeIdentify4x4();

	Matrix4x4 MakeScaleMatrix(Vector3 &scale);

	Matrix4x4 MakeTranslateMatrix(Vector3& transform);

	Vector3 Transform(Vector3& vector, Matrix4x4& Matrix);


	void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label);

	void VectorScreenPrintf(int x, int y,const  Vector3& vector, const char* label);

	Matrix4x4 MakeRotateXMatrix(float radian);

	Matrix4x4 MakeRotateYMatrix(float radian);

	Matrix4x4 MakeRotateZMatrix(float radian);

	Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rot, const Vector3& translate);

};


