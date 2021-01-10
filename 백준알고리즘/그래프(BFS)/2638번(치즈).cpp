#include<iostream>
#include<queue>
#include<vector>
#define MAX 101

using namespace std;

int height;
int width;
int board[MAX][MAX];
int countBoard[MAX][MAX];
int moveY[4] = { -1, 1, 0, 0 };
int moveX[4] = { 0, 0, -1, 1 };
bool visited[MAX][MAX];
int ret;

void BFS()
{
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visited[0][0] = true;
	queue<pair<int, int>> cheseQ;
	
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int dy = y + moveY[i];
			int dx = x + moveX[i];

			if (dy >= 0 && dy < height && dx >= 0 && dx < width)
			{
				if (board[dy][dx] == 0 && !visited[dy][dx])
				{
					q.push({ dy, dx });
					visited[dy][dx] = true;
				}
				else if (board[dy][dx] == 1)
				{
					countBoard[dy][dx] += 1;

					if (countBoard[dy][dx] >= 2 && !visited[dy][dx])
					{
						cheseQ.push({ dy, dx });
						visited[dy][dx] = true;
					}
				}
			}
		}

		if (q.empty())
		{
			if (!cheseQ.empty())
				ret++;
			else
				break;

			q = cheseQ;
			while(!cheseQ.empty())
			{
				board[cheseQ.front().first][cheseQ.front().second] = 0;
				cheseQ.pop();
			}
		}
	}
}

int main(int argc, char *argv[])
{
	cin >> height >> width;

	for (int i = 0; i < height; i++)
	for (int j = 0; j < width; j++)
		cin >> board[i][j];

	BFS();

	cout << ret << "\n";
	return 0;
}
