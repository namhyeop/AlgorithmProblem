#include<iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int microValue[3];
	microValue[0] = 10;
	microValue[1] = 60;
	microValue[2] = 300;

	int cookTime;
	int ret[3];
	cin >> cookTime;

	for (int i = 2; i >= 0; i--)
	{
		int cnt = ret[i] = cookTime / microValue[i];
		cookTime = cookTime % microValue[i];
	}

	if (cookTime != 0)
		cout << -1 << "\n";
	else
	for (int i = 2; i >= 0; i--)
		cout << ret[i] << " ";

	return 0;

}
