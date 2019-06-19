#include "Triangle.h"

Triangle::Triangle(Coordinate a, Coordinate b, Coordinate c) {
	A = a;
	B = b;
	C = c;
	center = Coordinate((A.x + B.x + C.x) / 3, (A.y + B.y + C.y) / 3, (A.z + B.z + C.z) / 3);
}

Triangle::~Triangle() {

}