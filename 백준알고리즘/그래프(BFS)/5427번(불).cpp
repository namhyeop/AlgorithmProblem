#include<iostream>
#include<queue>
#include<string>
#include<cstirng>

using namespace std;

#define MAX 1001

int width;
int height;
int moveY[4] = { -1, 1, 0, 0 };//상하좌우
int moveX[4] = { 0, 0, -1, 1 };
string board[MAX];
bool visited[MAX][MAX];
pair<int, int> start;
vector<pair<int, int>> fire;

int BFS()
{
	queue<pair<int, int>> q;
	q.push(start);
	queue<pair<int, int>> flame;
	for (int i = 0; i < fire.size(); i++)
		flame.push(fire[i]);

	int ret = 0;
	while (!q.empty())
	{
		int flameSize = flame.size();
		for (int i = 0; i < flameSize; i++)
		{
			int y = flame.front().first;
			int x = flame.front().second;
			flame.pop();

			for (int i = 0; i < 4; i++)
			{
				int nextY = y + moveY[i];
				int nextX = x + moveX[i];

				if (0 <= nextY && nextY < height && 0 <= nextX && nextX < width)
				if (board[nextY][nextX] == '.')
				{
					board[nextY][nextX] = '*';
					flame.push(make_pair(nextY, nextX));
				}
			}
		}

		int curSize = q.size();
		for (int i = 0; i < curSize; i++)
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			if (y == 0 || y == height - 1 || x == 0 || x == width - 1)
				return ret + 1;

			for (int i = 0; i < 4; i++)
			{
				int nextY = y + moveY[i];
				int nextX = x + moveX[i];

				if ( 0 <= nextY && nextY < height && 0 <= nextX && nextX < width)
				if (!visited[nextY][nextX] && board[nextY][nextX] != '*' && board[nextY][nextX] != '#')
				{
					visited[nextY][nextX] = true;
					q.push(make_pair(nextY, nextX));
				}
			}
		}
		ret++;
	}
	return -1;
}
int main(int argc, char *argv[])
{
	int Testcase;
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		fire.clear();
		memset(visited, false, sizeof(visited));

		cin >> width >> height;
		for (int j = 0; j < height; j++)
		{
			cin >> board[j];
			for (int k = 0; k < width; k++)
			{
				if (board[j][k] == '@')
					start = make_pair(j, k);
				else if (board[j][k] == '*')
					fire.push_back(make_pair(j, k));
			}
		}

		int result = BFS();

		if (result == -1)
			cout << "IMPOSSIBLE" << "\n";
		else
			cout << result << "\n";
	}
	return 0;
}
