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
