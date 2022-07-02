/*
	File: lvalue_rvalue.cc
	Author: Geun-Hyung Kim

 */

int main(int argc, char const *argv[])
{
	int i, j, *ptr;
	int &lvalue_ref = i;

	i = 7;

	7 = j;
	j * 4 = 7;

	ptr = i;
	*ptr = i;

	const int cvalue = 7;
	cvalue = 8;


	return 0;
}