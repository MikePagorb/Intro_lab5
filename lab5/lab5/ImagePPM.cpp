#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ImagePPM.h"

using namespace std;

void CreateimageFile()
{
	char buff[] = {
		'P', '6', '\n',
		'3', ' ', '2','\n',
		'2', '5', '5','\n',
		255, 0, 0,
		0, 255,0,
		0,0,255,
		255,255,0,
		255,255,255,
		0,0,0
	};
	int size = sizeof(buff) / sizeof(buff[0]);
	FILE *pImage = fopen("Img.ppm", "wb");
	fwrite(buff, 1, size, pImage);
	fclose(pImage);
}