#include<bits/stdc++.h>

using namespace std;

char board[12][6];
bool visited[12][6];
int moveY[] = { -1, 1, 0, 0 };
int moveX[] = { 0, 0, -1, 1 };
int flag = false;
int ret;

void moveShape()//뿌신 도형들이 중력이 밑으로 작용하므로 전부 아래로 밀어줘야 한다.
{
	char tmpboard[12];

	for (int x = 0; x < 6; x++)
	{
		memset(tmpboard, '.', sizeof(tmpboard));
		int idx = 0;
		for (int y = 11; y >= 0; y--)
		{
			if (board[y][x] != '.')
			{
				tmpboard[idx] = board[y][x];
				board[y][x] = '.';
				idx++;
			}
		}

		for (int y = 11, cur = 0; y >= 0; y--, cur++)
			board[y][x] = tmpboard[cur];
	}
}
void BFS(int y, int x, char color )
{
	int cnt = 1;
	visited[y][x] = true;
	queue<pair<int, int>> q; //BFS탐색을 위한 queue
	queue<pair<int, int>> tmpq;//부술 도형들을 .으로 표현해주기 위한 queue
	tmpq.push({ y, x });
	q.push({ y, x });

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = y + moveY[i];
			int nextX = x + moveX[i];

			if (0 <= nextY && nextY < 12 && 0 <= nextX && nextX < 6)
			if (!visited[nextY][nextX] && board[nextY][nextX] == color)
			{
				visited[nextY][nextX] = true;
				q.push({ nextY, nextX });
				tmpq.push({ nextY, nextX });
				cnt++;
			}
		}
	}

	if (cnt >= 4) //뿌요가 4개일 경우 부순다.
	{
		flag = true;
		while (!tmpq.empty())
		{
			int y = tmpq.front().first;
			int x = tmpq.front().second;
			tmpq.pop();
			board[y][x] = '.';
		}
	}
}
int main(void)
{
	for (int i = 0; i < 12; i++)
	for (int j = 0; j < 6; j++)
		cin >> board[i][j];

	while (1)
	{
		flag = false;
		for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
		{
			if (board[i][j] != '.')
			{
				BFS(i, j, board[i][j]);
			}
		}

		if (!flag) //더 이상 부셔질 단어가 없으면 탈출
			break;

		memset(visited, false, sizeof(visited));
		ret++;
		moveShape();

	}

	cout << ret << "\n";

	return 0;
}
