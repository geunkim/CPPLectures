#include "iostream"
using namespace std;

static int result = 0;

class Calculator
{
public:
	virtual int calculator(int x) = 0;
};

class Add : public Calculator
{
public:
	int calculator(int x)
	{
		result += x;
		return result;
	}
};

class Minus : public Calculator
{
public:
	int calculator(int x) 
	{
		result -= x;
		return result;
	}
};


int main(int argc, char const* argv[])
{
	int x;
	int num;
	Add add;
	Minus minus;
	Calculator* calculator = NULL;

	while (1)
	{
		x = 0;

		cout << "1:add  2:minus  3:reset  4:end" << endl;
		cout << "set calculation : ";
		cin >> num;

		cout << "set number : ";
		cin >> x;

		if (num == 1)
		{
			calculator = &add;
		}
		else if (num == 2)
		{
			calculator = &minus;
		}
		else if (num == 3)
		{
			result = 0;
			x = 0;
		}
		else if (num == 4)
		{
			cout << "result : " << result << endl;
			break;
		}
		else
		{
			cout << "wrong number error" << endl;
			break;
		}

		cout << "result : " << calculator->calculator(x) << endl;

	}

	return 0;
}