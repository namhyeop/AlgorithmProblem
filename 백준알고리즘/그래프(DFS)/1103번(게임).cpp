#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 50;
bool visited[MAX][MAX];
char board[MAX][MAX];
int cache[MAX][MAX];
int moveY[] = { -1, 1, 0, 0 };
int moveX[] = { 0, 0, -1, 1 };
int n, m, ret;
bool cycle;
int main(void)
{
	fastio;
	cin >> n >> m;

	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
		cin >> board[i][j];

	function<int(int, int)> DFS = [&](int y, int x)
	{
		if (y < 0 || y >= n || x < 0 || x >= m)
			return 0;
		if (board[y][x] == 'H')
			return 0;
		if (visited[y][x])
		{
			cycle = true;
			return -1;
		}
		int &ret = cache[y][x];
		if (ret != -1)
			return ret;
		visited[y][x] = true;
		for (int i = 0; i < 4; i++)
		{
			int nextY = y + (board[y][x] -'0') * moveY[i];
			int nextX = x + (board[y][x] -'0') * moveX[i];
			ret = max(ret, DFS(nextY, nextX) + 1);
		}
		visited[y][x] = false;
		return ret;
	};
	ret = DFS(0, 0);
	
	if (cycle)
		cout << -1 << "\n";
	else
		cout << ret << "\n";

	return 0;
}
