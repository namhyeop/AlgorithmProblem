#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
#include<string>
#define MAX 1500
using namespace std;

int height;
int width;
string board[MAX];
bool visited[MAX][MAX];
vector<pair<int, int>> bird;
queue<pair<int, int>> water;

int moveY[4] = { 1, -1, 0, 0 };
int moveX[4] = { 0, 0, -1, 1 };

int BFS()
{
	int count = 0;
	queue<pair<int, int>> q;
	q.push(bird[0]);
	
	visited[bird[0].first][bird[0].second] = true;

	while (1)
	{
		queue<pair<int, int>> nextQ;
		bool flag = false;

		while (!q.empty())
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			if (y == bird[1].first && x == bird[1].second)
			{
				flag = true;
				break;
			}

			for (int i = 0; i < 4; i++)
			{
				int dy = y + moveY[i];
				int dx = x + moveX[i];
			
				if (!visited[dy][dx] && dy >= 0 && dy < height && dx >= 0 && dx < width)
				{
					visited[dy][dx] = true;

					if (board[dy][dx] == 'X')
					{
						nextQ.push(make_pair(dy, dx));
						continue;
					}
					q.push(make_pair(dy, dx));
				}
			}
		}

		if (flag)
			break;

		q = nextQ; //백조 위주의 X들만 담아놓은 큐
		
		int curwaterSize = water.size();
		for (int i = 0; i < curwaterSize; i++)
		{
			int y = water.front().first;
			int x = water.front().second;
			water.pop();

			for (int j = 0; j < 4; j++)
			{
				int dy = y + moveY[j];
				int dx = x + moveX[j];
				
				if (dy >= 0 && dy < height && dx >=0 && dx < width)
				if (board[dy][dx] == 'X')
				{
					board[dy][dx] = '.';
					water.push(make_pair(dy, dx));
				}
				
			}
		}

		/*과정마다 변해가는 board판을 확인(디버깅 과정)
		cout << "\n";
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
				cout << board[i][j];
			cout << "\n";
		}*/
	
		count++;
	}
	return count;
}

int main(int argc, char *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> height >> width;

	for (int i = 0; i < height; i++)
	{
		cin >> board[i];
		for (int j = 0; j < width; j++)
		{
			if (board[i][j] == 'L')
				bird.push_back(make_pair(i, j));
			if (board[i][j] == '.' || board[i][j] == 'L')
				water.push(make_pair(i, j));
		}
	}

	cout << BFS() << "\n";
}

/*
4 4
L.XX
XXXX
XXXX
XXXL
*/
