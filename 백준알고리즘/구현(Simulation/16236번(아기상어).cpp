#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

const int MAX = 21;
int board[MAX][MAX];
bool visited[MAX][MAX];

typedef struct
{
	int time, y, x;
}pass;

bool operator <(const pass &a, const pass &b)
{
	if (a.time != b.time)
		return a.time > b.time;
	else if (a.y != b.y)
		return a.y > b.y;
	else if (a.x != b.x)
		return a.x > b.x;
	return false;
}

int n;
pair<int, int> st_shark;
int moveY[] = { -1, 0, 1, 0 };
int moveX[] = { 0, -1, 0, 1 };

int main(void)
{
	fastio;
	cin >> n;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		cin >> board[i][j];
		if (board[i][j] == 9)
		{
			st_shark = { i, j };
			board[i][j] = 0;
		}
	}

	auto BFS = [&]() -> int
	{
		int ret_cnt = 0;
		int eated_cnt = 0;

		queue<tuple<int, int, int>> q;
		q.push(mtt(st_shark.first, st_shark.second, 2));

		while (!q.empty())
		{
			int y = get<0>(q.front());
			int x = get<1>(q.front());
			int size = get<2>(q.front());
			q.pop();

			memset(visited, false, sizeof(visited));
			priority_queue<pass> tmp;
			tmp.push({ 0, y, x });
			visited[y][x] = true;

			while (!tmp.empty())
			{
				int tmpSize = tmp.size();
				priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
				for (int i = 0; i < tmpSize; i++)
				{
					int curY = tmp.top().y;
					int curX = tmp.top().x;
					int curTime = tmp.top().time;
					tmp.pop();
					for (int i = 0; i < 4; i++)
					{
						int nextY = curY + moveY[i];
						int nextX = curX + moveX[i];

						if (0 <= nextY && nextY < n && 0 <= nextX && nextX < n)
						if (!visited[nextY][nextX])
						if (board[nextY][nextX] <= size)
						{
							tmp.push({ curTime + 1, nextY, nextX });
							visited[nextY][nextX] = true;
							if (1 <= board[nextY][nextX] && board[nextY][nextX] < size)
								pq.push({ { nextY, nextX }, curTime + 1 });
						}
					}
				}
				if (!pq.empty())
				{
					eated_cnt++;
					if (eated_cnt == size)
					{
						q.push(mtt(pq.top().first.first, pq.top().first.second, size + 1));
						eated_cnt = 0;
					}
					else
						q.push(mtt(pq.top().first.first, pq.top().first.second, size));
					board[pq.top().first.first][pq.top().first.second] = 0;
					ret_cnt += pq.top().second;
					break;
				}
			}
		}
		return ret_cnt;
	};
	cout << BFS() << "\n";
	return 0;
}

/*
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
*/
