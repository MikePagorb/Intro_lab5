#include <iostream>
#include "Coord.h"
#include "Ray_trace.h"
#include "ImagePPM.h"

using namespace std;

int main()
{
	RayTracer g;
	g.tracer();
	CreateimageFile();
	system("pause");
	return 0;
}