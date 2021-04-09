#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;
const int MAX = 101;
int n;
string tmpboard[MAX];
int board[MAX][MAX];
ll cache[MAX][MAX];

ll search(int y, int x)
{
	if (y < 0 || y >= n || x < 0 || x >= n)
		return 0;

	if (y == n - 1 && x == n - 1)
		return 1;

	if (board[y][x] == 0)
		return 0;

	ll &ret = cache[y][x];

	if (ret != -1)
		return cache[y][x];

	ret = search(y + board[y][x], x) + search(y, x + board[y][x]);

	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (1)
	{
		cin >> n;
		
		if (n == -1)
			return 0;

		for (int i = 0; i < n; i++)
			cin >> tmpboard[i];

		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			board[i][j] = (tmpboard[i][j]) -'0';
		memset(cache, -1, sizeof(cache));

    cout << search(0, 0) << "\n";
	}
}
