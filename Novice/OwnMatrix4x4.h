#pragma once
#include "Functions.h"
#include <Novice.h>


class OwnMatrix4x4
{
	public:


	Matrix4x4 Add(Matrix4x4& m1, Matrix4x4& m2);

	Matrix4x4 Subtract(Matrix4x4& m1, Matrix4x4& m2);

	Matrix4x4 Multiply(Matrix4x4& m1, Matrix4x4& m2);

	Matrix4x4 Inverse(Matrix4x4& m1);

	Matrix4x4 Transpose(Matrix4x4& m1);
	Matrix4x4 MakeIdentify4x4();



	void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label);

};


