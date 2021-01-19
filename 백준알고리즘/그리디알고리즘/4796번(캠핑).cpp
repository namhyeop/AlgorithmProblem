#include<iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int i = 1;
	while (1)
	{
		int L, P, V;
		cin >> L >> P >> V;

		if (L == 0 && P == 0 && V == 0)
			return 0;

		int possibleNum = V / P;
		int possibleRm = V % P > L ? L : V % P;
		//cout << possibleNum << " " << possibleRm << "\n";
		int ret = ((possibleNum * L) + possibleRm);
		cout << "Case " << i <<": "<< ret << "\n";
		i++;
	}
	return 0;
}
