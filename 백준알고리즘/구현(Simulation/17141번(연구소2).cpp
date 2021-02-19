#include<bits/stdc++.h>

#define MAX 51
using namespace std;

int N, M;
int board[MAX][MAX];
bool visited[MAX][MAX];
int ret = INT_MAX;
int num;
int cnt;
vector<pair<int, int>> virus;
vector<pair<int, int>> pick;
vector<bool> check;

int moveY[] = { 1, -1, 0, 0 };
int moveX[] = { 0, 0, -1,1};

class point
{
public:
	int y, x, dist;
	
	
	point(int y, int x, int dist)
	{
		this->y = y;
		this->x = x;
		this->dist = dist;
	}
};

int bfs()
{
	queue<point> q;
	int tmpboard[MAX][MAX];
	int ret = INT_MIN;
	int temp = cnt;

	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
	{
		tmpboard[i][j] = board[i][j];
	}

	for (int i = 0; i < pick.size(); i++)
	{
		q.push({ pick[i].first, pick[i].second, 0 });
		visited[pick[i].first][pick[i].second] = true;
	}

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int k = q.front().dist;
		q.pop();
		
		temp--;

		ret = max(ret, k);

		for (int i = 0; i < 4; i++)
		{
			int nextY = y + moveY[i];
			int nextX = x + moveX[i];

			if (0 <= nextY && nextY < N && 0 <= nextX && nextX < N)
			if (!visited[nextY][nextX] && tmpboard[nextY][nextX] == 0)
			{
				tmpboard[nextY][nextX] = k + 1;
				q.push(point(nextY, nextX, k + 1));
				visited[nextY][nextX] = true;
			}
		}
	}

	if (temp == 0) 
		return ret;
	else
		return -1; 
}

void backtrack(int cur, int cnt)
{
	if (cnt == M)
	{
		memset(visited, false, sizeof(visited));
		int ok = bfs();
		if (ok != -1)
		{
			ret = min(ret, ok);
		}
		return;
	}

	for (int i = cur; i < virus.size(); i++)
	{
		if (check[i])
			continue;

		pick.push_back(virus[i]);
		check[i] = true;
		backtrack(i + 1, cnt + 1);
		pick.pop_back();
		check[i] = false;
	}
}
int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
	{
		cin >> num;
		if (num == 0)
		{
			board[i][j] = 0;
			cnt++;
		}
		else if (num == 1)
		{
			board[i][j] = -1;
		}
		else
		{
			board[i][j] = 0;
			virus.push_back({ i, j });
			check.push_back(false);
			cnt++;
		}
	}

	backtrack(0, 0);

	if (ret == INT_MAX)
		cout << -1;
	else
		cout << ret;

	return 0;
}
