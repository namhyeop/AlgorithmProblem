#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

#define MAX 100

int height, width;
int moveY[4] = { -1, 1, 0, 0 };
int moveX[4] = { 0, 0, -1, 1 };
string input[MAX];
bool visited[100][100];
int cache[100][100];

void bfs(int y, int x)
{
	visited[y][x] = true;

	queue<pair<int,int>> q;
	q.push(make_pair(y,x));

	while (!q.empty())
	{
		int tmpY = q.front().first;
		int tmpX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int dy = tmpY + moveY[i];
			int dx = tmpX + moveX[i];
			if (0 <= dy && dy < height &&
				0 <= dx && dx < width &&
				input[dy][dx] == '1' &&
				!visited[dy][dx] )
			{
				cache[dy][dx] = cache[tmpY][tmpX] + 1;
				visited[dy][dx] = true;
				q.push(make_pair(dy, dx));
			}

		}
	}
}
int main(int argc, char *argv[])
{
	cin >> height >> width;

	for (int i = 0; i < height; i++)
		cin >> input[i];
	bfs(0,0);
	cout << cache[height - 1][width - 1] +1<< "\n";
	
	return 0;
}
