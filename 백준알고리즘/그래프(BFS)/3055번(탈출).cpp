#include<iostream>
#include<queue>
#include<string.h>
#include<string>

using namespace std;

#define MAX 51


int row;
int col;
string board[MAX];
int moveY[4] = { -1, 1, 0, 0 };
int moveX[4] = { 0, 0, -1, 1 };
bool visited[MAX][MAX];
pair<int, int> start,finish;
vector<pair<int, int>> bigwater;

int bfs()
{
	queue<pair<int,int>> q;
	q.push(start);
	queue<pair<int,int>> flowwater;;
	for (int i = 0; i < bigwater.size(); i++)
		flowwater.push(bigwater[i]);
	
	int ret = 0;

	while (!q.empty())
	{
		int flowwaterSize = flowwater.size();

		for (int i = 0; i < flowwaterSize; i++)
		{
			int y = flowwater.front().first;
			int x = flowwater.front().second;
			flowwater.pop();

			for (int i = 0; i < 4; i++)
			{
				int dy = y + moveY[i];
				int dx = x + moveX[i];

				if (0 <= dy && dy < row && 0 <= dx && dx < col)
				if (board[dy][dx] == '.')
				{
					board[dy][dx] = '*';
					flowwater.push(make_pair(dy, dx));
				}
			}
		}

		int curSize = q.size();
		for (int i = 0; i < curSize; i++)
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			if (finish.first == y && finish.second == x)
				return ret;

			for (int i = 0; i < 4; i++)
			{
				int dy = y + moveY[i];
				int dx = x + moveX[i];

				if (0 <= dy && dy < row && 0 <= dx && dx < col)
				if (!visited[dy][dx] && board[dy][dx] != '*' &&board[dy][dx] != 'X')
				{
					visited[dy][dx] = true;
					q.push(make_pair(dy, dx));
				}
			}
		}
		ret++;
	}
	return -1;
}

int main(int argc, char *argv[])
{
	cin >> row >> col;

	for (int i = 0; i < row; i++)
	{
		cin >> board[i];
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == 'S')
				start = make_pair(i, j);
			else if (board[i][j] == 'D')
				finish = make_pair(i, j);
			else if (board[i][j] == '*')
				bigwater.push_back(make_pair(i, j));
		}
	}

	int ret = bfs();

	if (ret == -1)
		cout << "KAKTUS" << "\n";
	else
		cout << ret << "\n";

	return 0;
}
