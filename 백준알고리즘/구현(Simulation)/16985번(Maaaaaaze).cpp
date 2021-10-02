#include<bits/stdc++.h>
#define n 5
using namespace std;

int moveY[] = { 0, 0, 0, 0, 1, -1 };
int moveX[] = { 0, 0, 1, -1, 0, 0 };
int moveZ[] = { 1, -1, 0, 0, 0, 0 };
int ret;

void rotate(vector<vector<int>> &board)
{
	vector<vector<int>> tmp(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		tmp[i][j] = board[i][j];
	}

	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		board[i][j] = tmp[n - 1 - j][i];
}

int BFS(vector<vector<vector<int>>> &board)
{
	if (board[0][0][0] == 0)
		return -1;
	int dist[n][n][n];
	memset(dist, -1, sizeof(dist));
	queue<pair<int, pair<int, int>>> q;

	q.push({ 0, { 0, 0 } });
	dist[0][0][0] = 0;

	while (!q.empty())
	{
		int z = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();

		for (int d = 0; d < 6; d++)
		{
			int nextY = y + moveY[d];
			int nextX = x + moveX[d];
			int nextZ = z + moveZ[d];

			if (0 <= nextY && nextY < n && 0 <= nextX && nextX < n && 0 <= nextZ && nextZ < n)
			if (board[nextZ][nextY][nextX] == 1 && dist[nextZ][nextY][nextX] == -1)
			{
				dist[nextZ][nextY][nextX] = dist[z][y][x] + 1;
				q.push({ nextZ, { nextY, nextX } });
			}
		}
	}
	return dist[n - 1][n - 1][n - 1];
}

void solve(int begin, vector<vector<vector<int>>> &board)
{
	if (begin == n)
		return;

	for (int i = 0; i < 4; i++)
	{
		int cand = BFS(board);
		if (cand != -1)
		{
			if (ret == -1 || ret > cand)
				ret = cand;
		}
		solve(begin + 1, board);
		rotate(board[begin]);
	}
}
int main(void)
{
	vector<vector<vector<int>>> first(n);

	for (int i = 0; i < n; i++)
	{
		first[i].resize(n, vector<int>(n));
		for (int j = 0; j < n; j++)
		for (int k = 0; k < n; k++)
			cin >> first[i][j][k];
	}

	vector<int> order;
	for (int i = 0; i < n; i++)
		order.push_back(i);

	int ans = -1;
	ret = -1;

	do
	{
		vector<vector<vector<int>>> board(n);
		for (int i = 0; i < n; i++)
			board[order[i]] = first[i];

		solve(0, board);

		if (ret != -1)
		{
			if (ans == -1 || ans > ret)
				ans = ret;
		}
	} while (next_permutation(order.begin(), order.end()));
	
	cout << ans << "\n";
	return 0;
}

