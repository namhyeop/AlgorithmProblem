#include<bits/stdc++.h>
#define MAX 55
using namespace std;

int n, m;
int board[MAX][MAX];
bool visited[MAX][MAX];
int ret = INT_MIN;
int moveY[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int moveX[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void BFS(int i, int j)
{
	memset(visited, false, sizeof(visited));
	queue<pair<pair<int, int>, int>> qs;
	qs.push({{ i, j }, 1});
	visited[i][j] = true;

	int flag = false;
	while (!qs.empty())
	{
		int y = qs.front().first.first;
		int x = qs.front().first.second;
		int cnt = qs.front().second;
		qs.pop();
		
		for (int i = 0; i < 8; i++)
		{
			int nextY = y + moveY[i];
			int nextX = x + moveX[i];

			if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < m)
			{
				if (board[nextY][nextX] == 1)
				{
					flag = true;
					break;
				}
				if (board[nextY][nextX] == 0 && !visited[nextY][nextX])
				{
					qs.push({ { nextY, nextX }, cnt + 1 });
					visited[nextY][nextX] = true;
				}
			}
		}
		ret = max(ret, cnt);
		if (flag == true)
			break;
	}
}

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
		cin >> board[i][j];

	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	{
		if (board[i][j] == 0)
		BFS(i, j);
	}
	cout << ret << "\n";

	return 0;
}
