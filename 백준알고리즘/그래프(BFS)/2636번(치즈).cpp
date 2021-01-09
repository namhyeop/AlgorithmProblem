#include<iostream>
#include<queue>
#include<vector>
#define MAX 100
using namespace std;

int height;
int width;
int board[MAX][MAX];
bool visited[MAX][MAX];
int moveY[4] = { 1, -1, 0, 0 };
int moveX[4] = { 0, 0, -1, 1 };
int beforeRet;
int cnt;

void BFS()
{
	queue<pair<int,int>> q;
	queue<pair<int, int>> cheseQ;
	q.push({0,0});

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int dy = y + moveY[i];
			int dx = x + moveX[i];

			if (dy >= 0 && dy < height && dx >= 0 && dx < width && !visited[dy][dx])
			{
				if (board[dy][dx] == 0)
				{
					q.push({ dy, dx });
					visited[dy][dx] = true;
				}
				else if (board[dy][dx] == 1)
				{
					cheseQ.push({ dy, dx });
					visited[dy][dx] = true;
				}
			}
		}

		if (q.empty())
		{
			while (!cheseQ.empty())
			{
				int y = cheseQ.front().first;
				int x = cheseQ.front().second;
				cheseQ.pop();

				board[y][x] = 0;
				q.push({ y, x });
			}

			if (!q.empty())
			{
				cnt++;
				beforeRet = q.size();
			}
		}
	}
}

int main(int argc, char*argv[])
{
	cin >> height >> width;

	for (int i = 0; i < height; i++)
	for (int j = 0; j < width; j++)
	{
		cin >> board[i][j];
	}

	BFS();

	cout << cnt << "\n";
	cout << beforeRet << "\n";

	return 0;
}
