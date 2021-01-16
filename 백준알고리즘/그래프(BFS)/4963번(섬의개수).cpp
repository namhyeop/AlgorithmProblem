#include<iostream>
#include<queue>
#include<string.h>

using namespace std;

int board[50][50];
bool visited[50][50];
int height;
int width;
int moveY[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int moveX[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void BFS(int i, int j)
{
	queue<pair<int, int>> q;
	q.push({ i, j });
	visited[i][j] = true;

	while (!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int nextY = curY + moveY[i];
			int nextX = curX + moveX[i];

			if (nextY >= 0 && nextY < height && nextX >= 0 && nextX < width)
			if (board[nextY][nextX] == 1 && !visited[nextY][nextX])
			{
				q.push({ nextY, nextX });
				visited[nextY][nextX] = true;
			}
		}
	}
}

int main(int argc, char *argv[])
{
	while (1)
	{
		int cnt = 0;

		cin >> width >> height;
		if (width == 0 && height == 0)
			break;

		memset(board, 0, sizeof(board));
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			cin >> board[i][j];
		
		for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
		{
			if (!visited[i][j] && board[i][j] == 1)
			{
				BFS(i, j);
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
