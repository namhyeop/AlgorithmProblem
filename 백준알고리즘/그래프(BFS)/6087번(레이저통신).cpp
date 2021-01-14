#include<iostream>
#include<queue>
#include<string>
#define MAX 100

using namespace std;

int height;
int width;
string board[MAX];
int visited[MAX][MAX];
int moveY[4] = { 1, -1, 0, 0 };
int moveX[4] = { 0, 0, 1, -1 };
vector<pair<int, int>> position;

int BFS(int startY, int startX)
{
	queue<pair<pair<int, int>, pair<int, int>>> q;

	for (int i = 0; i < 4; i++)
		q.push({{ startY, startX }, { i, 0 }});
	visited[startY][startX] = 0;
	
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int dir = q.front().second.first;
		int cnt = q.front().second.second;
		
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextY = y + moveY[i];
			int nextX = x + moveX[i];
			int nextCnt = cnt;

			if (nextY < 0 || nextY >= height || nextX < 0 || nextX >= width)
				continue;
			if (board[nextY][nextX] == '*')
				continue;
			if (dir != i)
				nextCnt += 1;
			if (visited[nextY][nextX] >= nextCnt)
			{
				visited[nextY][nextX] = nextCnt;
				q.push({ { nextY, nextX }, { i, nextCnt } });
			}
		}
	}
	return visited[position[1].first][position[1].second];
}

int main(int argc, char *argv[])
{
	cin >> width >> height;

	for (int i = 0; i < height; i++)
	{
		cin >> board[i];
		for (int j = 0; j < width; j++)
		{
			if (board[i][j] == 'C')
				position.push_back({ i, j });
			visited[i][j] = 987654321;
		}
	}

	cout << BFS(position[0].first, position[0].second) << "\n";
}
