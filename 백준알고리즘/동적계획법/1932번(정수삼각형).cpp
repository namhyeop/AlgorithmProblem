#include<bits/stdc++.h>

using namespace std;
const int MAX = 501;

int cache[MAX][MAX];

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	for (int j = 0; j <= i; j++)
		cin >> cache[i][j];


	int maxValue = INT_MIN;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				cache[i][j] = cache[i - 1][0] + cache[i][j];
			else if (j == i)
				cache[i][j] = cache[i - 1][j - 1] + cache[i][j];
			else
				cache[i][j] = max(cache[i - 1][j - 1] + cache[i][j], cache[i - 1][j] + cache[i][j]);

			maxValue = max(maxValue, cache[i][j]);
		}
	}
	cout << maxValue << "\n";
	
	return 0;
}
