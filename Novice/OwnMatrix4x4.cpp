#include "OwnMatrix4x4.h"

void OwnMatrix4x4::DrawGrid(const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix) {
	const float kGridHalfWidth = 2.0f;
	const uint32_t kSubDivision = 10;
	const float kGridEvery = (kGridHalfWidth * 2.0f) / float(kSubDivision);
	Vector3 start[kSubDivision + 1]{};
	Vector3 end[kSubDivision + 1]{};
	Vector3 ndcVertexStart[kSubDivision + 1]{};
	Vector3 screenVerticesStart[kSubDivision + 1]{};
	Vector3 ndcVertexEnd[kSubDivision + 1]{};
	Vector3 screenVerticesEnd[kSubDivision + 1]{};
	int color = 0xAAAAAAFF;

	for (uint32_t xIndex = 0; xIndex <= kSubDivision; xIndex++) {
		// Vector3 pos;

		start[xIndex].x = (-5.0f + xIndex) * kGridEvery; // start of the x line
		end[xIndex].x = (-5.0f + xIndex) * kGridEvery;
		start[xIndex].z = -kGridHalfWidth; // space between lines
		end[xIndex].z = kGridHalfWidth;
		// pos.x = -kGridHalfWidth + xIndex * kGridEvery; // Calculate the x position

		ndcVertexStart[xIndex] = Transform(start[xIndex], viewProjectionMatrix); // change into screen coord
		screenVerticesStart[xIndex] = Transform(ndcVertexStart[xIndex], viewportMatrix);
		ndcVertexEnd[xIndex] = Transform(end[xIndex], viewProjectionMatrix);
		screenVerticesEnd[xIndex] = Transform(ndcVertexEnd[xIndex], viewportMatrix);

		if (xIndex == 5) {
			color = BLACK;
		} else {
			color = 0xAAAAAAFF;
		}

		//Novice::ScreenPrintf(0, 30 * xIndex, "%f", start[xIndex].x);
		//Novice::ScreenPrintf(100, 30 * xIndex, "%f", end[xIndex].x);
		Novice::DrawLine((int)screenVerticesStart[xIndex].x, (int)screenVerticesStart[xIndex].y, (int)screenVerticesEnd[xIndex].x, (int)screenVerticesEnd[xIndex].y, color);
	}

	for (uint32_t zIndex = 0; zIndex <= kSubDivision; zIndex++) {

		start[zIndex].x = -kGridHalfWidth;
		end[zIndex].x = kGridHalfWidth;
		start[zIndex].z = (-5.0f + zIndex) * kGridEvery;
		end[zIndex].z = (-5.0f + zIndex) * kGridEvery;
		ndcVertexStart[zIndex] = Transform(start[zIndex], viewProjectionMatrix);
		screenVerticesStart[zIndex] = Transform(ndcVertexStart[zIndex], viewportMatrix);
		ndcVertexEnd[zIndex] = Transform(end[zIndex], viewProjectionMatrix);
		screenVerticesEnd[zIndex] = Transform(ndcVertexEnd[zIndex], viewportMatrix);
		// pos.x = -kGridHalfWidth + xIndex * kGridEvery; // Calculate the x position

		if (zIndex == 5) {
			color = BLACK;
		} else {
			color = 0xAAAAAAFF;
		}

		//Novice::ScreenPrintf(300, 30 * zIndex, "%f", start[zIndex].z);
		//Novice::ScreenPrintf(500, 30 * zIndex, "%f", end[zIndex].z);
		Novice::DrawLine((int)screenVerticesStart[zIndex].x, (int)screenVerticesStart[zIndex].y, (int)screenVerticesEnd[zIndex].x, (int)screenVerticesEnd[zIndex].y, color);
	}
}

void OwnMatrix4x4::DrawSphere(const Sphere& sphere, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color) {
	const uint32_t kSubdivision = 20; // amount of lines
	const float pi = float(M_PI);
	const float longD = pi / kSubdivision;		// longitude of 1 line
	const float latiD = (2 * pi) / kSubdivision;	// latitude of 1 line

	for (uint32_t latIndex = 0; latIndex < kSubdivision; latIndex++) {
		float lat = (-pi / 2.0f) + (latiD * latIndex); // the latitude line we are currently on

		for (uint32_t longIndex = 0; longIndex < kSubdivision; longIndex++) {
			float lon = longIndex * longD; // the longitude line we are currently on

			Vector3 a, b, c;

			a = {cosf(lat) * cosf(lon) * sphere.radius + sphere.center.x, sinf(lat) * sphere.radius + sphere.center.y, cosf(lat) * sinf(lon) * sphere.radius + sphere.center.z};
			b = {cosf(lat + latiD) * cosf(lon) * sphere.radius + sphere.center.x, sinf(lat + latiD) * sphere.radius + sphere.center.y, cosf(lat + latiD) * sin(lon) * sphere.radius + sphere.center.z};
			c = {cosf(lat) * cosf(lon + longD) * sphere.radius + sphere.center.x, sinf(lat) * sphere.radius + sphere.center.y, cosf(lat) * sinf(lon + longD) * sphere.radius + sphere.center.z};

			Vector3 screenTransformA = Transform(Transform(a, viewProjectionMatrix), viewportMatrix);
			Vector3 screenTransformB = Transform(Transform(b, viewProjectionMatrix), viewportMatrix);
			Vector3 screenTransformC = Transform(Transform(c, viewProjectionMatrix), viewportMatrix);
			Novice::DrawLine((int)screenTransformA.x, (int)screenTransformA.y, (int)screenTransformB.x, (int)screenTransformB.y, color);
			Novice::DrawLine((int)screenTransformA.x, (int)screenTransformA.y, (int)screenTransformC.x, (int)screenTransformC.y, color);
		}
	}
}

Matrix4x4 OwnMatrix4x4::Add(Matrix4x4& m1, Matrix4x4& m2) {
	Matrix4x4 result{
	    m1.m[0][0] + m2.m[0][0], m1.m[0][1] + m2.m[0][1], m1.m[0][2] + m2.m[0][2], m1.m[0][3] + m2.m[0][3], m1.m[1][0] + m2.m[1][0], m1.m[1][1] + m2.m[1][1],
	    m1.m[1][2] + m2.m[1][2], m1.m[1][3] + m2.m[1][3], m1.m[2][0] + m2.m[2][0], m1.m[2][1] + m2.m[2][1], m1.m[2][2] + m2.m[2][2], m1.m[2][3] + m2.m[2][3],
	    m1.m[3][0] + m2.m[3][0], m1.m[3][1] + m2.m[3][1], m1.m[3][2] + m2.m[3][2], m1.m[3][3] + m2.m[3][3],
	};

	return result;
}

Vector3 OwnMatrix4x4::Add(const Vector3& v1, const Vector3& v2)
{
	Vector3 result{ v1.x + v2.x, v1.y + v2.y, v1.z + v2.z };
	return result;
}

Matrix4x4 OwnMatrix4x4::Subtract(Matrix4x4& m1, Matrix4x4& m2) {
	Matrix4x4 result{
	    m1.m[0][0] - m2.m[0][0], m1.m[0][1] - m2.m[0][1], m1.m[0][2] - m2.m[0][2], m1.m[0][3] - m2.m[0][3], m1.m[1][0] - m2.m[1][0], m1.m[1][1] - m2.m[1][1],
	    m1.m[1][2] - m2.m[1][2], m1.m[1][3] - m2.m[1][3], m1.m[2][0] - m2.m[2][0], m1.m[2][1] - m2.m[2][1], m1.m[2][2] - m2.m[2][2], m1.m[2][3] - m2.m[2][3],
	    m1.m[3][0] - m2.m[3][0], m1.m[3][1] - m2.m[3][1], m1.m[3][2] - m2.m[3][2], m1.m[3][3] - m2.m[3][3],
	};
	return result;
}

Vector3 OwnMatrix4x4::Subtract(const Vector3& v1, const Vector3& v2)
{
	Vector3 result{ v1.x - v2.x, v1.y - v2.y, v1.z - v2.z };
	return result;
}

Matrix4x4 OwnMatrix4x4::Multiply(Matrix4x4& m1, Matrix4x4& m2) {
	Matrix4x4 result{
	    m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0] + m1.m[0][2] * m2.m[2][0] + m1.m[0][3] * m2.m[3][0],
	    /*here*/ m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1] + m1.m[0][2] * m2.m[2][1] + m1.m[0][3] * m2.m[3][1],
	    /*here*/ m1.m[0][0] * m2.m[0][2] + m1.m[0][1] * m2.m[1][2] + m1.m[0][2] * m2.m[2][2] + m1.m[0][3] * m2.m[3][2],
	    /*here*/ m1.m[0][0] * m2.m[0][3] + m1.m[0][1] * m2.m[1][3] + m1.m[0][2] * m2.m[2][3] + m1.m[0][3] * m2.m[3][3],
	    m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0] + m1.m[1][2] * m2.m[2][0] + m1.m[1][3] * m2.m[3][0],
	    /*here*/ m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1] + m1.m[1][2] * m2.m[2][1] + m1.m[1][3] * m2.m[3][1],
	    /*here*/ m1.m[1][0] * m2.m[0][2] + m1.m[1][1] * m2.m[1][2] + m1.m[1][2] * m2.m[2][2] + m1.m[1][3] * m2.m[3][2],
	    /*here*/ m1.m[1][0] * m2.m[0][3] + m1.m[1][1] * m2.m[1][3] + m1.m[1][2] * m2.m[2][3] + m1.m[1][3] * m2.m[3][3],
	    m1.m[2][0] * m2.m[0][0] + m1.m[2][1] * m2.m[1][0] + m1.m[2][2] * m2.m[2][0] + m1.m[2][3] * m2.m[3][0],
	    /*here*/ m1.m[2][0] * m2.m[0][1] + m1.m[2][1] * m2.m[1][1] + m1.m[2][2] * m2.m[2][1] + m1.m[2][3] * m2.m[3][1],
	    /*here*/ m1.m[2][0] * m2.m[0][2] + m1.m[2][1] * m2.m[1][2] + m1.m[2][2] * m2.m[2][2] + m1.m[2][3] * m2.m[3][2],
	    /*here*/ m1.m[2][0] * m2.m[0][3] + m1.m[2][1] * m2.m[1][3] + m1.m[2][2] * m2.m[2][3] + m1.m[2][3] * m2.m[3][3],
	    m1.m[3][0] * m2.m[0][0] + m1.m[3][1] * m2.m[1][0] + m1.m[3][2] * m2.m[2][0] + m1.m[3][3] * m2.m[3][0],
	    /*here*/ m1.m[3][0] * m2.m[0][1] + m1.m[3][1] * m2.m[1][1] + m1.m[3][2] * m2.m[2][1] + m1.m[3][3] * m2.m[3][1],
	    /*here*/ m1.m[3][0] * m2.m[0][2] + m1.m[3][1] * m2.m[1][2] + m1.m[3][2] * m2.m[2][2] + m1.m[3][3] * m2.m[3][2],
	    /*here*/ m1.m[3][0] * m2.m[0][3] + m1.m[3][1] * m2.m[1][3] + m1.m[3][2] * m2.m[2][3] + m1.m[3][3] * m2.m[3][3],

	};
	return result;
}

Vector3 OwnMatrix4x4::Multiply(Vector3& v1, Vector3& v2)
{
	Vector3 result
	{
		v1.x * v2.x,
		v1.y * v2.y,
		v1.z * v2.z
	};
	return result;
}

Vector3 OwnMatrix4x4::Multiply(const float& f, const Vector3& v1)
{
	Vector3 result
	{
		f * v1.x,
		f * v1.y,
		f * v1.z
	};
	return result;
}

Matrix4x4 OwnMatrix4x4::Inverse(Matrix4x4& m1) {
	float A = m1.m[0][0] * m1.m[1][1] * m1.m[2][2] * m1.m[3][3] + m1.m[0][0] * m1.m[1][2] * m1.m[2][3] * m1.m[3][1] + m1.m[0][0] * m1.m[1][3] * m1.m[2][1] * m1.m[3][2] -
	          m1.m[0][0] * m1.m[1][3] * m1.m[2][2] * m1.m[3][1] - m1.m[0][0] * m1.m[1][2] * m1.m[2][1] * m1.m[3][3] - m1.m[0][0] * m1.m[1][1] * m1.m[2][3] * m1.m[3][2] -
	          m1.m[0][1] * m1.m[1][0] * m1.m[2][2] * m1.m[3][3] - m1.m[0][2] * m1.m[1][0] * m1.m[2][3] * m1.m[3][1] - m1.m[0][3] * m1.m[1][0] * m1.m[2][1] * m1.m[3][2] +
	          m1.m[0][3] * m1.m[1][0] * m1.m[2][2] * m1.m[3][1] + m1.m[0][2] * m1.m[1][0] * m1.m[2][1] * m1.m[3][3] + m1.m[0][1] * m1.m[1][0] * m1.m[2][3] * m1.m[3][2] +
	          m1.m[0][1] * m1.m[1][2] * m1.m[2][0] * m1.m[3][3] + m1.m[0][2] * m1.m[1][3] * m1.m[2][0] * m1.m[3][1] + m1.m[0][3] * m1.m[1][1] * m1.m[2][0] * m1.m[3][2] -
	          m1.m[0][3] * m1.m[1][2] * m1.m[2][0] * m1.m[3][1] - m1.m[0][2] * m1.m[1][1] * m1.m[2][0] * m1.m[3][3] - m1.m[0][1] * m1.m[1][3] * m1.m[2][0] * m1.m[3][2] -
	          m1.m[0][1] * m1.m[1][2] * m1.m[2][3] * m1.m[3][0] - m1.m[0][2] * m1.m[1][3] * m1.m[2][1] * m1.m[3][0] - m1.m[0][3] * m1.m[1][1] * m1.m[2][2] * m1.m[3][0] +
	          m1.m[0][3] * m1.m[1][2] * m1.m[2][1] * m1.m[3][0] + m1.m[0][2] * m1.m[1][1] * m1.m[2][3] * m1.m[3][0] + m1.m[0][1] * m1.m[1][3] * m1.m[2][2] * m1.m[3][0];

	Matrix4x4 result;

	result.m[0][0] = 1 / A *
	                 (m1.m[1][1] * m1.m[2][2] * m1.m[3][3] + m1.m[1][2] * m1.m[2][3] * m1.m[3][1] + m1.m[1][3] * m1.m[2][1] * m1.m[3][2] - m1.m[1][3] * m1.m[2][2] * m1.m[3][1] -
	                  m1.m[1][2] * m1.m[2][1] * m1.m[3][3] - m1.m[1][1] * m1.m[2][3] * m1.m[3][2]);
	result.m[0][1] = 1 / A *
	                 (-m1.m[0][1] * m1.m[2][2] * m1.m[3][3] - m1.m[0][2] * m1.m[2][3] * m1.m[3][1] - m1.m[0][3] * m1.m[2][1] * m1.m[3][2] + m1.m[0][3] * m1.m[2][2] * m1.m[3][1] +
	                  m1.m[0][2] * m1.m[2][1] * m1.m[3][3] + m1.m[0][1] * m1.m[2][3] * m1.m[3][2]);
	result.m[0][2] = 1 / A *
	                 (m1.m[0][1] * m1.m[1][2] * m1.m[3][3] + m1.m[0][2] * m1.m[1][3] * m1.m[3][1] + m1.m[0][3] * m1.m[1][1] * m1.m[3][2] - m1.m[0][3] * m1.m[1][2] * m1.m[3][1] -
	                  m1.m[0][2] * m1.m[1][1] * m1.m[3][3] - m1.m[0][1] * m1.m[1][3] * m1.m[3][2]);
	result.m[0][3] = 1 / A *
	                 (-m1.m[0][1] * m1.m[1][2] * m1.m[2][3] - m1.m[0][2] * m1.m[1][3] * m1.m[2][1] - m1.m[0][3] * m1.m[1][1] * m1.m[2][2] + m1.m[0][3] * m1.m[1][2] * m1.m[2][1] +
	                  m1.m[0][2] * m1.m[1][1] * m1.m[2][3] + m1.m[0][1] * m1.m[1][3] * m1.m[2][2]);

	result.m[1][0] = 1 / A *
	                 (-m1.m[1][0] * m1.m[2][2] * m1.m[3][3] - m1.m[1][2] * m1.m[2][3] * m1.m[3][0] - m1.m[1][3] * m1.m[2][0] * m1.m[3][2] + m1.m[1][3] * m1.m[2][2] * m1.m[3][0] +
	                  m1.m[1][2] * m1.m[2][0] * m1.m[3][3] + m1.m[1][0] * m1.m[2][3] * m1.m[3][2]);
	result.m[1][1] = 1 / A *
	                 (m1.m[0][0] * m1.m[2][2] * m1.m[3][3] + m1.m[0][2] * m1.m[2][3] * m1.m[3][0] + m1.m[0][3] * m1.m[2][0] * m1.m[3][2] - m1.m[0][3] * m1.m[2][2] * m1.m[3][0] -
	                  m1.m[0][2] * m1.m[2][0] * m1.m[3][3] - m1.m[0][0] * m1.m[2][3] * m1.m[3][2]);
	result.m[1][2] = 1 / A *
	                 (-m1.m[0][0] * m1.m[1][2] * m1.m[3][3] - m1.m[0][2] * m1.m[1][3] * m1.m[3][0] - m1.m[0][3] * m1.m[1][0] * m1.m[3][2] + m1.m[0][3] * m1.m[1][2] * m1.m[3][0] +
	                  m1.m[0][2] * m1.m[1][0] * m1.m[3][3] + m1.m[0][0] * m1.m[1][3] * m1.m[3][2]);
	result.m[1][3] = 1 / A *
	                 (m1.m[0][0] * m1.m[1][2] * m1.m[2][3] + m1.m[0][2] * m1.m[1][3] * m1.m[2][0] + m1.m[0][3] * m1.m[1][0] * m1.m[2][2] - m1.m[0][3] * m1.m[1][2] * m1.m[2][0] -
	                  m1.m[0][2] * m1.m[1][0] * m1.m[2][3] - m1.m[0][0] * m1.m[1][3] * m1.m[2][2]);

	result.m[2][0] = 1 / A *
	                 (m1.m[1][0] * m1.m[2][1] * m1.m[3][3] + m1.m[1][1] * m1.m[2][3] * m1.m[3][0] + m1.m[1][3] * m1.m[2][0] * m1.m[3][1] - m1.m[1][3] * m1.m[2][1] * m1.m[3][0] -
	                  m1.m[1][1] * m1.m[2][0] * m1.m[3][3] - m1.m[1][0] * m1.m[2][3] * m1.m[3][1]);
	result.m[2][1] = 1 / A *
	                 (-m1.m[0][0] * m1.m[2][1] * m1.m[3][3] - m1.m[0][1] * m1.m[2][3] * m1.m[3][0] - m1.m[0][3] * m1.m[2][0] * m1.m[3][1] + m1.m[0][3] * m1.m[2][1] * m1.m[3][0] +
	                  m1.m[0][1] * m1.m[2][0] * m1.m[3][3] + m1.m[0][0] * m1.m[2][3] * m1.m[3][1]);
	result.m[2][2] = 1 / A *
	                 (m1.m[0][0] * m1.m[1][1] * m1.m[3][3] + m1.m[0][1] * m1.m[1][3] * m1.m[3][0] + m1.m[0][3] * m1.m[1][0] * m1.m[3][1] - m1.m[0][3] * m1.m[1][1] * m1.m[3][0] -
	                  m1.m[0][1] * m1.m[1][0] * m1.m[3][3] - m1.m[0][0] * m1.m[1][3] * m1.m[3][1]);
	result.m[2][3] = 1 / A *
	                 (-m1.m[0][0] * m1.m[1][1] * m1.m[2][3] - m1.m[0][1] * m1.m[1][3] * m1.m[2][0] - m1.m[0][3] * m1.m[1][0] * m1.m[2][1] + m1.m[0][3] * m1.m[1][1] * m1.m[2][0] +
	                  m1.m[0][1] * m1.m[1][0] * m1.m[2][3] + m1.m[0][0] * m1.m[1][3] * m1.m[2][1]);

	result.m[3][0] = 1 / A *
	                 (-m1.m[1][0] * m1.m[2][1] * m1.m[3][2] - m1.m[1][1] * m1.m[2][2] * m1.m[3][0] - m1.m[1][2] * m1.m[2][0] * m1.m[3][1] + m1.m[1][2] * m1.m[2][1] * m1.m[3][0] +
	                  m1.m[1][1] * m1.m[2][0] * m1.m[3][2] + m1.m[1][0] * m1.m[2][2] * m1.m[3][1]);
	result.m[3][1] = 1 / A *
	                 (m1.m[0][0] * m1.m[2][1] * m1.m[3][2] + m1.m[0][1] * m1.m[2][2] * m1.m[3][0] + m1.m[0][2] * m1.m[2][0] * m1.m[3][1] - m1.m[0][2] * m1.m[2][1] * m1.m[3][0] -
	                  m1.m[0][1] * m1.m[2][0] * m1.m[3][2] - m1.m[0][0] * m1.m[2][2] * m1.m[3][1]);
	result.m[3][2] = 1 / A *
	                 (-m1.m[0][0] * m1.m[1][1] * m1.m[3][2] - m1.m[0][1] * m1.m[1][2] * m1.m[3][0] - m1.m[0][2] * m1.m[1][0] * m1.m[3][1] + m1.m[0][2] * m1.m[1][1] * m1.m[3][0] +
	                  m1.m[0][1] * m1.m[1][0] * m1.m[3][2] + m1.m[0][0] * m1.m[1][2] * m1.m[3][1]);
	result.m[3][3] = 1 / A *
	                 (m1.m[0][0] * m1.m[1][1] * m1.m[2][2] + m1.m[0][1] * m1.m[1][2] * m1.m[2][0] + m1.m[0][2] * m1.m[1][0] * m1.m[2][1] - m1.m[0][2] * m1.m[1][1] * m1.m[2][0] -
	                  m1.m[0][1] * m1.m[1][0] * m1.m[2][2] - m1.m[0][0] * m1.m[1][2] * m1.m[2][1]);

	return result;
}

Matrix4x4 OwnMatrix4x4::Transpose(Matrix4x4& m1) {
	Matrix4x4 result{m1.m[0][0], m1.m[1][0], m1.m[2][0], m1.m[3][0], m1.m[0][1], m1.m[1][1], m1.m[2][1], m1.m[3][1],
	                 m1.m[0][2], m1.m[1][2], m1.m[2][2], m1.m[3][2], m1.m[0][3], m1.m[1][3], m1.m[2][3], m1.m[3][3]};
	return result;
}

Matrix4x4 OwnMatrix4x4::MakeIdentify4x4() {
	Matrix4x4 result{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
	return result;
}

Matrix4x4 OwnMatrix4x4::MakeScaleMatrix(Vector3& scale) {
	Matrix4x4 result{scale.x, 0, 0, 0, 0, scale.y, 0, 0, 0, 0, scale.z, 0, 0, 0, 0, 1};
	return result;
}

Matrix4x4 OwnMatrix4x4::MakeTranslateMatrix(Vector3& translate) {
	Matrix4x4 result{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, translate.x, translate.y, translate.z, 1};
	return result;
}

Vector3 OwnMatrix4x4::Transform(const Vector3& vector, const Matrix4x4& Matrix) {
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

void OwnMatrix4x4::MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label) {
	Novice::ScreenPrintf(x, y, "%s", label);

	for (int row = 0; row < 4; row++) {
		for (int column = 0; column < 4; column++) {
			Novice::ScreenPrintf(x + column * kColumnWidth, y + row * kColumnHeight + 20, "%6.02f\n", matrix.m[row][column]);
		}
	}
}

void OwnMatrix4x4::VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label) {
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kColumnWidth * 4, y, "%s", label);
}

Matrix4x4 OwnMatrix4x4::MakeRotateXMatrix(float radian) {
	Matrix4x4 result{1, 0, 0, 0, 0, std::cos(radian), std::sin(radian), 0, 0, -std::sin(radian), std::cos(radian), 0, 0, 0, 0, 1};
	return result;
}

Matrix4x4 OwnMatrix4x4::MakeRotateYMatrix(float radian) {
	Matrix4x4 result{std::cos(radian), 0, -std::sin(radian), 0, 0, 1, 0, 0, std::sin(radian), 0, std::cos(radian), 0, 0, 0, 0, 1};
	return result;
}

Matrix4x4 OwnMatrix4x4::MakeRotateZMatrix(float radian) {
	Matrix4x4 result{std::cos(radian), std::sin(radian), 0, 0, -std::sin(radian), std::cos(radian), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
	return result;
}

Matrix4x4 OwnMatrix4x4::MakeAffineMatrix(const Vector3& scale, const Vector3& rot, const Vector3& translate) {

	Matrix4x4 MakeRotateMatrixZ{std::cos(rot.z), std::sin(rot.z), 0, 0, -std::sin(rot.z), std::cos(rot.z), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};

	Matrix4x4 MakeRotateMatrixX{1, 0, 0, 0, 0, std::cos(rot.x), std::sin(rot.x), 0, 0, -std::sin(rot.x), std::cos(rot.x), 0, 0, 0, 0, 1};

	Matrix4x4 MakeRotateMatrixY{std::cos(rot.y), 0, -std::sin(rot.y), 0, 0, 1, 0, 0, std::sin(rot.y), 0, std::cos(rot.y), 0, 0, 0, 0, 1};

	Matrix4x4 RotateYZ = Multiply(MakeRotateMatrixY, MakeRotateMatrixZ);

	Matrix4x4 Rotate = Multiply(MakeRotateMatrixX, RotateYZ);
	
	Matrix4x4 result{
	    scale.x * Rotate.m[0][0],
	    scale.x * Rotate.m[0][1],
	    scale.x * Rotate.m[0][2],
	    0,
	    scale.y * Rotate.m[1][0],
	    scale.y * Rotate.m[1][1],
	    scale.y * Rotate.m[1][2],
	    0,
	    scale.z * Rotate.m[2][0],
	    scale.z * Rotate.m[2][1],
	    scale.z * Rotate.m[2][2],
	    0,
	    translate.x,
	    translate.y,
	    translate.z,
	    1

	};

	return result;
}

Matrix4x4 OwnMatrix4x4::MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip) {
	Matrix4x4 result{1 / aspectRatio * 1 / std::tan(fovY / 2), 0, 0, 0, 0, 1 / std::tan(fovY / 2), 0, 0, 0, 0, farClip / (farClip - nearClip), 1, 0, 0, -nearClip * farClip / (farClip - nearClip), 0};

	return result;
}

Matrix4x4 OwnMatrix4x4::MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip) {
	Matrix4x4 result{2 / (right - left),
	                 0,
	                 0,
	                 0,
	                 0,
	                 2 / (top - bottom),
	                 0,
	                 0,
	                 0,
	                 0,
	                 1 / (farClip - nearClip),
	                 0,
	                 (left + right) / (left - right),
	                 (top + bottom) / (bottom - top),
	                 nearClip / (nearClip - farClip),
	                 1};
	return result;
}

Matrix4x4 OwnMatrix4x4::MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth) {
	Matrix4x4 result{width / 2, 0, 0, 0, 0, -(height / 2), 0, 0, 0, 0, maxDepth - minDepth, 0, left + (width / 2), top + (height / 2), minDepth, 1};
	return result;
}

Vector3 OwnMatrix4x4::Cross(const Vector3& v1, const Vector3& v2) {
	Vector3 result;
	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;

	return result;
}

Vector3 OwnMatrix4x4::Project(const Vector3& v1,const Vector3& v2)
{
	Vector3 result;

	float dotProduct = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
	float v2LengthSquared = (v2.x * v2.x) + (v2.y * v2.y) + (v2.z * v2.z);

	if(v2LengthSquared != 0.0f)
	{
		float projectionFactor = dotProduct / v2LengthSquared;

		result.x = projectionFactor * v2.x;
		result.y = projectionFactor * v2.y;
		result.z = projectionFactor * v2.z;
	} else{

		result = { 0.0f,0.0f,0.0f };
	}

	return result;
}



Vector3 OwnMatrix4x4::ClosestPoint(const Vector3& point, const Segment& segment)
{
	Vector3 project= Project(Subtract(point, segment.origin), segment.diff);
	return Add(segment.origin, project);
}

bool OwnMatrix4x4::IsCollision(const Sphere& s1, const Sphere& s2)
{
	float distance = Length(s1.center, s2.center);
	if (distance <= s1.radius + s2.radius) {
		return true;
	}
	return false;
}

//bool OwnMatrix4x4::IsCollision(const Sphere& sphere, const Plane& plane)
//{
//	return false;
//}

float OwnMatrix4x4::Length(const Vector3& point1, const Vector3& point2)
{
	Vector3 difference;
	difference.x = point1.x - point2.x;
	difference.y = point1.y - point2.y;
	difference.z = point1.z - point2.z;

	return sqrtf(difference.x * difference.x + difference.y * difference.y + difference.z * difference.z);
}

Vector3 OwnMatrix4x4::Perpendicular(const Vector3& vector)
{
	if(vector.x != 0.0f || vector.y != 0.0f)
	{
		return { -vector.y, vector.x, 0.0f };
	}
	return { 0.0f, -vector.z, vector.y };
}

void OwnMatrix4x4::DrawPlane(const Plane& plane, const Matrix4x4& viewProjectionMatrix, const Matrix4x4 viewPortMatrix, uint32_t color, uint32_t color2, uint32_t color3, uint32_t color4)
{

	Vector3 center = Multiply(plane.distance, plane.normal);
	Vector3 perpendiculars[4];
	perpendiculars[0] = Normalize(Perpendicular(plane.normal));
	perpendiculars[1] = { -perpendiculars[0].x, -perpendiculars[0].y, -perpendiculars[0].z };
	perpendiculars[2] = Cross(plane.normal, perpendiculars[0]);
	perpendiculars[3] = { -perpendiculars[2].x, -perpendiculars[2].y, -perpendiculars[2].z };

	Vector3 points[4];
	for (int32_t index = 0; index < 4; index++)
	{
		Vector3 extend = Multiply(2.0f, perpendiculars[index]);
		Vector3 point = Add(center, extend);
		points[index] = Transform(Transform(point, viewProjectionMatrix), viewPortMatrix);
	}
	Novice::DrawLine((int)points[0].x, (int)points[0].y, (int)points[2].x, (int)points[2].y, color);//white
	Novice::DrawLine((int)points[2].x, (int)points[2].y, (int)points[1].x, (int)points[1].y, color2);//red
	Novice::DrawLine((int)points[1].x, (int)points[1].y, (int)points[3].x, (int)points[3].y, color3);//blue
	Novice::DrawLine((int)points[3].x, (int)points[3].y, (int)points[0].x, (int)points[0].y, color4);//green
}

Vector3 OwnMatrix4x4::Normalize(Vector3 v)
{
	float normalize(v.x * v.x + v.y * v.y + v.z * v.z);

	if (normalize != 0) 
	{
		return Vector3(v.x / normalize, v.y / normalize, v.z / normalize);
	}
	return v;
}



