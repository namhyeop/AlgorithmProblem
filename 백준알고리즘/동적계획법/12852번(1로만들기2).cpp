#include<bits/stdc++.h>

using namespace std;
const int MAX = 1e7 + 5;

int cache[MAX];
int used[MAX];
int main()
{
	int n;
	cin >> n;
 
	cache[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		cache[i] = cache[i - 1] + 1;
		used[i] = i - 1;

		if (i % 2 == 0 && cache[i] > cache[i / 2] + 1)
		{
			cache[i] = cache[i/2] + 1;
			used[i] = i / 2;
		}

		if (i % 3 == 0 && cache[i] > cache[i / 3] + 1)
		{
			cache[i] = cache[i/3] + 1;
			used[i] = i / 3;
		}
	}

	cout << cache[n] << "\n";
	int cur = n;
	while (true)
	{
		cout << cur << ' ';
		if (cur == 1)
			break;
		cur = used[cur];
	}
}
