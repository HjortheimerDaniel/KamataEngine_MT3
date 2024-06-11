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
	int color;
};

struct Plane {
	Vector3 normal;
	float distance;
};

struct Line {
	Vector3 origin; //start point
	Vector3 diff; //difference between start and end
};

struct Ray {
	Vector3 origin; //start point
	Vector3 diff; //difference between start and end
};

struct Segment {
	Vector3 origin; //start point
	Vector3 diff; //difference between start and end
	int color;
};

struct Triangle {
	Vector3 vertices[3];
	int color;
};

struct AABB {
	Vector3 min;
	Vector3 max;
	int color;
};