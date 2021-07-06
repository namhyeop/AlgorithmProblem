
#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

const int MAX = 500;

int moveY[] = { 0, 1, 0, -1 };
int moveX[] = { -1, 0, 1, 0 };

double sandPercentage[5][5] = {
	{ 0, 0, 0.02, 0, 0 },
	{ 0, 0.1, 0.07, 0.01, 0 },
	{ 0.05, 0.55, 0, 0, 0 },
	{ 0, 0.1, 0.07, 0.01, 0 },
	{ 0, 0, 0.02, 0, 0 }
};

int board[MAX][MAX];
int ret;
int main(void)
{
	fastio;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		cin >> board[i][j];
	
	int y = n / 2;
	int x = n / 2;
	int cnt = 1;
	int dir = 0;

	while (1)
	{
		if (y == 0 && x == 0)
			break;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < cnt; j++)
			{
				y += moveY[dir];
				x += moveX[dir];

				auto moveSand = [&](int y, int x)
				{
					int curSand = board[y][x];
					board[y][x] = 0;

					if (curSand == 0)
						return;

					for (int i = -2; i <= 2; i++)
					for (int j = -2; j <= 2; j++)
					{
						double curSandPercentage = sandPercentage[i + 2][j + 2];

						if (curSandPercentage == 0)
							continue;

						auto alphaSand = [&](int curSand) -> int
						{
							return curSand
								- floor(curSand * 0.02) * 2
								- floor(curSand * 0.07) * 2
								- floor(curSand * 0.10) * 2
								- floor(curSand * 0.01) * 2
								- floor(curSand * 0.05);
						};

						int moveSand;
						if (curSandPercentage < 0.55)
							moveSand = floor(curSandPercentage * curSand);
						else
							moveSand = alphaSand(curSand);

						int nextY = y + i;
						int nextX = x + j;

						if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n)
							ret += moveSand;
						else
							board[nextY][nextX] += moveSand;
					}
				};
				moveSand(y, x);
				if (y == 0 && x == 0)
				{
					cout << ret << '\n';
					return 0;
				}
			}
			dir = (dir == 3) ? 0 : dir + 1;
			
			auto rotateSand = [&]()
			{
				double tmpsandPercentage[5][5];

				for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					tmpsandPercentage[i][j] = sandPercentage[i][j];

				for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					sandPercentage[5 - j -1][i] = tmpsandPercentage[i][j];
			};
			rotateSand();
		}
		cnt++;
	}
}
