#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<string.h>

using namespace std;

int height;
int width;
string board[50];
int visited[50][50];
int moveY[4] = { 1, -1, 0, 0 };
int moveX[4] = { 0, 0, -1, 1 };
vector<pair<int, int>> gold;
int ret;

int BFS(int y, int x)
{
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = 1;

	int ret = 0;
	while (!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		ret = max(ret, visited[curY][curX]);

		for (int i = 0; i < 4; i++)
		{
			int nextY = curY + moveY[i];
			int nextX = curX + moveX[i];

			if (0 <= nextY && nextY < height && 0 <= nextX && nextX < width)
			{
				if (board[nextY][nextX] == 'L' && !visited[nextY][nextX])
				{
					q.push({ nextY, nextX });
					visited[nextY][nextX] = visited[curY][curX] + 1;
				}
			}
		}
	}

	//visited배열을 방문 의미와 카운트를 동시에 사용하고 있어서 1로 설정해야 하는데 실제 카운트에서 시작점은 제외된다.
	return ret -1;
}
int main(int argc, char *argv[])
{
	cin >> height >> width;

	for (int i = 0; i < height; i++)
	{
		cin >> board[i];
		for (int j = 0; j < width; j++)
		{
			if (board[i][j] == 'L')
				gold.push_back({ i, j });
		}
	}

	for (int i = 0; i < gold.size(); i++)
		ret = max(ret,BFS(gold[i].first, gold[i].second));
	
	cout << ret << "\n";
}
