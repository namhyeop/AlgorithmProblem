#include<bits/stdc++.h>

using namespace std;
const int MAX = 1001;

int cache[MAX];
int main()
{
	int n;
	cin >> n;

	cache[1] = 1;
	cache[2] = 0;
	cache[3] = 1;
	cache[4] = 1;

	for (int i = 5; i <= n; i++)
	{
		if (cache[i - 1] + cache[i - 3] + cache[i - 4] == 3)
			cache[i] = 0;
		else
			cache[i] = 1;
	}

	if (cache[n] == 1)
		cout << "SK" << "\n";
	else
		cout << "CY" << "\n";
}
