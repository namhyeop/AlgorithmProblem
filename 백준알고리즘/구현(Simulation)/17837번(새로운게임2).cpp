#include<bits/stdc++.h>
#define MAX 12
#define CYCLEMAX 1000
using namespace std;

int n, k;
int board[MAX][MAX];

/*
1 : ->
2 : <-
3 : 상
4 : 하
*/

enum Color
{
	WHITE = 0, RED, BLUE
};

typedef struct
{
	int y;
	int x;
	int dir;
}object;

int moveY[] = { 0, 0, 0, -1, 1 };
int moveX[] = { 0, 1, -1, 0, 0 };
vector<int> pieces[MAX][MAX];

bool isFinished(void)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (pieces[i][j].size() >= 4)
				return true;
		}
	}
	return false;
}

int main(void)
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		cin >> board[i][j];

	vector<object> chessPieces(k);

	for (int i = 0; i < k; i++)
	{
		int y, x, dir;
		cin >> y >> x >> dir;

		chessPieces[i] = { y - 1, x - 1, dir };
		pieces[y - 1][x - 1].push_back(i);
	}

	vector<int> v;

	for (int t = 1; t <= CYCLEMAX; t++)
	{
		for (int a = 0; a < k; a++)
		{
			if (isFinished())
			{
				cout << t << "\n";
				return 0;
			}

			int y = chessPieces[a].y;
			int x = chessPieces[a].x;
			int d = chessPieces[a].dir;

			int nextY = y + moveY[d];
			int nextX = x + moveX[d];

			vector<int> v;
			bool flag = false;
			int nextDir = d;

			if ((nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) || board[nextY][nextX] == BLUE)
			{
				nextDir = d < 3 ? 3 - d : 7 - d;
				nextY = y + moveY[nextDir];
				nextX = x + moveX[nextDir];

				if ((nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) || board[nextY][nextX] == BLUE)
				{
					chessPieces[a] = { y, x, nextDir };
					continue;
				}
				flag = true;
			}

			v = pieces[y][x];
			int startIdx = 0;

			for (int i = 0; i < v.size(); i++)
			{
				if (v[i] == a)
				{
					startIdx = i;
					break;
				}
			}
			chessPieces[a] = { nextY, nextX, d };


			if (flag)
			{
				chessPieces[a].dir = nextDir;
			}

			if (board[nextY][nextX] == RED)
			{
				if (startIdx == 0)
					reverse(v.begin(), v.end());
				else
					reverse(v.begin() + startIdx, v.end());
			}

			for (int i = startIdx; i < v.size(); i++)
			{
				chessPieces[v[i]].y = nextY;
				chessPieces[v[i]].x = nextX;
				pieces[nextY][nextX].push_back(v[i]);
			}

			if (startIdx == 0)
			{
				pieces[y][x].clear();
			}
			else
			{
				pieces[y][x].erase(pieces[y][x].begin() + startIdx, pieces[y][x].end());
			}
		}



		if (isFinished())
		{
			cout << t << "\n";
			return 0;
		}
	}

	cout << -1 << "\n";
	return 0;

}
