#include<iostream>
#include<queue>
#define MAX 200

using namespace std;

int k;
int height;
int width;
int board[MAX][MAX];
int visited[MAX][MAX][30];
int moveY[] = { -1, 1, 0, 0 };
int moveX[] = { 0, 0, -1, 1 };
int moveKnightY[] = {-1, -2, -2, -1, 1, 2, 2, 1 };
int moveKnightX[] = {-2, -1, 1, 2, -2, -1, 1, 2 };

int BFS()
{
	queue<pair<pair<int, int>,pair<int,int>>> q;
	q.push({ { 0, 0 }, {0,0} });
	visited[0][0][0] = true;

	while (!q.empty())
	{
		int curY = q.front().first.first;
		int curX = q.front().first.second;
		int knight = q.front().second.first;
		int curCnt = q.front().second.second;
		q.pop();

		if (curY == height - 1 && curX == width - 1)
			return curCnt;

		if (knight < k)
		{
			for (int i = 0; i < 8; i++)
			{
				int nextY = curY + moveKnightY[i];
				int nextX = curX + moveKnightX[i];
				
				if (0 <= nextY && nextY < height && nextX >= 0 && nextX < width)
				if (!visited[nextY][nextX][knight + 1] && !board[nextY][nextX])
				{
					visited[nextY][nextX][knight + 1] = true;
					q.push({{ nextY, nextX }, { knight + 1, curCnt + 1 }
				});
				}
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int nextY = curY + moveY[i];
			int nextX = curX + moveX[i];

			if (0 <= nextY && nextY < height && 0 <= nextX && nextX < width)
			if (!visited[nextY][nextX][knight] && !board[nextY][nextX])
			{
				visited[nextY][nextX][knight] = true;
				q.push({ { nextY, nextX }, { knight, curCnt + 1 } });
			}
		}	
	}
	return -1;
}
int main(int argc, char *argv[])
{
	cin >> k;
	cin >> width >> height;

	for (int i = 0; i < height; i++)
	for (int j = 0; j < width; j++)
	{
		cin >> board[i][j];
	}

	cout << BFS() << "\n";
}
