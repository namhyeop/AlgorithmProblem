#include<bits/stdc++.h>
#define MAX 20
using namespace std;

int board[MAX][MAX];
int moveY[] = { -1, 0, 1, 0 };
int moveX[] = { 0, -1, 0, 1 };
bool visited[MAX][MAX];

typedef struct
{
	int time, y, x;
}pass;

bool operator <(const pass &p1, const pass &p2)
{
	if (p1.time > p2.time)
		return true;
	else if (p1.time == p2.time && p1.y > p2.y)
		return true;
	else if (p1.time == p2.time && p1.y == p2.y && p1.x > p2.x)
		return true;
	return false;
}

int main(void)
{
	int N;
	cin >> N;

	pair<int, int> start;
	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
	{
		cin >> board[i][j];
		if (board[i][j] == 9)
		{
			start = { i, j };
			board[i][j] = 0;
		}
	}


	queue<pair<pair<int, int>, int>> q;
	q.push({ { start }, 2 });

	int duration = 0;
	int cnt = 0;

	while (!q.empty())
	{
		int y = q.front().first.first;;
		int x = q.front().first.second;
		int size = q.front().second;
		q.pop();

		memset(visited, false, sizeof(visited));
		priority_queue<pass> temp;
		temp.push({ 0, y, x });
		visited[y][x] = true;

		while (!temp.empty())
		{
			int iter = temp.size();
			priority_queue <pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
			for (int j = 0; j < iter; j++)
			{
				int curY = temp.top().y;
				int curX = temp.top().x;
				int curTime = temp.top().time;
				temp.pop();

				for (int i = 0; i < 4; i++)
				{
					int nextY = curY + moveY[i];
					int nextX = curX + moveX[i];

					if (0 <= nextY && nextY < N && 0 <= nextX && nextX < N)
					if (!visited[nextY][nextX])
					{
						if (board[nextY][nextX] <= size)
						{
							temp.push({ curTime + 1, nextY, nextX });
							visited[nextY][nextX] = true;
							if (1 <= board[nextY][nextX] && board[nextY][nextX] < size)
								pq.push({ { nextY, nextX }, curTime + 1 });
						}
					}
				}
			}
			if (!pq.empty())
			{
				cnt++;
				if (cnt == size)
				{
					q.push({ { pq.top().first }, size + 1 });
					cnt = 0;
				}
				else
					q.push({ { pq.top().first }, size });

				board[pq.top().first.first][pq.top().first.second] = 0;
				duration += pq.top().second;
				break;
			}

		}
	}
	cout << duration << "\n";
	return 0;
}
