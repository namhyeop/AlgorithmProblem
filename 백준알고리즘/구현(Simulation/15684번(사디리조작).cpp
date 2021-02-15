#include<bits/stdc++.h>
#define MAX 30
using namespace std;

int n, m, h;

int ladder[MAX][11];
int ladderCnt;
bool flag;

void DFS(int y, int cnt)
{
	if (flag)
		return;

	if (ladderCnt == cnt)
	{
		bool possible = true;
		for (int i = 1; i <= n; i++)
		{
			int row = i;
			for (int j = 0; j < h; j++)
			if (ladder[j][row])
				row++;
			else if (row > 1 && ladder[j][row - 1])
				row--;

			if (row != i)
			{
				possible = false;
				break;
			}
		}
		if (possible)
			flag = true;
		return;
	}

	for (int i = y; i < h; i++)
	for (int j = 1; j < n; j++)
	if (!ladder[i][j - 1] && !ladder[i][j] && !ladder[i][j + 1])
	{
		ladder[i][j] = true;
		DFS(i, cnt + 1);
		ladder[i][j] = false;
	}
	return;
}

int main(void)
{
	cin >> n >> m >> h;

	for (int i = 0; i < m; i++)
	{
		int y, x;
		cin >> y >> x;
		ladder[y - 1][x] = true;
	}

	for (int i = 0; i <= 3; i++)
	{
		ladderCnt = i;
		DFS(0, 0);
		if (flag)
		{
			cout << ladderCnt << "\n";
			return 0;
		}
	}

	cout << -1 << "\n";
}
