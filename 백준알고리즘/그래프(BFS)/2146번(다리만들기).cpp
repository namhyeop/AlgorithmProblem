#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>

#define MAX 100
#define INF 987654321
using namespace std;

int N;
int board[MAX][MAX];
bool visited[MAX][MAX];
int moveY[4] = { -1, 1, 0, 0 };
int moveX[4] = { 0, 0, -1, 1 };
queue<pair<int, int>> q;

void DFS(int y, int x, int cnt)
{
	visited[y][x] = true;
	board[y][x] = cnt;

	for (int i = 0; i < 4; i++)
	{
		int nextY = y + moveY[i];
		int nextX = x + moveX[i];

		if (0 <= nextY && nextY < N && nextX >= 0 && nextX < N)
		if (board[nextY][nextX] && !visited[nextY][nextX])
			DFS(nextY, nextX, cnt);
	}
}

int BFS(int cnt)
{
	q = queue<pair<int,int>>(); //큐 초기화

	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
		if (board[i][j] == cnt)
		{
			visited[i][j] = true;
			q.push({ i, j });
		}
	

	int result = 0;
	while (!q.empty())
	{
		int curSize = q.size();
		
		for (int i = 0; i < curSize; i++)
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nextY = y + moveY[i];
				int nextX = x + moveX[i];

				if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < N)
				{
					if (board[nextY][nextX] && board[nextY][nextX] != cnt)
						return result;
					else if (!board[nextY][nextX] && !visited[nextY][nextX])
					{
						visited[nextY][nextX] = true;
						q.push({ nextY, nextX });
					}
				}
			}
		}
		result++;
	}

}
int main(int argc, char *argv[])
{
	cin >> N;

	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
		cin >> board[i][j];
	
	int cnt = 1;

	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
	if (board[i][j] && !visited[i][j])
		DFS(i, j, cnt++);

	int result = INF;
	
	for (int i = 1; i < cnt; i++)
	{
		memset(visited, false, sizeof(visited));
		result = min(result, BFS(i));
	}

	cout << result << "\n";

	return 0;
}
