#include<bits/stdc++.h>

using namespace std;

int n;
long long cache[91];

int main()
{
	cin >> n;
	cache[0] = 0;
	cache[1] = 1;

	for (int i = 2; i <= n; i++)
		cache[i] = cache[i - 2] + cache[i - 1];
	
	cout << cache[n] << "\n";
	return 0;
}
