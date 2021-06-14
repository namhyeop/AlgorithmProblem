#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 31;
int board[MAX][11];
int n, m, h;
int boardCnt;
bool flag;

int main(void)
{
	fastio;
	cin >> n >> m >> h;

	for (int i = 0; i < m; i++)
	{
		int y, x;
		cin >> y >> x;
		board[y - 1][x] = true;
	}

	function<void(int, int)> DFS = [&](int y, int cnt)
	{
		if (flag)
			return;

		if (boardCnt == cnt)
		{
			bool possibleflag = true;
			for (int i = 1; i <= n; i++)
			{
				int row = i;
				for (int j = 0; j < h; j++)
				if (board[j][row])
					row++;
				else if (1 < row && board[j][row -1])
					row--;
				
				if (i != row)
				{
					possibleflag = false;
					break;
				}
			}
			if (possibleflag)
				flag = true;
			return;
		}

		for (int i = y; i < h; i++) //순서대로 한 개씩 사디리를 놓아보는 과정 
		for (int j = 1; j < n; j++)
		if (!board[i][j - 1] && !board[i][j] && !board[i][j + 1])
		{
			board[i][j] = true;
			DFS(i, cnt + 1);
			board[i][j] = false;
		}
		return;
	};

	for (int i = 0; i <= 3; i++)
	{
		boardCnt = i;
		DFS(0, 0);
		if (flag)
		{
			cout << boardCnt << "\n";
			return 0;
		}
	}
	cout << -1 << "\n";
}
/*
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
*/
