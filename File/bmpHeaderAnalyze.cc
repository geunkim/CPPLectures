#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#pragma pack(push, 1)       // 구조체를 1 바이트 크기로 정렬

struct BITMAPFILEHEADER     // BMP 비트맵 파일 헤더 구조체
{
    unsigned short bfType;           // BMP 파일 매직 넘버
    unsigned int   bfSize;           // 파일 크기
    unsigned short bfReserved1;      // 예약
    unsigned short bfReserved2;      // 예약
    unsigned int   bfOffBits;        // 비트맵 데이터의 시작 위치
};

struct BITMAPINFOHEADER     // BMP 비트맵 정보 헤더 구조체(DIB 헤더)
{
    unsigned int   biSize;           // 현재 구조체의 크기
    int            biWidth;          // 비트맵 이미지의 가로 크기
    int            biHeight;         // 비트맵 이미지의 세로 크기
    unsigned short biPlanes;         // 사용하는 색상판의 수
    unsigned short biBitCount;       // 픽셀 하나를 표현하는 비트 수
    unsigned int   biCompression;    // 압축 방식
    unsigned int   biSizeImage;      // 비트맵 이미지의 픽셀 데이터 크기
    int            biXPelsPerMeter;  // 그림의 가로 해상도(미터당 픽셀)
    int            biYPelsPerMeter;  // 그림의 세로 해상도(미터당 픽셀)
    unsigned int   biClrUsed;        // 색상 테이블에서 실제 사용되는 색상 수
    unsigned int   biClrImportant;   // 비트맵을 표현하기 위해 필요한 색상 인덱스 수
};

struct bmpHeader{
	BITMAPFILEHEADER bmphead;
	BITMAPINFOHEADER bmpinfo;
	char *gap;
};

#pragma pack(pop) 


int main(int argc, char const *argv[])
{
	ifstream ifile("lena.bmp");
	ofstream ofile("lenacopy.bmp");

	BITMAPFILEHEADER bmphead;
	BITMAPINFOHEADER bmpinfo;

	if(!ifile.is_open()){
		cout << "file open error" << endl;
		exit(1);
	} 

	ifile.read((char *)&bmphead, sizeof(bmphead));
	ifile.read((char *)&bmpinfo, sizeof(bmpinfo));

	cout << "bf Size: " << bmphead.bfSize << endl;
	cout << "bit pixel offset: " << bmphead.bfOffBits << endl;

	cout << "bmpinfo struct size: " << bmpinfo.biSize << endl;
	cout << "width: " << bmpinfo.biWidth << endl;
	cout << "height: " << bmpinfo.biHeight << endl;
	cout << "Image pixel size: " << bmpinfo.biSizeImage << endl;

	int gap = bmphead.bfOffBits - (sizeof(bmphead) + sizeof(bmpinfo));

	cout << "gap: " << gap << endl;
ㅗㄷㅁㅇ
	ifile.close();
	ofile.close();

	return 0;
}