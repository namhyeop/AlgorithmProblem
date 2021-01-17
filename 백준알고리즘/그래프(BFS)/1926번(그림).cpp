#include<iostream>
#include<queue>
#define MAX 500

using namespace std;

int height;
int width;
int cnt;
int ret;
int moveY[4] = { -1, 1, 0, 0 };
int moveX[4] = { 0, 0, -1, 1 };
int board[MAX][MAX];
bool visited[MAX][MAX];

int BFS(int y, int x)
{
	int count = 1;
	queue<pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = true;
	
	while (!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = curY + moveY[i];
			int nextX = curX + moveX[i];

			if (nextY >= 0 && nextY < height && nextX >= 0 && nextX < width)
			if (!visited[nextY][nextX] && board[nextY][nextX] == 1)
			{
				visited[nextY][nextX] = true;
				q.push({ nextY, nextX });
				count++;
			}
		}
	}
	return count;
}

int main(int argc, char *argv[])
{
	cin >> height >> width;

	for (int i = 0; i < height; i++)
	for (int j = 0; j < width; j++)
		cin >> board[i][j];

	for (int i = 0; i < height; i++)
	for (int j = 0; j < width; j++)
	{
		if (!visited[i][j] && board[i][j] == 1)
		{
			cnt++;
			ret = max(ret,BFS(i, j));
		}
	}

	cout << cnt << "\n";
	cout << ret << "\n";
	return 0;
}
