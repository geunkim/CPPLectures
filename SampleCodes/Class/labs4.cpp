#include <iostream>

using namespace std;

class Data
{
	int val[10];
	int num = 10;
public:
	Data() 
	{ 
		init();
	}
	void init();
	void insert(int);
	void show();
};

void Data::init()
{
	for (int i = 0; i < 10; i++)
	{
		val[i] = 0;
	}
}
void Data::insert(int n)
{
	if (val[num - 1] == 0)
	{
		for (int i = 0; i < num; i++)
		{
			if (val[i] == 0)
			{
				val[i] = n;
				return;
			}
		}
	}
	else
		cout << "array has full" << endl;
}
void Data::show()
{
	for (int i = 0; i < num; i++)
	{
		cout << val[i] << " ";
	}
	cout << endl;
}

int main(int argc, const char* argv[])
{
	Data data;
	data.show();
	data.insert(1);
	data.insert(2);
	data.insert(3);

	data.show();

	return 0;
}