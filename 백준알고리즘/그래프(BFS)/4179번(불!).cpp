#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<string.h>

using namespace std;
#define MAX 1000

int height;
int width;
string board[MAX];
int moveY[4] = { -1, 1, 0, 0 };
int moveX[4] = { 0, 0, -1, 1 };
vector<pair<int, int>> firePlace;
pair<pair<int, int>, int> startJ;
bool visited[MAX][MAX];

int BFS()
{
	queue<pair<pair<int, int>, int>> q;
	q.push(startJ);

	queue<pair<int, int>> spreadFire;
	for (int i = 0; i < firePlace.size(); i++)
		spreadFire.push(firePlace[i]);

	while (!q.empty())
	{
		int fireSize = spreadFire.size();
		for (int k = 0; k < fireSize; k++)
		{
			int y = spreadFire.front().first;
			int x = spreadFire.front().second;
			spreadFire.pop();

			for (int l = 0; l < 4; l++)
			{
				int dy = y + moveY[l];
				int dx = x + moveX[l];

				if (dy >= 0 && dy < height && dx >= 0 && dx < width)
				if (board[dy][dx] != '#' && board[dy][dx] != 'F' && (board[dy][dx] == '.' || board[dy][dx] == 'J'))
				{
					board[dy][dx] = 'F';
					spreadFire.push(make_pair(dy, dx));
				}
			}
		}

		int humanSize = q.size();
		for (int i = 0; i < humanSize; i++)
		{
			int curY = q.front().first.first;
			int curX = q.front().first.second;
			int count = q.front().second;
			q.pop();

			if (curY == 0 || curY == height - 1 || curX == 0 || curX == width - 1)
				return count;

			for (int j = 0; j < 4; j++)
			{
				int dy = curY + moveY[j];
				int dx = curX + moveX[j];
				int dcount = count + 1;

				if (dy >= 0 && dy < height && dx >= 0 && dx < width)
				if (board[dy][dx] != '#' && board[dy][dx] == '.' && !visited[dy][dx])
				{
					visited[dy][dx] = true;
					q.push(make_pair(make_pair(dy, dx), dcount));
				}
			}
		}
	}

	return -1;
}
int main(int argc, char *argv[])
{
	cin >> height >> width;

	for (int i = 0; i < height; i++)
	{
		cin >> board[i];
		for (int j = 0; j < width; j++)
		{
			if (board[i][j] == 'J')
			{
				startJ.first.first = i;
				startJ.first.second = j;
				startJ.second = 0;
			}
			else if (board[i][j] == 'F')
			{
				firePlace.push_back(make_pair(i, j));
			}
		}
	}

	int ret = BFS();

	if (ret == -1)
		cout << "IMPOSSIBLE" << "\n";
	else
		cout << ret + 1 << "\n";

	return 0;
}
