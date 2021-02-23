#include<bits/stdc++.h>
#define MAX 50
using namespace std;

int R, C, T;
int board[MAX][MAX];
int srBoard[MAX][MAX];
int visited[MAX][MAX];
vector<int> aircleaner;
int moveY[] = { -1, 1, 0, 0 };
int moveX[] = { 0, 0, -1, 1 };


/*
3 3 1
0 30 7
-1 10 0
-1 0 20
*/
void spread()
{
	for (int i = 0; i < R; i++)
	for (int j = 0; j < C; j++)
	{
		if (board[i][j] > 0)
		{
			srBoard[i][j] = board[i][j] / 5;
		}
	}

	for (int i = 0; i < R; i++)
	for (int j = 0; j < C; j++)
	{
		int cnt = 0;
		for (int d = 0; d < 4; d++)
		{
			if (i + moveY[d] >= 0 && i + moveY[d] < R && j + moveX[d] >= 0 && j + moveX[d] < C)
			if (board[i + moveY[d]][j + moveX[d]] >= 0)
			{
				board[i + moveY[d]][j + moveX[d]] += srBoard[i][j];
				cnt++;
			}
		}
		board[i][j] -= cnt * srBoard[i][j];
	}
	
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}

}

void circulation1()
{
	int y = aircleaner[0];
	 
	for (int i = y - 1; i > 0; i++)
		board[i][0] = board[i - 1][0];
	for (int i = 0; i < C - 1; i++)
		board[0][i] = board[0][i + 1];
	for (int i = 0; i < y; i++)
		board[i][C - 1] = board[i + 1][C - 1];
	for (int i = C - 1; i > 1; i--)
		board[y][i] = board[y][i - 1];
}

void circulation2()
{
	int y = aircleaner[1];

	for (int i = y + 1; i < R; i++)
		board[i][0] = board[i + 1][0];
	for (int i = 0; i < C - 1; i++)
		board[R][i] = board[R][i + 1];
	for (int i = R - 1; i > y; i--)
		board[i][C - 1] = board[i - 1][C - 1];
	for (int i = C - 1; i > 1; i--)
		board[y][i] = board[y][i - 1];
}

int main(void)
{
	cin >> R >> C >> T;

	for (int i = 0; i < R; i++)
	for (int j = 0; j < C; j++)
	{
		cin >> board[i][j];
		if (board[i][j] == -1)
			aircleaner.push_back(i);
	}

	cout << aircleaner[0] << "\n";
	cout << aircleaner[1] << "\n";

	for (int i = 0; i < T; i++)
	{
		spread();
		circulation1();
		cout << "---------" << "\n";
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}
		circulation2();
		cout << "---------" << "\n";
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}
	}

	int sum = 0;
	for (int i = 0; i < R; i++)
	for (int j = 0; j < C; j++)
	if (board[i][j] != -1)
		sum += board[i][j];

	cout << sum << "\n";

	return 0;
}
