#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
	ifstream ifile("lena.bmp");
	ofstream ofile("lenacp.bmp");

	if(!ifile.is_open()){
		cout << "file open error" << endl;
		exit(1);
	} 

	// BMP header extract
	// 여기서 추출한 헤더 내용은 출력파일의 앞부분에 write 하여야 함
	// 동일한 크기의 파일을 만들어야 할 때 사용되어야 함 
	char* headerData = new char[1078];
	ifile.read(headerData, 1078);
	// -------------
	// 다음 줄 부터 512 * 512 데이터를 읽어서 처리하면 됨  







    // 앞 부부분에 코드를 추가하야 함 
    // ---- 
	delete[] headerData;
	
	ifile.close();
	ofile.close();

	return 0;
}
