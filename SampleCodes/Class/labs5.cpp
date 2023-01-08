#include <iostream>

using namespace std;

class Data
{
	int* val;
	int* val2;
	int num;
public:
	Data(int i)
	{
		num = i;
		val = new int[i];
		init(val, i);
	}
	void init(int*, int);
	void insert(int);
	void deleteData(int);
	void show();

};

void Data::init(int* arr, int index)
{
	for (int i = 0; i < index; i++)
	{
		arr[i] = 0;
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
	{
		cout << "array extance" << endl;

		val2 = new int[num];

		for (int i = 0; i < num ; i++)
		{
			val2[i] = val[i];
		}

		val = new int[num * 2];
		init(val, num * 2);

		for (int i = 0; i < num; i++)
		{
			val[i] = val2[i];
		}

		num *= 2;

		insert(n);
	}
	
	
}
void Data::deleteData(int n)
{
	val[n] = 0;
	if (n < num - 1)
	{
		for (int i = n + 1; i < num; i++)
		{
			val[n] = val[i];
			n++;
		}
		val[num - 1] = 0;
	}
	
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
	Data data(5);

	data.show();
	data.insert(1);
	data.insert(2);
	data.insert(3);
	data.insert(4);
	data.insert(5);

	data.show();

	data.insert(6);
	data.insert(7);
	data.insert(8);
	data.insert(9);
	data.insert(10);

	data.show();

	cout << "delete" << endl;
	data.deleteData(3);
	data.show();
	

	return 0;
}