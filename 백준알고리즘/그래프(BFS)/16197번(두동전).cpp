#include<iostream>
#include<queue>
#include<string>

#define MAX 22
using namespace std;

struct coinBeg
{
	int y1;
	int x1;
	int y2;
	int x2;
	int cnt;
};

int height;
int width;
string board[MAX];
int moveY[4] = { -1, 1, 0, 0 };
int moveX[4] = { 0, 0, -1, 1 };
int visited[MAX][MAX][MAX][MAX];
vector<pair<int, int>> coin;
pair<int, int> coin1, coin2;

bool outCheck(int y, int x)
{
	if ((0 <= y && y < height) && (0 <= x && x < width))
		return true;

	return false;
}

int BFS()
{
	queue<coinBeg> q;
	q.push({ coin[0].first, coin[0].second, coin[1].first, coin[1].second, 0 });
	
	while (!q.empty())
	{
		coinBeg cur = q.front();
		visited[cur.y1][cur.x1][cur.y2][cur.x2] = 1;
		q.pop();

		if (cur.cnt > 10)
			break;

		for (int i = 0; i < 4; i++)
		{
			int nextY1 = cur.y1 + moveY[i];
			int nextX1 = cur.x1 + moveX[i];
			int nextY2 = cur.y2 + moveY[i];
			int nextX2 = cur.x2 + moveX[i];

			if ((outCheck(nextY1, nextX1) && !outCheck(nextY2, nextX2)) || (!outCheck(nextY1, nextX1) && outCheck(nextY2, nextX2)))
			{
				if (cur.cnt + 1 > 10)
					return -1;
				return cur.cnt + 1;
			}

			//둘 다 범위를 초과한 경우
			if (!outCheck(nextY1, nextX1) && !outCheck(nextY2, nextX2))
				continue;

			//둘 다 벽이라서 나가야 하는 경우
			if (board[nextY1][nextX1] == '#' && board[nextY2][nextX2] == '#')
			{
				continue;
			}

			//하나만 벽에 부딪치는 경우
			if (board[nextY1][nextX1] == '#')
			{
				nextY1 = cur.y1;
				nextX1 = cur.x1;
			}
			else if (board[nextY2][nextX2] == '#')
			{
				nextY2 = cur.y2;
				nextX2 = cur.x2;
			}

			if (!visited[nextY1][nextX1][nextY2][nextX2])
			{
				q.push({ nextY1, nextX1, nextY2, nextX2, cur.cnt + 1 });
				visited[nextY1][nextX1][nextY2][nextX2] = true;
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
			if (board[i][j] == 'o')
			{
				coin.push_back({ i, j });
			}
		}
	}

	cout << BFS() << "\n";

}
