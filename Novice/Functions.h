#pragma once
#include "Vector4.h"

static const int kColumnWidth = 60;
static const int kColumnHeight = 20;
const int kWindowWidth = 1280;
const int kWindowHeight = 720;

struct Vector3 {
	float x, y, z;
};

struct Matrix4x4 {
	float m[4][4];
};

struct Sphere {
	Vector3 center;
	float radius;
};