#include<bits/stdc++.h>
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
}
