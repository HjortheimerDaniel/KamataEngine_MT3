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

Matrix4x4 OwnMatrix4x4::Multiply(Matrix4x4& m1, Matrix4x4& m2)
{
	Matrix4x4 result{
		m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0] + m1.m[0][2] * m2.m[2][0] + m1.m[0][3] * m2.m[3][0], /*here*/ m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1] + m1.m[0][2] * m2.m[2][1] + m1.m[0][3] * m2.m[3][1], /*here*/ m1.m[0][0] * m2.m[0][2] + m1.m[0][1] * m2.m[1][2] + m1.m[0][2] * m2.m[2][2] + m1.m[0][3] * m2.m[3][2], /*here*/ m1.m[0][0] * m2.m[0][3] + m1.m[0][1] * m2.m[1][3] + m1.m[0][2] * m2.m[2][3] + m1.m[0][3] * m2.m[3][3],
		m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0] + m1.m[1][2] * m2.m[2][0] + m1.m[1][3] * m2.m[3][0], /*here*/ m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1] + m1.m[1][2] * m2.m[2][1] + m1.m[1][3] * m2.m[3][1], /*here*/ m1.m[1][0] * m2.m[0][2] + m1.m[1][1] * m2.m[1][2] + m1.m[1][2] * m2.m[2][2] + m1.m[1][3] * m2.m[3][2], /*here*/ m1.m[1][0] * m2.m[0][3] + m1.m[1][1] * m2.m[1][3] + m1.m[1][2] * m2.m[2][3] + m1.m[1][3] * m2.m[3][3],
		m1.m[2][0] * m2.m[0][0] + m1.m[2][1] * m2.m[1][0] + m1.m[2][2] * m2.m[2][0] + m1.m[2][3] * m2.m[3][0], /*here*/ m1.m[2][0] * m2.m[0][1] + m1.m[2][1] * m2.m[1][1] + m1.m[2][2] * m2.m[2][1] + m1.m[2][3] * m2.m[3][1], /*here*/ m1.m[2][0] * m2.m[0][2] + m1.m[2][1] * m2.m[1][2] + m1.m[2][2] * m2.m[2][2] + m1.m[2][3] * m2.m[3][2], /*here*/ m1.m[2][0] * m2.m[0][3] + m1.m[2][1] * m2.m[1][3] + m1.m[2][2] * m2.m[2][3] + m1.m[2][3] * m2.m[3][3],
		m1.m[3][0] * m2.m[0][0] + m1.m[3][1] * m2.m[1][0] + m1.m[3][2] * m2.m[2][0] + m1.m[3][3] * m2.m[3][0], /*here*/ m1.m[3][0] * m2.m[0][1] + m1.m[3][1] * m2.m[1][1] + m1.m[3][2] * m2.m[2][1] + m1.m[3][3] * m2.m[3][1], /*here*/ m1.m[3][0] * m2.m[0][2] + m1.m[3][1] * m2.m[1][2] + m1.m[3][2] * m2.m[2][2] + m1.m[3][3] * m2.m[3][2], /*here*/ m1.m[3][0] * m2.m[0][3] + m1.m[3][1] * m2.m[1][3] + m1.m[3][2] * m2.m[2][3] + m1.m[3][3] * m2.m[3][3],

	};
	return result;
}

Matrix4x4 OwnMatrix4x4::Inverse(Matrix4x4& m1)
{
	float A = m1.m[0][0] * m1.m[1][1] * m1.m[2][2] * m1.m[3][3] + m1.m[0][0] * m1.m[1][2] * m1.m[2][3] * m1.m[3][1] + m1.m[0][0] * m1.m[1][3] * m1.m[2][1] * m1.m[3][2] -
			  m1.m[0][0] * m1.m[1][3] * m1.m[2][2] * m1.m[3][1] - m1.m[0][0] * m1.m[1][2] * m1.m[2][1] * m1.m[3][3] - m1.m[0][0] * m1.m[1][1] * m1.m[2][3] * m1.m[3][2] -
			  m1.m[0][1] * m1.m[1][0] * m1.m[2][2] * m1.m[3][3] - m1.m[0][2] * m1.m[1][0] * m1.m[2][3] * m1.m[3][1] - m1.m[0][3] * m1.m[1][0] * m1.m[2][1] * m1.m[3][2] +
			  m1.m[0][3] * m1.m[1][0] * m1.m[2][2] * m1.m[3][1] + m1.m[0][2] * m1.m[1][0] * m1.m[2][1] * m1.m[3][3] + m1.m[0][1] * m1.m[1][0] * m1.m[2][3] * m1.m[3][2] +
			  m1.m[0][1] * m1.m[1][2] * m1.m[2][0] * m1.m[3][3] + m1.m[0][2] * m1.m[1][3] * m1.m[2][0] * m1.m[3][1] + m1.m[0][3] * m1.m[1][1] * m1.m[2][0] * m1.m[3][2] -
			  m1.m[0][3] * m1.m[1][2] * m1.m[2][0] * m1.m[3][1] - m1.m[0][2] * m1.m[1][1] * m1.m[2][0] * m1.m[3][3] - m1.m[0][1] * m1.m[1][3] * m1.m[2][0] * m1.m[3][2] -
			  m1.m[0][1] * m1.m[1][2] * m1.m[2][3] * m1.m[3][0] - m1.m[0][2] * m1.m[1][3] * m1.m[2][1] * m1.m[3][0] - m1.m[0][3] * m1.m[1][1] * m1.m[2][2] * m1.m[3][0] +
			  m1.m[0][3] * m1.m[1][2] * m1.m[2][1] * m1.m[3][0] + m1.m[0][2] * m1.m[1][1] * m1.m[2][3] * m1.m[3][0] + m1.m[0][1] * m1.m[1][3] * m1.m[2][2] * m1.m[3][0];


	Matrix4x4 result;

	result.m[0][0] = 1 / A * (m1.m[1][1] * m1.m[2][2] * m1.m[3][3] + m1.m[1][2] * m1.m[2][3] * m1.m[3][1] + m1.m[1][3] * m1.m[2][1] * m1.m[3][2] - m1.m[1][3] * m1.m[2][2] * m1.m[3][1] - m1.m[1][2] * m1.m[2][1] * m1.m[3][3] - m1.m[1][1] * m1.m[2][3] * m1.m[3][2]);
	result.m[0][1] = 1 / A * (-m1.m[0][1] * m1.m[2][2] * m1.m[3][3] - m1.m[0][2] * m1.m[2][3] * m1.m[3][1] - m1.m[0][3] * m1.m[2][1] * m1.m[3][2] + m1.m[0][3] * m1.m[2][2] * m1.m[3][1] + m1.m[0][2] * m1.m[2][1] * m1.m[3][3] + m1.m[0][1] * m1.m[2][3] * m1.m[3][2]);
	result.m[0][2] = 1 / A * (m1.m[0][1] * m1.m[1][2] * m1.m[3][3] + m1.m[0][2] * m1.m[1][3] * m1.m[3][1] + m1.m[0][3] * m1.m[1][1] * m1.m[3][2] - m1.m[0][3] * m1.m[1][2] * m1.m[3][1] - m1.m[0][2] * m1.m[1][1] * m1.m[3][3] - m1.m[0][1] * m1.m[1][3] * m1.m[3][2]);
	result.m[0][3] = 1 / A * (-m1.m[0][1] * m1.m[1][2] * m1.m[2][3] - m1.m[0][2] * m1.m[1][3] * m1.m[2][1] - m1.m[0][3] * m1.m[1][1] * m1.m[2][2] + m1.m[0][3] * m1.m[1][2] * m1.m[2][1] + m1.m[0][2] * m1.m[1][1] * m1.m[2][3] + m1.m[0][1] * m1.m[1][3] * m1.m[2][2]);

	result.m[1][0] = 1 / A * (-m1.m[1][0] * m1.m[2][2] * m1.m[3][3] - m1.m[1][2] * m1.m[2][3] * m1.m[3][0] - m1.m[1][3] * m1.m[2][0] * m1.m[3][2] + m1.m[1][3] * m1.m[2][2] * m1.m[3][0] + m1.m[1][2] * m1.m[2][0] * m1.m[3][3] + m1.m[1][0] * m1.m[2][3] * m1.m[3][2]);
	result.m[1][1] = 1 / A * (m1.m[0][0] * m1.m[2][2] * m1.m[3][3] + m1.m[0][2] * m1.m[2][3] * m1.m[3][0] + m1.m[0][3] * m1.m[2][0] * m1.m[3][2] - m1.m[0][3] * m1.m[2][2] * m1.m[3][0] - m1.m[0][2] * m1.m[2][0] * m1.m[3][3] - m1.m[0][0] * m1.m[2][3] * m1.m[3][2]);
	result.m[1][2] = 1 / A * (-m1.m[0][0] * m1.m[1][2] * m1.m[3][3] - m1.m[0][2] * m1.m[1][3] * m1.m[3][0] - m1.m[0][3] * m1.m[1][0] * m1.m[3][2] + m1.m[0][3] * m1.m[1][2] * m1.m[3][0] + m1.m[0][2] * m1.m[1][0] * m1.m[3][3] + m1.m[0][0] * m1.m[1][3] * m1.m[3][2]);
	result.m[1][3] = 1 / A * (m1.m[0][0] * m1.m[1][2] * m1.m[2][3] + m1.m[0][2] * m1.m[1][3] * m1.m[2][0] + m1.m[0][3] * m1.m[1][0] * m1.m[2][2] - m1.m[0][3] * m1.m[1][2] * m1.m[2][0] - m1.m[0][2] * m1.m[1][0] * m1.m[2][3] - m1.m[0][0] * m1.m[1][3] * m1.m[2][2]);

	result.m[2][0] = 1 / A * (m1.m[1][0] * m1.m[2][1] * m1.m[3][3] + m1.m[1][1] * m1.m[2][3] * m1.m[3][0] + m1.m[1][3] * m1.m[2][0] * m1.m[3][1] - m1.m[1][3] * m1.m[2][1] * m1.m[3][0] - m1.m[1][1] * m1.m[2][0] * m1.m[3][3] - m1.m[1][0] * m1.m[2][3] * m1.m[3][1]);
	result.m[2][1] = 1 / A * (-m1.m[0][0] * m1.m[2][1] * m1.m[3][3] - m1.m[0][1] * m1.m[2][3] * m1.m[3][0] - m1.m[0][3] * m1.m[2][0] * m1.m[3][1] + m1.m[0][3] * m1.m[2][1] * m1.m[3][0] + m1.m[0][1] * m1.m[2][0] * m1.m[3][3] + m1.m[0][0] * m1.m[2][3] * m1.m[3][1]);
	result.m[2][2] = 1 / A * (m1.m[0][0] * m1.m[1][1] * m1.m[3][3] + m1.m[0][1] * m1.m[1][3] * m1.m[3][0] + m1.m[0][3] * m1.m[1][0] * m1.m[3][1] - m1.m[0][3] * m1.m[1][1] * m1.m[3][0] - m1.m[0][1] * m1.m[1][0] * m1.m[3][3] - m1.m[0][0] * m1.m[1][3] * m1.m[3][1]);
	result.m[2][3] = 1 / A * (-m1.m[0][0] * m1.m[1][1] * m1.m[2][3] - m1.m[0][1] * m1.m[1][3] * m1.m[2][0] - m1.m[0][3] * m1.m[1][0] * m1.m[2][1] + m1.m[0][3] * m1.m[1][1] * m1.m[2][0] + m1.m[0][1] * m1.m[1][0] * m1.m[2][3] + m1.m[0][0] * m1.m[1][3] * m1.m[2][1]);

	result.m[3][0] = 1 / A * (-m1.m[1][0] * m1.m[2][1] * m1.m[3][2] - m1.m[1][1] * m1.m[2][2] * m1.m[3][0] - m1.m[1][2] * m1.m[2][0] * m1.m[3][1] + m1.m[1][2] * m1.m[2][1] * m1.m[3][0] + m1.m[1][1] * m1.m[2][0] * m1.m[3][2] + m1.m[1][0] * m1.m[2][2] * m1.m[3][1]);
	result.m[3][1] = 1 / A * (m1.m[0][0] * m1.m[2][1] * m1.m[3][2] + m1.m[0][1] * m1.m[2][2] * m1.m[3][0] + m1.m[0][2] * m1.m[2][0] * m1.m[3][1] - m1.m[0][2] * m1.m[2][1] * m1.m[3][0] - m1.m[0][1] * m1.m[2][0] * m1.m[3][2] - m1.m[0][0] * m1.m[2][2] * m1.m[3][1]);
	result.m[3][2] = 1 / A * (-m1.m[0][0] * m1.m[1][1] * m1.m[3][2] - m1.m[0][1] * m1.m[1][2] * m1.m[3][0] - m1.m[0][2] * m1.m[1][0] * m1.m[3][1] + m1.m[0][2] * m1.m[1][1] * m1.m[3][0] + m1.m[0][1] * m1.m[1][0] * m1.m[3][2] + m1.m[0][0] * m1.m[1][2] * m1.m[3][1]);
	result.m[3][3] = 1 / A * (m1.m[0][0] * m1.m[1][1] * m1.m[2][2] + m1.m[0][1] * m1.m[1][2] * m1.m[2][0] + m1.m[0][2] * m1.m[1][0] * m1.m[2][1] - m1.m[0][2] * m1.m[1][1] * m1.m[2][0] - m1.m[0][1] * m1.m[1][0] * m1.m[2][2] - m1.m[0][0] * m1.m[1][2] * m1.m[2][1]);

	return result;
}

Matrix4x4 OwnMatrix4x4::Transpose(Matrix4x4& m1)
{
	Matrix4x4 result{
		m1.m[0][0], m1.m[1][0],m1.m[2][0],m1.m[3][0],
		m1.m[0][1], m1.m[1][1],m1.m[2][1],m1.m[3][1],
		m1.m[0][2], m1.m[1][2],m1.m[2][2],m1.m[3][2],
		m1.m[0][3],m1.m[1][3],m1.m[2][3],m1.m[3][3]
	};
	return result;
}

Matrix4x4 OwnMatrix4x4::MakeIdentify4x4()
{
	Matrix4x4 result{
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		0,0,0,1
	};
	return result;
}

Matrix4x4 OwnMatrix4x4::MakeScaleMatrix(Vector3& scale)
{
	Matrix4x4 result{
	scale.x, 0, 0, 0,
	0, scale.y, 0, 0,
	0, 0, scale.z, 0,
	0, 0, 0, 1
	};
	return result;
}

Matrix4x4 OwnMatrix4x4::MakeTranslateMatrix(Vector3& translate)
{
	Matrix4x4 result {
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		translate.x, translate.y, translate.z, 1
	};
	return result;
}

Vector3 OwnMatrix4x4::Transform(Vector3& vector, Matrix4x4& Matrix)
{
	Vector3 result;

	result.x = vector.x * Matrix.m[0][0] + vector.y * Matrix.m[1][0] + vector.z * Matrix.m[2][0] + 1.0f * Matrix.m[3][0];
	result.y = vector.x * Matrix.m[0][1] + vector.y * Matrix.m[1][1] + vector.z * Matrix.m[2][1] + 1.0f * Matrix.m[3][1];
	result.z = vector.x * Matrix.m[0][2] + vector.y * Matrix.m[1][2] + vector.z * Matrix.m[2][2] + 1.0f * Matrix.m[3][2];
	float w = vector.x * Matrix.m[0][3] + vector.y * Matrix.m[1][3] + vector.z * Matrix.m[2][3] + 1.0f * Matrix.m[3][3];
	assert(w != 0.0f);
	result.x /= w;
	result.y /= w;
	result.z /= w;

	return result;

}


void OwnMatrix4x4::MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label)
{
	Novice::ScreenPrintf(x, y, "%s", label);

	for (int row = 0; row < 4; row++)
	{
		for (int column = 0; column < 4; column++)
		{
			Novice::ScreenPrintf(x + column * kColumnWidth, y + row * kColumnHeight + 20, "%6.02f\n", matrix.m[row][column]);
		}

	}
}

void OwnMatrix4x4::VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label)
{
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kColumnWidth * 4, y, "%s", label);
}

Matrix4x4 OwnMatrix4x4::MakeRotateXMatrix(float radian)
{
	Matrix4x4 result{
		1, 0, 0, 0,
		0, std::cos(radian), std::sin(radian), 0,
		0, -std::sin(radian), std::cos(radian), 0,
		0, 0, 0, 1
	};
	return result;
}

Matrix4x4 OwnMatrix4x4::MakeRotateYMatrix(float radian)
{
	Matrix4x4 result{
		 std::cos(radian), 0, -std::sin(radian), 0,
		0, 1, 0, 0,
		std::sin(radian), 0, std::cos(radian), 0,
		0, 0, 0, 1
	};
	return result;
}

Matrix4x4 OwnMatrix4x4::MakeRotateZMatrix(float radian)
{
	Matrix4x4 result{
		 std::cos(radian), std::sin(radian), 0, 0,
		-std::sin(radian),  std::cos(radian), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};
	return result;
}

Matrix4x4 OwnMatrix4x4::MakeAffineMatrix(const Vector3& scale, const Vector3& rot, const Vector3& translate)
{
	//Matrix4x4 Scale{
	//	scale.x, 0, 0, 0,
	//	0, scale.y, 0, 0,
	//	0, 0, scale.z, 0,
	//	0, 0, 0, 1
	//};
	//
	//Matrix4x4 Translate{
	//	1, 0, 0, 0,
	//	0, 1, 0, 0,
	//	0, 0, 1, 0,
	//	translate.x, translate.y, translate.z, 1
	//};

	Matrix4x4 MakeRotateMatrixZ{
			std::cos(rot.z), std::sin(rot.z), 0, 0,
			-std::sin(rot.z), std::cos(rot.z), 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
	};

	Matrix4x4 MakeRotateMatrixX{
			1, 0, 0, 0,
			0, std::cos(rot.x), std::sin(rot.x), 0,
			0, -std::sin(rot.x), std::cos(rot.x), 0,
			0, 0, 0, 1
	};

	Matrix4x4 MakeRotateMatrixY{
			std::cos(rot.y), 0, -std::sin(rot.y), 0,
			0, 1, 0, 0,
			std::sin(rot.y), 0, std::cos(rot.y), 0,
			0, 0, 0, 1
	};

	Matrix4x4 RotateYZ = Multiply(MakeRotateMatrixY, MakeRotateMatrixZ);
	//
	Matrix4x4 Rotate = Multiply(MakeRotateMatrixX, RotateYZ);
	//Matrix4x4 ScaleRotate = Multiply(Scale, Rotate);
	//Matrix4x4 result = Multiply(Translate, ScaleRotate);

	Matrix4x4 result{
		scale.x * Rotate.m[0][0], scale.x * Rotate.m[0][1], scale.x * Rotate.m[0][2], 0,
		scale.y * Rotate.m[1][0], scale.y * Rotate.m[1][1], scale.y * Rotate.m[1][2], 0,
		scale.z * Rotate.m[2][0], scale.z * Rotate.m[2][1], scale.z * Rotate.m[2][2], 0,
		translate.x, translate.y, translate.z, 1

	};

	return result;
}










