#include<iostream>
#include<queue>
#include<string.h>
#include<string>
#define MAX 1000000
using namespace std;


int moveY[4] = { 1, -1, 0, 0 };
int moveX[4] = { 0, 0, 1, -1 };
int ret = 0;
bool visited[MAX];
string board[5][5];

void bfs(int y, int x)
{
	queue<string> q;
	queue <pair<int, int>> position;

	q.push(board[y][x]);
	position.push({ y, x });

	while (!q.empty())
	{
		string temp = q.front();
		int dy = position.front().first;
		int dx = position.front().second;

		q.pop();
		position.pop();

		if (temp.size() == 6)
		{
			int now = stoi(temp);
			if (!visited[now])
			{
				ret++;
				visited[now] = true;
			}
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			int	nextY = dy + moveY[i];
			int nextX = dx + moveX[i];
			if (0 <= nextY && nextY < 5 && 0 <= nextX && nextX < 5)
			{
				q.push(temp + board[nextY][nextX]);
				position.push({ nextY, nextX });
			}
		}
	}
}

int main(int argc, char *argv[])
{
	for (int i = 0; i < 5; i++)
	for (int j = 0; j < 5; j++)
		cin >> board[i][j];

	for (int i = 0; i < 5; i++)
	for (int j = 0; j < 5; j++)
		bfs(i, j);

	cout << ret << "\n";
	return 0;
}
