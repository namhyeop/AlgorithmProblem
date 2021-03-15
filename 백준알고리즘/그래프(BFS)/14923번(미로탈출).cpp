#include<bits/stdc++.h>
#define MAX 1001
using namespace std;

int moveY[] = { 1, -1, 0, 0 };
int moveX[] = { 0, 0, -1, 1 };

int n, m;
int ret;
pair<int, int> start, finish;
int board[MAX][MAX];
int cache[MAX][MAX][2];

int BFS()
{
	queue<pair<pair<int, int>, int>> q;
	q.push({ start, 1 });
	cache[start.first][start.second][1] = 1;

	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int block = q.front().second;
		q.pop();

		if (y == finish.first && x == finish.second)
			return cache[y][x][block] - 1;

		for (int i = 0; i < 4; i++)
		{
			int nextY = y + moveY[i];
			int nextX = x + moveX[i];

			if (1 <= nextY && nextY <= n && 1 <= nextX && nextX <= m)
			{
				if (board[nextY][nextX] == 1 && block && cache[nextY][nextX][block - 1] == 0)
				{
					cache[nextY][nextX][block - 1] = cache[y][x][block] + 1;
					q.push({ { nextY, nextX }, block - 1 });
				}
				else if (board[nextY][nextX] == 0 && cache[nextY][nextX][block] == 0)
				{
					cache[nextY][nextX][block] = cache[y][x][block] + 1;
					q.push({ { nextY, nextX }, block });
				}
			}
		}
	}
	return -1;
}

int main(void)
{
	cin >> n >> m;

	cin >> start.first >> start.second;
	cin >> finish.first >> finish.second;

	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
		cin >> board[i][j];

	ret = BFS();

	cout << ret << "\n";

	return 0;
}
