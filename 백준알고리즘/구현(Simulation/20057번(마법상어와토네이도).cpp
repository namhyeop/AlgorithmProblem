#include <bits/stdc++.h>
#define MAX 510

using namespace std;

int n;
int ret;
int board[MAX][MAX];
//동서남북
int moveY[] = { 0, 0, 1, -1 };
int moveX[] = { 1, -1, 0, 0};

//동서남북 순으로 1,1,7,7,10,10,2,2,5 위 위치를 매핑
int ydy[4][10] = 
{ 
	{ -1, 1, -1, 1, -1, 1, -2, 2, 0, 0 }, 
	{ -1, 1, -1, 1, -1, 1, -2, 2, 0, 0 },
	{ 0, 0, 1, 1, 2, 2, 1, 1, 3, 2 }, 
	{ 0, 0, -1, -1, -2, -2, -1, -1, -3, -2 } 
};

int xdx[4][10] = 
{ 
	{ 0, 0, 1, 1, 2, 2, 1, 1, 3, 2 }, 
	{ 0, 0, -1, -1, -2, -2, -1, -1, -3, -2 },
	{ -1, 1, -1, 1, -1, 1, -2, 2, 0, 0 }, 
	{ -1, 1, -1, 1, -1, 1, -2, 2, 0, 0 } 
};

int arr[9] = { 1, 1, 7, 7, 10, 10, 2, 2, 5 };

int change_dir(int num)
{
	if (num == 0)
		return 3;
	if (num == 1)
		return 2;
	if (num == 2)
		return 0;
	if (num == 3)
		return 1;
}
void spread_sand(int y, int x, int dir)
{
	int nextY = y + moveY[dir];
	int nextX = x + moveX[dir];
	if (board[nextY][nextX] == 0)
		return;

	int sand = board[nextY][nextX];
	int temp = sand;
	for (int i = 0; i < 9; i++)
	{
		int toY = y + ydy[dir][i];
		int toX = x + xdx[dir][i];
		int per = arr[i];
		int plus = (temp * per) / 100;

		if (toX < 1 || toY < 1 || toX > n || toY > n)
			ret += plus;
		else
			board[toY][toX] += plus;
		sand -= plus;
	}
	int toY = y + ydy[dir][9];
	int toX = x + xdx[dir][9];
	
	if (toY < 1 || toX < 1 || toX > n || toY > n)
		ret += sand;
	else
		board[toY][toX] += sand;
	board[nextY][nextX] = 0;
}

int main(void)
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		cin >> board[i][j];

	int y = (n + 1) / 2;
	int x = (n + 1) / 2;
	int dir = 1; // 가장 처음에는 서쪽으로 이동
	int move_cnt = 1;

	while (1)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < move_cnt; j++)
			{
				spread_sand(y, x, dir);
				y += moveY[dir];
				x += moveX[dir];
			}
			dir = change_dir(dir);
		}
		move_cnt++;
		if (move_cnt == n)
		{
			for (int j = 0; j < move_cnt; j++)
			{
				spread_sand(y, x, dir);
				y += moveY[dir];
				x += moveX[dir];
			}
			break;
		}
	}
	cout << ret << "\n";

	return 0;
}
