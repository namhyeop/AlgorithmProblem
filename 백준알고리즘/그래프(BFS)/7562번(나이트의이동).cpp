#include<iostream>
#include<queue>
#include<string.h>

using namespace std;
#define MAX 300

int length;
pair<int, int> start;
pair<int, int> finish;
int moveY[8] = { -1, -2, -1, -2, 1, 2, 1, 2 };
int moveX[8] = { -2, -1, 2, 1, -2, -1, 2, 1 };
bool visited[MAX][MAX];
int cache[MAX][MAX];

int BFS(int y, int x)
{
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	cache[y][x] = 0;


	while (!q.empty())
	{
		pair<int, int> here = q.front();
		q.pop();

		if (finish.first == here.first && finish.second == here.second)
			return cache[here.first][here.second];

		for (int i = 0; i < 8; i++)
		{
			int dy = here.first + moveY[i];
			int dx = here.second + moveX[i];

			if (0 <= dy && dy < length &&
				0 <= dx && dx < length &&
				!visited[dy][dx])
			{
				q.push(make_pair(dy, dx));
				visited[dy][dx] = true;
				cache[dy][dx] = cache[here.first][here.second] + 1;
			}
		}
	}
}
int main(int argc, char *argv[])
{
	int Testcase;
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		cin >> length;
		cin >> start.first >> start.second;
		cin >> finish.first >> finish.second;

		memset(visited, false, sizeof(visited));
		memset(cache, 0, sizeof(cache));

		cout << BFS(start.first, start.second) << "\n";
	}
	return 0;
}
