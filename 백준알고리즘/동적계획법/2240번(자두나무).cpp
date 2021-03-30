#include<bits/stdc++.h>

using namespace std;
const int MAX = 1001;
int arr[MAX];
int cache[3][MAX][32];


int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m + 1; j++)
	{
		if (arr[i] == 1)
		{
			cache[1][i][j] = max(cache[1][i - 1][j] + 1, cache[2][i - 1][j - 1] + 1);
			cache[2][i][j] = max(cache[1][i - 1][j - 1], cache[2][i - 1][j]);
		}
		else
		{
			if (i == 1 && j == 1)
				continue;

			cache[1][i][j] = max(cache[1][i - 1][j], cache[2][i - 1][j - 1]);
			cache[2][i][j] = max(cache[1][i - 1][j - 1] + 1, cache[2][i - 1][j] + 1);
		}
	}

	int ret = 0;
	for (int i = 1; i <= m + 1; i++)
		ret = max(ret, max(cache[1][n][i], cache[2][n][i]));
	
	cout << ret << "\n";

	return 0;
}
