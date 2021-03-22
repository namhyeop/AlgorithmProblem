#include<bits/stdc++.h>

using namespace std;

int N;
int Xi;
int Pi;
int maxPi;
int tolerance = 1;

long long ret;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> Xi >> Pi;
		if (ret <= Xi)
		{
			ret += Pi;
			maxPi = Pi > maxPi ? Pi : maxPi;
		}
		else if (ret - maxPi > Xi || maxPi < Pi)
		{
			tolerance--;
		}
		else
		{
			tolerance--;
			ret -= maxPi;
			ret += Pi;
		}
		if (tolerance < 0)
		{
			cout << "Zzz" << "\n";
			return 0;
		}
	}
	cout << "Kkeo-eok";
	return 0;
}
