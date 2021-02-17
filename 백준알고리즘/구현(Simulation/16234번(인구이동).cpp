#include<bits/stdc++.h>
#define MAX 51
using namespace std;

int n, l, r;
int sum;
int cnt;
int ans;

int board[MAX][MAX];
bool visited[MAX][MAX];

vector<pair<int, int>> v;

bool pplFlag;
int moveY[4] = { 0, 1, 0, -1 };
int moveX[4] = { 1, 0, -1, 0 };

void changePPL()
{
	int avg = sum / cnt;
	for (int i = 0; i < v.size(); i++)
	{
		int y = v[i].first;
		int x = v[i].second;
		board[y][x] = avg;
	}
}
void BFS(int y, int x)
{
	queue<pair<int, int>> q;
	q.push({ y, x });
	v.push_back({ y, x });
	visited[y][x] = true;
	sum += board[y][x];
	cnt++;

	while (!q.empty())
	{
		int cury = q.front().first;
		int curx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = cury + moveY[i];
			int nextX = curx + moveX[i];

			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n)
				continue;
			if (visited[nextY][nextX])
				continue;

			int sub = abs(board[cury][curx] - board[nextY][nextX]);

			if (l <= sub && sub <= r)
			{
				visited[nextY][nextX] = true;
				sum += board[nextY][nextX];
				cnt++;
				q.push({ nextY, nextX });
				v.push_back({ nextY, nextX });
			}
		}
	}

	if (v.size() > 1)
	{
		changePPL();
		pplFlag = true;
	}
	
	v.clear();
	sum = 0;
	cnt = 0;
}
int main(void)
{
	cin >> n >> l >> r;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		cin >> board[i][j];

	while (1)
	{
		memset(visited, false, sizeof(visited));
		pplFlag = false;
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j])
				BFS(i, j);
		}

		if (pplFlag)
			ans++;
		else
			break;

	}
	cout << ans << "\n";
	return 0;
}
