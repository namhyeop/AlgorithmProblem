#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

const int MAX = 500;

int n, m;
bool visited[MAX][MAX];
int board[MAX][MAX];
int moveY[] = { -1, 1, 0, 0 };
int moveX[] = { 0, 0, -1, 1 };

int exceptShape(int y, int x)
{
	int ret = INT_MIN;

	if (y > 0 && x > 0 && x < m - 1)
		ret = max(ret, board[y][x - 1] + board[y][x] + board[y - 1][x] + board[y][x + 1]);
	if (x > 0 && y < n - 1 && x < m - 1)
		ret = max(ret, board[y][x - 1] + board[y][x] + board[y][x + 1] + board[y + 1][x]);
	if (y > 0 && x > 0 && y < n - 1)
		ret = max(ret, board[y - 1][x] + board[y][x] + board[y][x - 1] + board[y + 1][x]);
	if (y > 0 && x < m - 1 && y < n - 1)
		ret = max(ret, board[y - 1][x] + board[y][x] + board[y + 1][x] + board[y][x + 1]);
	
	return ret;
}

int DFS(int y, int x, int cnt)
{
	if (cnt == 4)
		return board[y][x];

	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		int nextY = y + moveY[i];
		int nextX = x + moveX[i];
		
		if (0 <= nextY && nextY < n && 0 <= nextX && nextX < m)
		if (!visited[nextY][nextX])
		{
			visited[nextY][nextX] = true;
			sum = max(sum, board[y][x] + DFS(nextY, nextX, cnt + 1));
			visited[nextY][nextX] = false;
		}
	}
	return sum;
}

int main()
{
	fastio;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
		cin >> board[i][j];

	int ret = INT_MIN;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	{
		visited[i][j] = true;
		ret = max(ret, DFS(i, j, 1));
		ret = max(ret, exceptShape(i, j));
		visited[i][j] = false;
	}

	cout << ret << "\n";
}
