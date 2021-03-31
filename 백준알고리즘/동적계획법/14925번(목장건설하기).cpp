#include<bits/stdc++.h>

using namespace std;
const int MAX = 1001;
int board[MAX][MAX];
int cache[MAX][MAX];

int main()
{
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
		cin >> board[i][j];

	//변의 길이
	int len = 0;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	{
		if (board[i][j] == 0)
		{
			cache[i][j] = min(cache[i - 1][j], min(cache[i][j - 1], cache[i - 1][j - 1])) + 1;
			len = max(len , cache[i][j]);
		}
	}
	cout << len << "\n";

	return 0;
}
