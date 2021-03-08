#include<bits/stdc++.h>

using namespace std;

int moveY[5] = { 0, -1, 1, 0, 0 };
int moveX[5] = { 0, 0, 0, -1, 1 };

int board[21][21];
pair<int, int> smell[21][21];

typedef struct
{
	int isDead;
	int dir;
	int y;
	int x;
	int rank[5][4];
}Shark;

Shark shark[401];
int N, M, K;

bool valid(int y, int x)
{
	if (y < 0 || x < 0 || y >= N || x >= N)
		return false;
	return true;
}

void remove_smell()
{
	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
	{
		if (board[i][j] == 0 && smell[i][j].second > 0)
		{
			smell[i][j].second -= 1;
			if (smell[i][j].second == 0)
			{
				smell[i][j].first = 0;
			}
		}
	}
}

void moving()
{
	for (int i = 1; i <= M; i++)
	{
		int dir = shark[i].dir;
		int y = shark[i].y;
		int x = shark[i].x;

		bool isFind = false;

		if (shark[i].isDead == false)
		{
			for (int j = 0; j < 4; j++)
			{
				int f_dir = shark[i].rank[dir][j];
				int ty = y + moveY[f_dir];
				int tx = x + moveX[f_dir];

				if (valid(ty, tx) && smell[ty][tx].second == 0)
				{
					if (board[ty][tx] != 0)
					{
						if (board[ty][tx] > i)
						{
							board[y][x] = 0;
							board[ty][tx] = i;
							shark[i].y = ty;
							shark[i].x = tx;
							shark[board[ty][tx]].isDead = true;
							isFind = true;
							shark[i].dir = f_dir;
						}
						else if (board[ty][tx] < i)
						{
							board[y][x] = 0;
							shark[i].isDead = true;
							isFind = true;
							break;
						}
					}
					else
					{
						board[y][x] = 0;
						board[ty][tx] = i;
						shark[i].y = ty;
						shark[i].x = tx;
						isFind = true;
						shark[i].dir = f_dir;
					}

					break;
				}
			}

			if (!isFind)
			{
				for (int j = 0; j < 4; j++)
				{
					int f_dir = shark[i].rank[dir][j];
					int ty = y + moveY[f_dir];
					int tx = x + moveX[f_dir];

					if (valid(ty, tx) && smell[ty][tx].first == i)
					{
						board[y][x] = 0;
						board[ty][tx] = i;
						shark[i].y = ty;
						shark[i].x = tx;

						shark[i].dir = f_dir;
						break;
					}
				}
			}
		}
	}

	for (int i = 1; i <= M; i++)
	{
		if (shark[i].isDead == false)
		{
			int y = shark[i].y;
			int x = shark[i].x;

			smell[y][x].first = i;
			smell[y][x].second = K;
		}
	}
}

int simulation()
{
	int time = 0;

	while (time <= 1000)
	{
		bool flag = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (board[i][j] != 0 && board[i][j] != 1)
				{
					flag = true;
					break;
				}
			}
		}
		if (!flag)
			break;

		moving();
		remove_smell();
		time += 1;
	}

	if (time > 1000)
		return -1;

	return time;
}

int main()
{
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			if (board[i][j] != 0)
			{
				shark[board[i][j]].y = i;
				shark[board[i][j]].x = j;
			}
		}
	}

	for (int i = 1; i <= M; i++)
	{
		int input;
		cin >> input;
		shark[i].dir = input;
	}

	for (int i = 1; i <= M; i++)
	{
		for (int k = 1; k <= 4; k++)
		{
			for (int j = 0; j < 4; j++)
			{
				cin >> shark[i].rank[k][j];
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] != 0)
				smell[i][j] = make_pair(board[i][j], K);
		}
	}

	int res = simulation();
	cout << res;

	return 0;
}
