#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 11;
char board[MAX][MAX];
bool visited[MAX][MAX][MAX][MAX];
int moveY[] = { -1, 1, 0, 0 };
int moveX[] = { 0, 0, -1, 1 };
queue<tuple<int, int>> red_ball, blue_ball;
int n, m;
int ry, rx, by, bx, gy, gx;

int main(void)
{
	fastio;
	cin >> n >> m;

	auto BFS = [&]() -> int
	{
		bool flag = false;
		int cnt = 0;
		visited[ry][rx][by][bx] = true;
		while (!red_ball.empty())
		{
			int qSize = red_ball.size();
			for (int t = 0; t < qSize; t++)
			{
				ry = get<0>(red_ball.front());
				rx = get<1>(red_ball.front());
				by = get<0>(blue_ball.front());
				bx = get<1>(blue_ball.front());
				red_ball.pop();
				blue_ball.pop();

				if (ry == gy && rx == gx)
				{
					flag = true;
					break;
				}

				for (int i = 0; i < 4; i++)
				{
					int nextrY = ry + moveY[i];
					int nextrX = rx + moveX[i];
					int nextbY = by + moveY[i];
					int nextbX = bx + moveX[i];

					while (1)
					{
						if (board[nextrY][nextrX] == '#')
						{
							nextrY -= moveY[i];
							nextrX -= moveX[i];
							break;
						}
						if (board[nextrY][nextrX] == 'O')
							break;
						nextrY += moveY[i];
						nextrX += moveX[i];
					}
					while (1)
					{
						if (board[nextbY][nextbX] == '#')
						{
							nextbY -= moveY[i];
							nextbX -= moveX[i];
							break;
						}
						if (board[nextbY][nextbX] == 'O')
							break;
						nextbY += moveY[i];
						nextbX += moveX[i];
					}

					if (nextbY == gy && nextbX == gx)
						continue;
					if (nextrY == nextbY && nextrX == nextbX)
					{
						if (i == 0)
							ry > by ? nextrY++ : nextbY++;
						else if (i == 1)
							ry > by ? nextbY-- : nextrY--;
						else if (i == 2)
							rx > bx ? nextrX++ : nextbX++;
						else if (i == 3)
							rx > bx ? nextbX-- : nextrX--;
					}

					if (!visited[nextrY][nextrX][nextbY][nextbX])
					{
						visited[nextrY][nextrX][nextbY][nextbX] = true;
						red_ball.push(mt(nextrY, nextrX));
						blue_ball.push(mt(nextbY, nextbX));
					}
				}
			}
			if (flag == true)
				break;
			else
				cnt++;
		}
		if (flag == false)
			cnt = -1;
		return cnt;
	};

	string input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		for (int j = 0; j < m; j++)
		{
			board[i][j] = input[j];
			if (board[i][j] == 'R')
			{
				red_ball.push(mt(i, j));
				ry = i;
				rx = j;
			}
			else if (board[i][j] == 'B')
			{
				blue_ball.push(mt(i, j));
				by = i;
				bx = j;
			}
			else if (board[i][j] == 'O')
			{
				gy = i;
				gx = j;
			}
		}	
	}
	cout << BFS() << "\n";
	return 0;
}
