#include<bits/stdc++.h>

using namespace std;

int board[2187][2187];
int n;
int falseNum, zeroNum, positiveNum;

void divide(int y, int x, int num)
{
	int flag = true;
	int signal = board[y][x];
	for (int i = y; i < y + num; i++)
	for (int j = x; j < x + num; j++)
	{
		if (signal != board[i][j])
			flag = false;
	}
	
	if (flag)
	{
		if (signal == -1)
			falseNum++;
		else if (signal == 0)
			zeroNum++;
		else positiveNum++;
	}
	else
	{
		int size = num / 3;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				divide(y + size *i, x + size * j, size);
		}
	}
}
int main(int argc, char *argv[])
{
	cin >> n;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		cin >> board[i][j];

	divide(0, 0, n);

	cout << falseNum << "\n";
	cout << zeroNum << "\n";
	cout << positiveNum << "\n";
}
