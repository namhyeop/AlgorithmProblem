#include<iostream>
#include<cstring>
using namespace std;

int n;
char board[3000][3000];
void solve(int y, int x, int num)
{
	if (num == 1)
	{
		board[y][x] = '*';
		return;
	}

	int div = num / 3;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 1 && j == 1)
				continue;
			else
				solve(y + (i * div), x + (j*div), div);
		}
	}
}
int main(int argc, char *argv[])
{
	cin >> n;
	memset(board, ' ', sizeof(board));
	solve(0, 0, n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << board[i][j];
		cout << "\n";
	}

	return 0;
}
