#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;
const int MAX = 501;
int cache[MAX][MAX];
int board[MAX][MAX];
bool visited[MAX][MAX];
int m, n;

int search(int y, int x)
{
	if (y < 0 || x < 0 || y >= m || x >= n)
		return 0;

	if (m - 1 == y && n - 1 == x)
		return 1;

	if (visited[y][x])
		return cache[y][x];

	int &ret = cache[y][x];

	visited[y][x] = true;

	if (board[y][x] > board[y + 1][x] && y + 1 >= 0)
		ret += search(y + 1, x);
	if (board[y][x] > board[y - 1][x] && y - 1 >= 0)
		ret += search(y - 1, x);
	if (board[y][x] > board[y][x + 1] && x + 1 >= 0)
		ret += search(y, x + 1);
	if (board[y][x] > board[y][x - 1] && x - 1 >= 0)
		ret += search(y, x - 1);

	return ret;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> n;

	for (int i = 0; i < m; i++)
	for (int j = 0; j < n; j++)
		cin >> board[i][j];

	cout << search(0, 0) << "\n";
}

/*
#include<bits/stdc++.h>

using namespace std;

int n, m;
int arr[501][501];
int cache[501][501];
int moveY[4] = { -1, 1, 0, 0 };
int moveX[4] = { 0, 0, -1, 1 };

int search(int y, int x)
{
	int k;

	if (y == n && x == m)
		return 1;
	else if (cache[y][x] == -1)
	{
		cache[y][x] = 0;
		for (int k = 0; k < 4; k++)
		{
			int nextY = y + moveY[k];
			int nextX = x + moveX[k];
			if (nextY > 0 && nextY <= n && nextX > 0 && nextX <= m && arr[y][x] > arr[nextY][nextX])
			{
				cache[y][x] += search(nextY, nextX);
				/*경로 탐색 순서 확인
				for (int i = 1; i <= n; i++)
				{
					for (int j = 1; j <= m; j++)
					{
						printf("%2d ", cache[i][j]);
					}
					cout << "\n";
				}
				cout << "\n";
				*/
			}
		}
	}
	return cache[y][x];
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
	for (int j = 0; j <= m; j++)
	{
		cache[i][j] = -1;
		arr[i][j] = 100001;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
	}

	cout << search(1,1) << "\n";
}
*/
