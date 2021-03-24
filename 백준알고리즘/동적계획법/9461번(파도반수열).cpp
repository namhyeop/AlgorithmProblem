#include<bits/stdc++.h>

using namespace std;

int Testcase;
long long cache[101];

int main()
{
	int Testcase;
	cin >> Testcase;

	cache[1] = 1;
	cache[2] = 1;
	//cache[3] = 1;

	for (int i = 3; i <= 100; i++)
		cache[i] = cache[i - 2] + cache[i - 3];

	while (Testcase--)
	{
		int tmp;
		cin >> tmp;
		cout << cache[tmp] << "\n";
	}

	return 0;
} 
