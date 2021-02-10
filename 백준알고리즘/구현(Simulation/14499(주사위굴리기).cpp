#include<bits/stdc++.h>
#define MAX 22
using namespace std;

int n, m;
int x, y, k;
int board[MAX][MAX];
int dice[6];
vector<int> cmd;

bool valid(int y, int  x)
{
	return  0 <= y && y < n && 0 <= x && x < m;
}

bool operate(int num)
{
	if (num == 1) // 동
	{
		x += 1;
		if (valid(y, x))
		{
			int tmpdice[6];
			for (int i = 0; i < 6; i++)
				tmpdice[i] = dice[i];
			dice[0] = tmpdice[3];
			dice[2] = tmpdice[0];
			dice[5] = tmpdice[2];
			dice[3] = tmpdice[5];
		}
		else
		{
			x -= 1;
			return false;
		}
	}
	else if (num == 2)// 서
	{
		x -= 1;
		if (valid(y, x))
		{
			int tmpdice[6];
			for (int i = 0; i < 6; i++)
				tmpdice[i] = dice[i];
			dice[3] = tmpdice[0];
			dice[5] = tmpdice[3];
			dice[2] = tmpdice[5];
			dice[0] = tmpdice[2];
		}
		else
		{
			x += 1;
			return false;
		}
	}
	else if (num == 3)// 북
	{
		y -= 1;
		if (valid(y, x))
		{
			int tmpdice[6];
			for (int i = 0; i < 6; i++)
				tmpdice[i] = dice[i];
			dice[1] = tmpdice[0];
			dice[5] = tmpdice[1];
			dice[4] = tmpdice[5];
			dice[0] = tmpdice[4];
		}
		else
		{
			y += 1;
			return false;
		}
	}
	else if (num == 4)//남
	{
		y += 1;
		if (valid(y, x))
		{
			int tmpdice[6];
			for (int i = 0; i < 6; i++)
				tmpdice[i] = dice[i];
			dice[4] = tmpdice[0];
			dice[0] = tmpdice[1];
			dice[1] = tmpdice[5];
			dice[5] = tmpdice[4];
		}
		else
		{
			y -= 1;
			return false;
		}
	}

	if (board[y][x])
	{
		dice[0] = board[y][x];
		board[y][x] = 0;
	}
	else
		board[y][x] = dice[0];
	
	return true;
}
int main(void)
{
	cin >> n >> m >> y >> x >> k;

	cmd.resize(k);
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
		cin >> board[i][j];

	for (int i = 0; i < k; i++)
		cin >> cmd[i];

	for (int i = 0; i < k; i++)
	{
		bool flag = operate(cmd[i]);
		if (flag)
		cout << dice[5] << "\n";
	}
}
