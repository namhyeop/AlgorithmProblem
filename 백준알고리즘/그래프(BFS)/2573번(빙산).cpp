#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>

#define MAX 333
using namespace std;

int height;
int width;
int moveY[4] = { -1, 1, 0, 0 };
int moveX[4] = { 0, 0, -1, 1 };
int board[MAX][MAX];
int tmpboard[MAX][MAX];
int visited[MAX][MAX];
queue<pair<int, int>> q;

void BFS(int y, int x)
{
	visited[y][x] = true;
	queue<pair<int, int>> q;
	q.push({ y, x });

	while (!q.empty())
	{
		int cury = q.front().first;
		int curx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = cury + moveY[i];
			int nextX = curx + moveX[i];

			if (nextY >= 0 && nextY < height && nextX >= 0 && nextX < width)
			if (!visited[nextY][nextX] && board[nextY][nextX])
			{
				visited[nextY][nextX] = true;
				q.push({ nextY, nextX });
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

	int ret = 0;

	while (1)
	{
		int cnt = 0;
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
		if (!visited[i][j] && board[i][j] > 0)
		{
			cnt++;
			if (cnt >= 2)
			{
				cout << ret << "\n";
				return 0;
			}
			BFS(i, j);
		}
		ret++;

		if (cnt == 0)
			break;

		memcpy(tmpboard, board, sizeof(board));

		for (int i = 1; i < height; i++)
		for (int j = 1; j < width; j++)
		if (tmpboard[i][j] > 0)
		{
			int deCnt = 0;
			for (int k = 0; k < 4; k++)
			{
				int nextY = i + moveY[k];
				int nextX = j + moveX[k];

				if (tmpboard[nextY][nextX] == 0)
					deCnt++;
			}
			board[i][j] = max(tmpboard[i][j] - deCnt, 0);
		}

		/*빙산 지도 변화과정확인
		cout << "\n";
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
				cout << board[i][j] << " ";
				cout << "\n";
		}*/
	}

	//while문 안에서 안 끝난다는것은 2개 이상인 빙산이 없다는 의미
	cout << "0" << "\n";

	return 0;
}
