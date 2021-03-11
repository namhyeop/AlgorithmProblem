#include<bits/stdc++.h>
#define MAX 16

using namespace std;

int moveY[] = { 0, 1, 1 };
int moveX[] = { 1, 0, 1 };

int n;
int ret;
int board[MAX][MAX];

void func(int y, int x, int pipe)
{
	if (y == n - 1 && x == n - 1)
	{
		ret++;
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		if ((i == 0 && pipe == 1) || (i == 1 && pipe == 0))
			continue;

		int nextY = y + moveY[i];
		int nextX = x + moveX[i];
		if (nextY >= n || nextX >= n || board[nextY][nextX] == 1)
			continue;
		if (i == 2 && (board[y][x + 1] == 1 || board[y + 1][x] == 1))
			continue;

		func(nextY, nextX, i);
	}
}

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	}

	func(0, 1, 0);

	cout << ret << "\n";

	return 0;
}
