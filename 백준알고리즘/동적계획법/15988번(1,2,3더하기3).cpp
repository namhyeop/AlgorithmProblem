#include<bits/stdc++.h>

using namespace std;
const int MAX = 1e6;
const int mod = 1e9 + 9;
int n;

long long cache[MAX + 1];

int main()
{
	int Testcase;
	cin >> Testcase;

	cache[1] = 1;
	cache[2] = 2;
	cache[3] = 4;
	for (int i = 4; i <= MAX; i++)
		cache[i] = (cache[i - 1] + cache[i - 2] + cache[i - 3]) % mod;

	while (Testcase--)
	{
		int tmp;
		cin >> tmp;
		cout << cache[tmp] << "\n";
	}
}
