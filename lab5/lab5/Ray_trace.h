#pragma once

#include "Triangle.h"
#include "Coord.h"

class RayTracer {
public:
	RayTracer();
	~RayTracer();

	void tracer();
	bool ThereIsIntersectionBetweenRayAndTriangle(Coordinate, Coordinate, Triangle);
	void DrawScreenBuffer(int, int, bool**);
};