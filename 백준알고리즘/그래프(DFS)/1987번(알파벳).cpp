#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 21;
char board[MAX][MAX];
int ret;
map<char, int> s;
int moveY[] = { 1, -1, 0, 0 };
int moveX[] = { 0, 0, 1, -1 };
int main(void)
{
	fastio;
	int r, c;
	cin >> r >> c;

	function<void(int, int, long long, int)> dfs = [&](int y, int x, long long alphabet, int cnt)
	{
		alphabet |= (1 << (board[y][x] - 'A'));

		for (int i = 0; i < 4; i++)
		{
			int nextY = y + moveY[i];
			int nextX = x + moveX[i];

			if (0 <= nextY && nextY < r && 0 <= nextX && nextX < c)
			if (!(alphabet & (1 << (board[nextY][nextX] - 'A'))))
				dfs(nextY, nextX, alphabet, cnt + 1);
		}
		ret = max(ret, cnt);
	};

	string str;
	for (int i = 0; i < r; i++)
	{
		cin >> str;
		for (int j = 0; j < c; j++)
		{
			board[i][j] = str[j];
		}
	}
	dfs(0, 0, (long long)1 << 26, 1);
	cout << ret << "\n";
}
