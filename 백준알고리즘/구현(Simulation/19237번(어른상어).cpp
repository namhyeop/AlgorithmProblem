#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

int moveY[] = { 0, -1, 1, 0, 0 };
int moveX[] = { 0, 0, 0, -1, 1 };

int board[21][21];
pair<int, int> smell[21][21]; //냄새의 주인 상어번호, 남아있는 횟수

typedef struct
{
	int isDead;
	int dir;
	int y;
	int x;
	int rank[5][4];
}Shark;

Shark shark[401];
int n, m, k;

bool valid(int y, int x)
{
	if (y < 0 || x < 0 || y >= n || x >= n)
		return false;
	return true;
}

int main(void)
{
	fastio;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] != 0)
			{
				shark[board[i][j]].y = i;
				shark[board[i][j]].x = j;
			}
		}
	}

	for (int i = 1; i <= m; i++)
	{
		int input;
		cin >> input;
		shark[i].dir = input;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int k = 1; k <= 4; k++)
		{
			for (int j = 0; j < 4; j++)
				cin >> shark[i].rank[k][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] != 0)
				smell[i][j] = make_pair(board[i][j], k);
		}
	}
	auto simulation = [&]() -> int
	{
		int time = 0;
		while (time <= 1000)
		{
			bool flag = false;
			for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] != 0 && board[i][j] != 1)
				{
					flag = true;
					break;
				}
			}
			if (!flag)
				break;

			auto moving = [&]()
			{
				for (int i = 1; i <= m; i++)
				{
					int dir = shark[i].dir;
					int y = shark[i].y;
					int x = shark[i].x;

					bool isFind = false;
					if (shark[i].isDead == false)
					{
						for (int j = 0; j < 4; j++)
						{
							int f_dir = shark[i].rank[dir][j]; // dir일 때 상어의 탐색 우선수위
							int ty = y + moveY[f_dir];
							int tx = x + moveX[f_dir];

							if (valid(ty, tx) && smell[ty][tx].second == 0)//범위가 유효하고 다음 상어가 갈 위치에 냄새가 없다면
							{
								if (board[ty][tx] != 0) //이동하는 칸이 상어인경우
								{
									if (board[ty][tx] > i) // 기존에 있는 칸의 상어가 이동할려는 상어보다 큰 경우, 번호가 작으면 남아있고 큰 경우 쫓김을 당한다.
									{
										board[y][x] = 0;
										shark[board[ty][tx]].isDead = true;
										board[ty][tx] = i;
										shark[i].y = ty;
										shark[i].x = tx;
										isFind = true;
										shark[i].dir = f_dir;
									}
									else if (board[ty][tx] < i)
									{
										board[y][x] = 0;
										shark[i].isDead = true;
										isFind = true;
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
							for (int j = 0; j < 4; j++) //근처가 전부 냄새가 있어서 자기의 냄새로 가야할 경우
							{
								int f_dir = shark[i].rank[dir][j];//자기 냄새의 우선순위에 맞게
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
				for (int i = 1; i <= m; i++)
				{
					if (shark[i].isDead == false)
					{
						int y = shark[i].y;
						int x = shark[i].x;
						smell[y][x].first = i;
						smell[y][x].second = k;
					}
				}
			};

			auto remove_smell = [&]()
			{
				for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
				{
					if (board[i][j] == 0 && smell[i][j].second > 0) //냄새이면서 냄새 횟수가 남아있을 경우
					{
						smell[i][j].second -= 1;
						if (smell[i][j].second == 0)
							smell[i][j].first = 0;
					}
				}
			};
			moving();
			remove_smell();
			time += 1;
		}
		if (time > 1000)
			return -1;
		return time;
	};
	cout << simulation();
	
	return 0;
}

/*
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
*/
