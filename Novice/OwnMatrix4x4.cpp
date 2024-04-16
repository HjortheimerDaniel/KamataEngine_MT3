#include "OwnMatrix4x4.h"

Matrix4x4 OwnMatrix4x4::Add(Matrix4x4& m1, Matrix4x4& m2)
{
	Matrix4x4 result{
		m1.m[0][0] + m2.m[0][0], m1.m[0][1] + m2.m[0][1], m1.m[0][2] + m2.m[0][2],m1.m[0][3] + m2.m[0][3],
		m1.m[1][0] + m2.m[1][0], m1.m[1][1] + m2.m[1][1], m1.m[1][2] + m2.m[1][2],m1.m[1][3] + m2.m[1][3],
		m1.m[2][0] + m2.m[2][0], m1.m[2][1] + m2.m[2][1], m1.m[2][2] + m2.m[2][2],m1.m[2][3] + m2.m[2][3],
		m1.m[3][0] + m2.m[3][0], m1.m[3][1] + m2.m[3][1], m1.m[3][2] + m2.m[3][2],m1.m[3][3] + m2.m[3][3],
	};

	//result.m[0][0] = m1.m[0][0] + m2.m[0][0];
	//result.m[0][1] = m1.m[0][1] + m2.m[0][1];
	//result.m[0][2] = m1.m[0][2] + m2.m[0][2];
	//result.m[0][3] = m1.m[0][3] + m2.m[0][3];
	//
	//result.m[1][0] = m1.m[1][0] + m2.m[0][0];
	//result.m[1][1] = m1.m[1][1] + m2.m[0][1];
	//result.m[1][2] = m1.m[1][2] + m2.m[0][2];
	//result.m[1][3] = m1.m[1][3] + m2.m[0][3];
	//
	//result.m[2][0] = m1.m[2][0] + m2.m[0][0];
	//result.m[2][1] = m1.m[2][1] + m2.m[0][1];
	//result.m[2][2] = m1.m[2][2] + m2.m[0][2];
	//result.m[2][3] = m1.m[2][3] + m2.m[0][3];
	//
	//result.m[3][0] = m1.m[3][0] + m2.m[0][0];
	//result.m[3][1] = m1.m[3][1] + m2.m[0][1];
	//result.m[3][2] = m1.m[3][2] + m2.m[0][2];
	//result.m[3][3] = m1.m[3][3] + m2.m[0][3];

	return result;
}

Matrix4x4 OwnMatrix4x4::Subtract(Matrix4x4& m1, Matrix4x4& m2)
{
	Matrix4x4 result{
		m1.m[0][0] - m2.m[0][0], m1.m[0][1] - m2.m[0][1], m1.m[0][2] - m2.m[0][2],m1.m[0][3] - m2.m[0][3],
		m1.m[1][0] - m2.m[1][0], m1.m[1][1] - m2.m[1][1], m1.m[1][2] - m2.m[1][2],m1.m[1][3] - m2.m[1][3],
		m1.m[2][0] - m2.m[2][0], m1.m[2][1] - m2.m[2][1], m1.m[2][2] - m2.m[2][2],m1.m[2][3] - m2.m[2][3],
		m1.m[3][0] - m2.m[3][0], m1.m[3][1] - m2.m[3][1], m1.m[3][2] - m2.m[3][2],m1.m[3][3] - m2.m[3][3],
	};
	return result;
}

void OwnMatrix4x4::MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix)
{
	for (int row = 0; row < 4; row++)
	{
		for (int column = 0; column < 4; column++)
		{
			Novice::ScreenPrintf(x + column * kColumnWidth, y + row * kColumnHeight, "%6.02f", matrix.m[row][column]);
		}

	}
}




