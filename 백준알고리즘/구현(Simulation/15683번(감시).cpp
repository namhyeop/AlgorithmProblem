#include<bits/stdc++.h>
#define MAX 8
#define BLOCK 6
using namespace std;

int n, m;
vector <pair<pair<int, int>, int> > input;
int board[MAX][MAX];
int ret = INT_MAX;
int direction [5][4][2] =
{
	{ { 0, 1 } },
	{ { 0, -1 }, { 0, 1 } },
	{ { -1, 0 }, { 0, 1 } },
	{ { -1, 0 }, { 0, 1 }, { 0, -1 } },
	{ { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } }
};

void search(int level, int board[][MAX])
{
	if (input.size() == level)
	{
		int cnt = 0;

		for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0)
				cnt++;
		}
		ret = min(ret, cnt);
		return;
	}

	int cctvNum = input[level].second;
	int cycleValue;
	int cursor;
	switch (cctvNum)
	{
	case 0:
		cycleValue = 4;
		cursor = 1;
		break;
	case 2:
		cycleValue = 4;
		cursor = 2;
		break;
	case 3:
		cycleValue = 4;
		cursor = 3;
		break;
	case 1:
		cycleValue = 2;
		cursor = 2;
		break;
	default:
		cycleValue = 1;
		cursor = 4;
		break;
	}

	for (int i = 0; i < cycleValue; i++)
	{
		int y = input[level].first.first;
		int x = input[level].first.second;
		

		int tmpboard[MAX][MAX];
		memcpy(tmpboard, board, sizeof(tmpboard));
		for (int j = 0; j < cursor; j++)
		{
			int nextY = y + direction[cctvNum][j][0];
			int nextX = x + direction[cctvNum][j][1];
			while (1)
			{
				if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < m)
				{
					if (tmpboard[nextY][nextX] != 6)
						tmpboard[nextY][nextX] = '#';
					else
						break;
				}
				else
					break;

				nextY += direction[cctvNum][j][0];
				nextX += direction[cctvNum][j][1];
			}
		}

		search(level + 1, tmpboard);

		for (int i = 0; i < cursor; i++)
		{
			int tmp = - 1 * direction[cctvNum][i][0];
			direction[cctvNum][i][0] = direction[cctvNum][i][1];
			direction[cctvNum][i][1] = tmp;
		}
	}
}

int main(int argc, char *argv[])
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	{
		cin >> board[i][j];
		if (board[i][j] != 0 && board[i][j] != 6)
		{
			input.push_back({ { i, j }, board[i][j] -1 });
		}
	}

	search(0, board);

	cout << ret << "\n";

	return 0;
}
