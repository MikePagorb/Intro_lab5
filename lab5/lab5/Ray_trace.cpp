#include <iostream>
#include "Ray_trace.h"
#include <cmath>
using namespace std;

#define PI            3.14159265358979323846

RayTracer::RayTracer() {

}

RayTracer::~RayTracer() {

}

void RayTracer::tracer() {
	
	Coordinate cameraPos(0, 0, -7);
	
	Coordinate cameraDir(0, 0, 1);
	
	Coordinate planeOrigin = cameraPos + cameraDir.singleVector();

	float fov = 60; 

	int Width = 100;
	int Height = 100;
	bool** screenBuffer = new bool*[Width];

	for (int i = 0; i < Height; i++)
		screenBuffer[i] = new bool[Height];

	Coordinate A(0, 0, 0);
	Coordinate B(-2, 1, 0);
	Coordinate C(1, 1, 0);
	Triangle triangleToDraw(A, B, C);

	for (int x = 0; x < Width; x++) {
		for (int y = 0; y < Height; y++) {
			screenBuffer[x][y] = false;
			
			float xNormal = (x - Width / 2) / (float)Width;
			float yNormal = -(y - Height / 2) / (float)Height;

			float distanceToPlaneFromCamera = (cameraPos - planeOrigin).length();
			
			float fovInRad = fov / (float)180 * PI;

			
			float realPlaneHeight = (float)(distanceToPlaneFromCamera * tan(fovInRad));

			Coordinate temp(xNormal * realPlaneHeight / 2, yNormal * realPlaneHeight / 2, 0);
			Coordinate positionOnPlane = planeOrigin + temp;

			Coordinate rayDirection = positionOnPlane - cameraPos;

			
			if (ThereIsIntersectionBetweenRayAndTriangle(cameraPos, rayDirection, triangleToDraw))
				screenBuffer[x][y] = true;
		}
	}
	DrawScreenBuffer(Height, Width, screenBuffer);
}

void RayTracer::DrawScreenBuffer(int screenHeight, int screenWidth, bool** screenBuffer)
{
	
	for (int y = 0; y < screenHeight; y++)
	{
		for (int x = 0; x < screenWidth; x++)
		{
			if (screenBuffer[x][y])
				cout << "X";
			else
				cout << ".";
		}
		cout << endl;
	}
}


bool RayTracer::ThereIsIntersectionBetweenRayAndTriangle(Coordinate rayOrigin, Coordinate rayVector, Triangle inTriangle) {
	Coordinate vertex0 = inTriangle.A;
	Coordinate vertex1 = inTriangle.B;
	Coordinate vertex2 = inTriangle.C;
	Coordinate edge1 = vertex1 - vertex0;
	Coordinate edge2 = vertex2 - vertex0;
	Coordinate h = rayVector.CrossProduct(edge2);
	float a = edge1.DotProduct(h);
	float EPSILON = 1e-5f;
	if (a > -EPSILON && a < EPSILON)
		return false;
	float f = 1 / a;
	Coordinate s = rayOrigin - vertex0;
	float u = f * s.DotProduct(h);
	if (u < 0.0 || u > 1.0)
		return false;
	Coordinate q = s.CrossProduct(edge1);
	float v = f * rayVector.DotProduct(q);
	if (v < 0.0 || u + v > 1.0)
		return false;
	
	float t = f * edge2.DotProduct(q);
	return t > EPSILON;
}