#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

	int payValue, suggestValue=1000;
	int count=0, sum;

	cin >> payValue;

	sum = suggestValue - payValue;

	if (sum >= 500)
	{
		count += sum / 500;
		sum %= 500;
	}

	if (sum >= 100)
	{
		count += sum / 100;
		sum %= 100;
	}

	if (sum >= 50)
	{
		count += sum/50;
		sum %= 50;
	}

	if (sum >= 10)
	{
		count += sum / 10;
		sum %= 10;
	}

	if (sum >= 5)
	{
		count += sum / 5;
		sum %= 5;
	}

	if (sum >= 1)
	{
		count += sum / 1;
	}

	cout << count;

}
