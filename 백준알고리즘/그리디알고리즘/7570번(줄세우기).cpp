#include<bits/stdc++.h>

using namespace std;
const int MAX = 1e6 + 1;
int n;
int cache[MAX];
int maxValue;

int main()
{
	cin >> n;

	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		cache[tmp] = cache[tmp - 1] + 1;
		maxValue = max(maxValue, cache[tmp]);
	}
	
	cout << n - maxValue << "\n";

	return 0;
}
