#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)

using namespace std;

const int MAX = 9;

int board[MAX][MAX];
bool row[MAX][MAX];
bool col[MAX][MAX];
bool square[MAX][MAX];

int calculator(int y, int x)
{
	return (y / 3) * 3 + x / 3;
}

void DFS(int cnt)
{
	if (cnt == 81)
	{
		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
				cout << board[i][j] << " ";
			cout << "\n";
		}
		exit(0);
	}

	int y = cnt / 9;
	int x = cnt % 9;

	if (board[y][x])
		DFS(cnt + 1);
	else
	{
		for (int k = 1; k <= MAX; k++)
		{
			if (!row[y][k] && !col[x][k] && !square[calculator(y, x)][k])
			{
				board[y][x] = k;
				row[y][k] = true;
				col[x][k] = true;
				square[calculator(y, x)][k] = true;
				DFS(cnt + 1);
				board[y][x] = 0;
				row[y][k] = false;
				col[x][k] = false;
				square[calculator(y, x)][k] = false;
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < MAX; i++)
	for (int j = 0; j < MAX; j++)
	{
		cin >> board[i][j];

		if (board[i][j])
		{
			row[i][board[i][j]] = true;
			col[j][board[i][j]] = true;
			square[calculator(i, j)][board[i][j]] = true;
		}
	}

	DFS(0);

	return 0;
}
