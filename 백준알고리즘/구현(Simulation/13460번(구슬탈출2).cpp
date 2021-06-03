#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 10 + 1;
int n, m;
char board[MAX][MAX];
bool visited[MAX][MAX][MAX][MAX];
int ry_ball, rx_ball, by_ball, bx_ball, goal_y, goal_x;
int moveY[] = { -1, 1, 0, 0 };
int moveX[] = { 0, 0, -1, 1 };
queue<pair<int, int>> Q_red, Q_blue;

int main(void)
{
	fastio;
	string input;
	cin >> n >> m;

	auto BFS = [&]() -> int
	{
		int cnt = 0;
		while (!Q_red.empty())
		{
			int qSize = Q_red.size();
			while (qSize--)
			{
				int rY = Q_red.front().first;
				int rX = Q_red.front().second;
				int bY = Q_blue.front().first;
				int bX = Q_blue.front().second;
				//cout << rY << " " << rX <<"\n";
				Q_red.pop();
				Q_blue.pop();

				if (cnt > 10)
					return -1;

				if (rY == goal_y && rX == goal_x)
				{
					return cnt;
				}

				if(bY == goal_y && bX == goal_x)
					continue;

				for (int i = 0; i < 4; i++)
				{
					int nextry = rY + moveY[i];
					int nextrx = rX + moveX[i];
					int nextby = bY + moveY[i];
					int nextbx = bX + moveX[i];

					while (1)
					{
						if (board[nextry][nextrx] == '#')
						{
							nextry -= moveY[i];
							nextrx -= moveX[i];
							break;
						}
						if (board[nextry][nextrx] == 'O')
							break;
						nextry += moveY[i];
						nextrx += moveX[i];
					}

					while (1)
					{
						if (board[nextby][nextbx] == '#')
						{
							nextby -= moveY[i];
							nextbx -= moveX[i];
							break;
						}
						if (board[nextby][nextbx] == 'O')
							break;
						nextby += moveY[i];
						nextbx += moveX[i];
					}

					if (nextby == goal_y && nextbx == goal_x)
						continue;

					if (nextry == nextby && nextrx == nextbx)
					{
						switch (i)
						{
						case 0:
							if (rY > bY)
								nextry++;
							else
								nextby++;
							break;
						case 1:
							if (rY > bY)
								nextby--;
							else
								nextry--;
							break;
						case 2:
							if (rX > bX)
								nextrx++;
							else
								nextbx++;
							break;
						case 3:
							if (rX > bX)
								nextbx--;
							else
								nextrx--;
							break;
						}
					}
					if (!visited[nextry][nextrx][nextby][nextbx])
					{
						visited[nextry][nextrx][nextby][nextbx] = true;
						Q_red.push({ nextry, nextrx });
						Q_blue.push({ nextby, nextbx });
					}
				}
			}
			cnt++;
		}
		return -1;
	};

	for (int i = 0; i < n; i++)
	{
		cin >> input;
		for (int j = 0; j < m; j++)
		{
			board[i][j] = input[j];
			if (board[i][j] == 'R')
			{
				ry_ball = i;
				rx_ball = j;
				Q_red.push({ i, j });
			}
			else if (board[i][j] == 'B')
			{
				by_ball = i;
				bx_ball = j;
				Q_blue.push({ i, j });
			}
			else if (board[i][j] == 'O')
			{
				goal_y = i;
				goal_x = j;
			}
		}
	}

	visited[ry_ball][rx_ball][by_ball][bx_ball] = true;

	cout << BFS();
}

/*#include<bits/stdc++.h>
#define MAX 11
using namespace std;

int n, m;
int ry, rx, by, bx;
int hy, hx;
int flag;
int board[MAX][MAX];
int visited[MAX][MAX][MAX][MAX];
queue<pair<int, int>> redball;
queue<pair<int, int>> blueball;

int moveY[] = { -1, 1, 0, 0 };
int moveX[] = { 0, 0, -1, 1 };

int main(void)
{
	string str;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			board[i][j] = str[j];
			if (board[i][j] == 'R')
			{
				redball.push({ i, j });
				ry = i;
				rx = j;
			}
			if (board[i][j] == 'B')
			{
				blueball.push({ i, j });
				by = i;
				bx = j;
			}
			if (board[i][j] == 'O')
			{
				hy = i;
				hx = j;
			}
		}
	}

	visited[ry][rx][by][bx] = true;
	int ret = 0;
	while (!redball.empty())
	{
		int qsize = redball.size();
		while (qsize--)
		{
			ry = redball.front().first;
			rx = redball.front().second;
			by = blueball.front().first;
			bx = blueball.front().second;
			redball.pop();
			blueball.pop();

			if (ret > 10)
				break;
			if (ry == hy && rx == hx)
			{
				flag = true;
				break;
			}

			for (int i = 0; i < 4; i++)
			{
				int nextRy = ry + moveY[i];
				int nextRx = rx + moveX[i];
				int nextBy = by + moveY[i];
				int nextBx = bx + moveX[i];

				while (1)
				{
					if (board[nextRy][nextRx] == '#')
					{
						nextRy -= moveY[i];
						nextRx -= moveX[i];
						break;
					}
					if (board[nextRy][nextRx] == 'O')
						break;
					nextRy += moveY[i];
					nextRx += moveX[i];
				}
				while (1)
				{
					if (board[nextBy][nextBx] == '#')
					{
						nextBy -= moveY[i];
						nextBx -= moveX[i];
						break;
					}
					if (board[nextBy][nextBx] == 'O')
						break;
					nextBy += moveY[i];
					nextBx += moveX[i];
				}

				if (nextBy == hy && nextBx == hx)
					continue;

				if (nextRy == nextBy && nextRx == nextBx)
				{
					switch (i)
					{
					case 0:
						ry > by ? nextRy++ : nextBy++;
						break;
					case 1:
						ry < by ? nextRy-- : nextBy--;
						break;
					case 2:
						rx > bx ? nextRx++ : nextBx++;
						break;
					case 3:
						rx < bx ? nextRx-- : nextBx--;
						break;
					}
				}
				if (visited[nextRy][nextRx][nextBy][nextBx])
					continue;
				redball.push({ nextRy, nextRx });
				blueball.push({ nextBy, nextBx });
				visited[nextRy][nextRx][nextBy][nextBx] = true;
			}
		}
		if (flag)
			break;
		else
			ret++;
	}
	if (flag)
		cout << ret << "\n";
	else
		cout << -1;

	return 0;
}*/
