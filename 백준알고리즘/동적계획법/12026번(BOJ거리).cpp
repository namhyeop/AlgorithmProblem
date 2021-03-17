#include<bits/stdc++.h>
#define MAX 1001
using namespace std;

int n;
char board[MAX];
int cache[MAX];

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> board[i];

	fill(cache, cache + MAX, 1e9);
	cache[1] = 0;

	for (int i = 1; i < n; i++)
	{
		if (board[i] == 'B')
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (board[j] == 'O')
					cache[j] = min(cache[j], (j - i) * (j - i) + cache[i]);
			}
		}
		else if (board[i] == 'O')
		{
			for (int j = i + 1; j <= n; j++)
			if (board[j] == 'J')
				cache[j] = min(cache[j], (j - i) * (j - i) + cache[i]);
		}
		else
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (board[j] == 'B')
				{
					cache[j] = min(cache[j], (j - i) *(j - i) + cache[i]);
				}
			}
		}
	}

	if (cache[n] == 1e9)
		cout << -1 << "\n";
	else
		cout << cache[n] << "\n";
	return 0;
}
