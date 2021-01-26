#include<iostream>
#define MAX 19

using namespace std;

const int notPiece = 0;
const int targetNum = 5;

int board[MAX][MAX];

int print_yx(int y, int x)
{
	cout << board[y][x] << "\n";
	cout << y + 1 << " " << x + 1 << "\n";
	return 1;
}

int checkRow(void)
{
	for (int y = 0; y < MAX; y++)
	{
		for (int x = 0; x <= MAX - targetNum; x++)
		{
			if (board[y][x] == notPiece)
				continue;

			int cnt;

			for (cnt = 1; cnt < targetNum; cnt++)
			{
				if (board[y][x] != board[y][x + cnt])
					break;
			}

			if (cnt != targetNum)
				continue;

			if ((board[y][x + targetNum] != board[y][x])
				&& (board[y][x - 1] != board[y][x]))
			{
				if (print_yx(y, x))
					return 1;
			}
		}
	}

	return 0;
}

int checkCol()
{
	for (int x = 0; x < MAX; x++)
	{
		for (int y = 0; y <= MAX - targetNum; y++)
		{
			if (board[y][x] == notPiece)
				continue;

			int cnt;

			for (cnt = 1; cnt < targetNum; cnt++)
			{
				if (board[y][x] != board[y + cnt][x])
					break;
			}

			if (cnt != targetNum)
				continue;

			if (( board[y + targetNum][x] != board[y][x])
				&& (board[y - 1][x] != board[y][x]))
			{
				if (print_yx(y, x))
					return 1;
			}
		}
	}
	return 0;
}

int downDiagonal(void)
{
	for (int x = 0; x <= MAX - targetNum; x++)
	for (int y = targetNum - 1; y < MAX; y++)
	{
		if (board[y][x] == notPiece)
			continue;

		int cnt;

		for (cnt = 1; cnt < targetNum; cnt++)
		{
			if (board[y][x] != board[y - cnt][x + cnt])
				break;
		}

		if (cnt != targetNum)
			continue;

		//뒤를 봐야하는경우 && 앞을 봐야 하는 경우
		if ((board[y - targetNum][x + targetNum] != board[y][x])
			&& (board[y + 1][x - 1] != board[y][x]))
		{
			if (print_yx(y, x))
				return 1;
		}
	}
	return 0;
}

int upDiagonal(void)
{
	for (int y = 0; y <= MAX - targetNum; y++)
	{
		for (int x = 0; x <= MAX - targetNum; x++)
		{
			if (board[y][x] == notPiece)
				continue;

			int cnt;

			for (cnt = 1; cnt < targetNum; cnt++)
			{
				if (board[y][x] != board[y + cnt][x + cnt])
					break;
			}

			if (cnt != targetNum)
				continue;

			if ((board[y][x] != board[y + targetNum][x + targetNum])
				&& (board[y - 1][x - 1] != board[y][x]))
			{
				if (print_yx(y, x))
					return 1;
			}
		}
	}
	return 0;
}



int main(int argc, char *argv[])
{
	for (int i = 0; i < MAX; i++)
	for (int j = 0; j < MAX; j++)
	{
		cin >> board[i][j];
	}

	if (checkRow())
		return 0;
	if (checkCol())
		return 0;
	if (downDiagonal())
		return 0;
	if (upDiagonal())
		return 0;

	cout << 0 << "\n";

	return 0;
}
