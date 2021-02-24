#include<bits/stdc++.h>
#define MAX 30
using namespace std;

int w, h;
int board[MAX][MAX];
int dist[MAX][MAX];

int moveY[] = { -1, 1, 0, 0 };
int moveX[] = { 0, 0, -1, 1 };

void BFS(int r, int c)
{
	bool visited[MAX][MAX] = { 0, };
	queue<pair<int, int>> q;
	visited[r][c] = true;
	q.push({ r, c });

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = y + moveY[i];
			int nextX = x + moveX[i];

			if (nextY >= 0 && nextY < h && nextX >= 0 && nextX < w)
			if (!visited[nextY][nextX] && board[nextY][nextX] != -1)
			{
				visited[nextY][nextX] = true;
				q.push({ nextY, nextX });
				dist[nextY][nextX] = dist[y][x] + 1;
			}
		}
	}
}

int main(void)
{
	while (1)
	{
		cin >> w >> h;

		if (w == 0 && h == 0)
			break;
		memset(board, 0, sizeof(board));
		vector<pair<int, int>> v(1);

		char tmp;
		for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
		{
			cin >> tmp;
			if (tmp == 'o')
				v[0] = { i, j };
			if (tmp == '*')
				v.push_back({ i, j });
			if (tmp == 'x')
				board[i][j] = -1;
		}

		int result[MAX][MAX] = { 0, };
		for (int i = 0; i < v.size(); i++)
		{
			memset(dist, 0, sizeof(dist));
			BFS(v[i].first, v[i].second);

			for (int j = 0; j < v.size(); j++)
				result[i][j] = dist[v[j].first][v[j].second];
		}

		vector<int> location(v.size() - 1);
		for (int i = 0; i < v.size() - 1; i++)
			location[i] = i + 1;

		int ret = INT_MAX;
		bool flag = true;

		do
		{
			int cur = result[0][location[0]];
			if (!cur)
			{
				flag = false;
				break;
			}

			for (int i = 0; i < v.size() - 2; i++)
				cur += result[location[i]][location[i + 1]];

			if (ret > cur)
				ret = cur;

		} while (next_permutation(location.begin(), location.end()));
	
		if (!flag)
			cout << -1 << "\n";
		else
			cout << ret << "\n";
	}
	return 0;
}
