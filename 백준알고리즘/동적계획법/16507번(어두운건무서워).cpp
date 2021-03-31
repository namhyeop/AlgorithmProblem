#include<bits/stdc++.h>

using namespace std;
const int MAX = 1001;
int cache[MAX][MAX];
int board[MAX][MAX];
int r, c, k;

int main()
{
	cin >> r >> c >> k;

	for (int i = 1; i <= r; i++)
	for (int j = 1; j <= c; j++)
		cin >> board[i][j];

	for (int i = 1; i <= r; i++)
	for (int j = 1; j <= c; j++)
		cache[i][j] = cache[i - 1][j] + cache[i][j - 1] - cache[i - 1][j - 1] + board[i][j];


	for (int i = 0; i < k; i++)
	{
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		int ans = 0;
		ans = cache[y2][x2] - cache[y2][x1 - 1] - cache[y1 - 1][x2] + cache[y1 - 1][x1 - 1];
		int denominator = ((y2 - y1) + 1) * ((x2 - x1) + 1);
		ans /= denominator;
		cout << ans << "\n";
	}

	return 0;
}
