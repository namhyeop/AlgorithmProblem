#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 4;
typedef struct
{
	int f_num;
	int dir;
	int y, x;
}fish;

fish fishes[MAX * MAX + 1];
int board[MAX][MAX];
fish shark;
int ret;
int moveY[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int moveX[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };

int main(void)
{
	fastio;

	for (int y = 0; y < MAX; y++)
	for (int x = 0; x < MAX; x++)
	{
		int num, dir;
		cin >> num >> dir;
		if (y == 0 && x == 0)
		{
			shark = { num, dir, y, x };
			continue;
		}
		fishes[num] = { num, dir, y, x };
		board[y][x] = num;
	}

	function<void(fish[], int[][MAX], fish, int)> DFS = [&](fish fishes[MAX * MAX + 1], int board[MAX][MAX], fish shark, int sum)
	{
		ret = max(ret, sum);
	
		for (int i = 1; i <= MAX * MAX; i++)
		{
			int y = fishes[i].y;
			int x = fishes[i].x;
			int dir = fishes[i].dir;

			if (dir == 0)
				continue;

			int nextY, nextX, changeCnt;
			for (changeCnt = 0; changeCnt < 8; changeCnt++)
			{
				nextY = y + moveY[dir];
				nextX = x + moveX[dir];
				if (nextY < 0 || nextY >= MAX || nextX < 0 || nextX >= MAX)
				{
					fishes[i].dir = (dir == 8) ? 1 : dir + 1;
					dir = fishes[i].dir;
					continue;
				}
				if (nextY == shark.y && nextX == shark.x)
				{
					fishes[i].dir = (dir == 8) ? 1 : dir + 1;
					dir = fishes[i].dir;
					continue;
				}
				break;
			}

			if (changeCnt == 8)
				continue;

			int nextIdx = board[nextY][nextX];
			
			if (nextIdx)
			{
				fishes[nextIdx].y = y;
				fishes[nextIdx].x = x;
				board[y][x] = nextIdx;
			}
			else
			{
				board[y][x] = 0;
			}
			fishes[i].y = nextY;
			fishes[i].x = nextX;
			board[nextY][nextX] = i;
		}

		int y = shark.y;
		int x = shark.x;
		int dir = shark.dir;

		for (int i = 1; i <= 3; i++)
		{
			fish tmpfishes[MAX * MAX + 1];
			memcpy(tmpfishes, fishes, sizeof(tmpfishes));
			int tmpboard[MAX][MAX];
			memcpy(tmpboard, board, sizeof(tmpboard));

			int nextY = y + moveY[dir] * i;
			int nextX = x + moveX[dir] * i;

			if (nextY < 0 || nextY >= MAX || nextX < 0 || nextX >= MAX)
				continue;
			
			if (tmpboard[nextY][nextX] == 0)
				continue;

			shark.y = nextY;
			shark.x = nextX;

			int score = tmpboard[nextY][nextX];
			tmpboard[nextY][nextX] = 0;

			shark.dir = tmpfishes[score].dir;
			tmpfishes[score].dir = 0;
			DFS(tmpfishes, tmpboard, shark, sum + score);
		}
	};

	DFS(fishes, board, shark, shark.f_num);

	cout << ret << "\n";
}
/*
#include<bits/stdc++.h>
#define MAX 4
using namespace std;

typedef struct
{
	int idx;
	int dir;
	int y, x;
}fish;

int moveY[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };//
int moveX[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int ret;
fish shark;
fish fishes[MAX * MAX + 1];
int fishTank[MAX][MAX];

void func(fish fishes[MAX * MAX + 1], int fishTank[MAX][MAX], fish shark, int sum)
{
	ret = max(ret, sum);

	for (int i = 1; i <= MAX * MAX; i++)
	{
		int y = fishes[i].y;
		int x = fishes[i].x;
		int dir = fishes[i].dir;

		if (dir == 0)
			continue;
			
		int nextY = y + moveY[dir];
		int nextX = x + moveX[dir];

		int dirChangeCnt = 0;

		for (dirChangeCnt = 0; dirChangeCnt < 8; dirChangeCnt++)
		{
			nextY = y + moveY[dir];
			nextX = x + moveX[dir];

			if (nextY < 0 || nextY >= MAX || nextX < 0 || nextX >= MAX)
			{
				fishes[i].dir = (dir == 8) ? 1 : dir + 1;
				dir = fishes[i].dir;
				continue;
			}

			if (nextY == shark.y && nextX == shark.x)
			{
				fishes[i].dir = (dir == 8) ? 1 : dir + 1;
				dir = fishes[i].dir;
				continue;
			}
			break;
		}

		if (dirChangeCnt == 8)
			continue;

		int nextIdx = fishTank[nextY][nextX];

		if (nextIdx)
		{
			fishes[nextIdx].y = y;
			fishes[nextIdx].x = x;
			fishTank[y][x] = nextIdx;
		}
		else
		{
			fishTank[y][x] = 0;
		}

		fishes[i].y = nextY;
		fishes[i].x = nextX;
		fishTank[nextY][nextX] = i;
	}

	int y = shark.y;
	int x = shark.x;
	int dir = shark.dir;

	for (int i = 1; i <= 3; i++)
	{
		fish tempFishes[MAX * MAX + 1];
		for (int idx = 0; idx < MAX * MAX + 1; idx++)
			tempFishes[idx] = fishes[idx];

		int tempFishTank[MAX][MAX];

		for (int j = 0; j < MAX; j++)
		{
			for (int k = 0; k < MAX; k++)
			{
				tempFishTank[j][k] = fishTank[j][k];
			}
		}

		int nextY = y + moveY[dir] * i;
		int nextX = x + moveX[dir] * i;

		if (nextY < 0 || nextY >= MAX || nextX < 0 || nextX >= MAX)
			continue;

		if (tempFishTank[nextY][nextX] == 0)
			continue;

		shark.y = nextY;
		shark.x = nextX;

		int score = tempFishTank[nextY][nextX];
		tempFishTank[nextY][nextX] = 0;

		shark.dir = tempFishes[score].dir;
		tempFishes[score].dir = 0;
		func(tempFishes, tempFishTank, shark, sum + score);
	}
}
int main(void)
{
	for (int y = 0; y < MAX; y++)
	{
		for (int x = 0; x < MAX; x++)
		{
			int idx, dir;
			cin >> idx >> dir;

			if (y == 0 && x == 0)
			{
				shark = { idx, dir, y, x };
				continue;
			}
			fishes[idx] = { idx, dir, y, x };
			fishTank[y][x] = idx;
		}
	}

	func(fishes, fishTank, shark, shark.idx);

	cout << ret << "\n";

	return 0;
}
*/
