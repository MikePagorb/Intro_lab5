#pragma once

#include <string>
#include <iostream>

using namespace std;


typedef struct {
	int8_t id[2];
	int32_t filesize;
	int16_t reserved[2];
	int32_t headersize;
	int32_t infoSize;
	int32_t width;
	int32_t depth;
	int16_t biPlanes;
	int16_t bits;
	int32_t biCompression;
	int32_t biSizeImage;
	int32_t biXPelsPerMeter;
	int32_t biYPelsPerMeter;
	int32_t biClrUsed;
	int32_t biClrImportant;
} BMPHEAD;

typedef struct {
public:
	int8_t redComponent;
	int8_t greenComponent;
	int8_t blueComponent;
} RGBQUAD;

class picture {

	BMPHEAD header;
	RGBQUAD  **array;

public:
	picture() {};
	void writePicture();
};

void picture::writePicture()
{
	string line; line = "";  // путь к файлу для записи

	const char *file = line;

	FILE *fp2 = fopen(file, "wb");

	int32_t headerDepthOld = header.depth; // размеры исходника
	int32_t headerWidthOld = header.width;

	header.depth = int(header.depth * factor);
	header.width = int(header.width * factor); // NEW EDIT

	RGBQUAD **ARRAY = new RGBQUAD*[header.depth];
	for (int i = 0; i < header.depth; i++) {
		ARRAY[i] = new RGBQUAD[header.width];
	}


	for (int i = 0; i < header.depth; i++) // по Oy
	{
		for (int j = 0; j < header.width; j++) // по Ox
		{
			ARRAY[i][j].blueComponent = array[1][2].blueComponent;
			ARRAY[i][j].greenComponent = array[1][2].greenComponent;
			ARRAY[i][j].redComponent = array[1][2].redComponent;

		}
	}


	fwrite(&header.id, sizeof(header.id), 1, fp2);
	fwrite(&header.filesize, sizeof(header.filesize), 1, fp2);
	fwrite(&header.reserved, sizeof(header.reserved), 1, fp2);
	fwrite(&header.headersize, sizeof(header.headersize), 1, fp2);
	fwrite(&header.infoSize, sizeof(header.infoSize), 1, fp2);
	fwrite(&header.width, sizeof(header.width), 1, fp2);
	fwrite(&header.depth, sizeof(header.depth), 1, fp2);
	fwrite(&header.biPlanes, sizeof(header.biPlanes), 1, fp2);
	fwrite(&header.bits, sizeof(header.bits), 1, fp2);
	fwrite(&header.biCompression, sizeof(header.biCompression), 1, fp2);
	fwrite(&header.biSizeImage, sizeof(header.biSizeImage), 1, fp2);
	fwrite(&header.biXPelsPerMeter, sizeof(header.biXPelsPerMeter), 1, fp2);
	fwrite(&header.biYPelsPerMeter, sizeof(header.biYPelsPerMeter), 1, fp2);
	fwrite(&header.biClrUsed, sizeof(header.biClrUsed), 1, fp2);
	fwrite(&header.biClrImportant, sizeof(header.biClrImportant), 1, fp2);

	for (int i = 0; i < header.depth; i++) {
		for (int j = 0; j < header.width; j++) {
			fwrite(&ARRAY[i][j].blueComponent, 1, 1, fp2);
			fwrite(&ARRAY[i][j].greenComponent, 1, 1, fp2);
			fwrite(&ARRAY[i][j].redComponent, 1, 1, fp2);

			//            cout << "new pixel: [ " << i << " " << j << " ] " << int(ARRAY[i][j].redComponent) << " " << int(ARRAY[i][j].greenComponent) << " "<<  int(ARRAY[i][j].blueComponent) << endl;

		}
		int8_t empty = 0x00;
		if (stride != 0) {
			fwrite(&empty, 1, stride, fp2);
		}
	}

	fclose(fp2);


}