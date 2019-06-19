#pragma once

class Coordinate {
public:
	float x;
	float y;
	float z;

	Coordinate(float X = 0, float Y = 0, float Z = 0);
	~Coordinate();

	float length();
	void getCoordinate();
	Coordinate singleVector();

	Coordinate operator +(Coordinate);
	Coordinate operator -(Coordinate);
	Coordinate operator *(float);
	bool operator==(Coordinate);

	float distance(Coordinate);
	Coordinate CrossProduct(Coordinate);
	float DotProduct(Coordinate);
};