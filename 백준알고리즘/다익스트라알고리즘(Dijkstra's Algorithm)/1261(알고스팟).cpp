//다이젝스트라 풀이
#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 101;
const int INF = 987654321;
int n, m;
int board[MAX][MAX];
int dist[MAX][MAX];
int moveY[] = { 1, -1, 0, 0 };
int moveX[] = { 0, 0, 1, -1 };
queue<pair<int, int>> q;

int main(void)
{
	fastio;

	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < m; j++)
		{
			board[i][j] = input[j] - '0';
		}
	}

	fill(&dist[0][0], &dist[MAX - 1][MAX], INF);
	dist[0][0] = 0;
	q.push({ 0, 0 });

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = y + moveY[i];
			int nextX = x + moveX[i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) continue;

			if (board[nextY][nextX] == 1)
			{
				if (dist[nextY][nextX] > dist[y][x] + 1)
				{
					dist[nextY][nextX] = dist[y][x] + 1;
					q.push({ nextY, nextX });
				}
			}
			else if (board[nextY][nextX] == 0)
			{
				if (dist[nextY][nextX] > dist[y][x])
				{
					dist[nextY][nextX] = dist[y][x];
					q.push({ nextY, nextX });
				}
			}

		}
	}
	cout << dist[n - 1][m - 1] << "\n";
	return 0;
}

