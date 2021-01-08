#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<string.h>

using namespace std;

#define MAX 1001

int height;
int width;
int possibleBlock;
int board[MAX][MAX];
int visited[MAX][MAX][11];
int moveY[4] = { -1, 1, 0, 0 };
int moveX[4] = { 0, 0, -1, 1 };

struct node
{
	int y;
	int x;
	int wall;
	int cnt;

	node() {}
	node(int _y, int _x, int _wall, int _cnt) : y(_y), x(_x), wall(_wall), cnt(_cnt) { }
};

int bfs()
{
	queue<node> q;
	q.push(node(0,0,0,1));
	visited[0][0][0] = true;

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int wall = q.front().wall;
		int cnt = q.front().cnt;
		q.pop();

		if (y == height - 1 && x == width - 1)
			return cnt;
		
		for (int i = 0; i < 4; i++)
		{
			int ny = y + moveY[i];
			int nx = x + moveX[i];

			if (nx >= 0 && nx < width && ny >= 0 && ny < height)
			{
				if (board[ny][nx] == 1)
				{
					if (wall < possibleBlock && !visited[ny][nx][wall + 1])
					{
						q.push(node(ny, nx, wall + 1, cnt + 1));
						visited[ny][nx][wall + 1] = true;
					}
				}

				if (board[ny][nx] == 0 && !visited[ny][nx][wall])
				{
					q.push(node(ny, nx, wall, cnt + 1));
					visited[ny][nx][wall] = true;
				}
			}
		}
	}
	return -1;
}

int main(int argc, char *argv[])
{
	cin >> height >> width >> possibleBlock;

	for (int i = 0; i < height; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < width; j++)
			board[i][j] = tmp[j] - '0';
	}
	cout << bfs() << "\n";

	return 0;
}
