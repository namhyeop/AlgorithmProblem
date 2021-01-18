#include<iostream>
#include<queue>
#include<cstring>

#define MAX 101
using namespace std;

int N;
int M;
int a, b, c, d;
bool light[MAX][MAX];
bool visited[MAX][MAX];
vector <pair<int,int>> board[MAX][MAX];
int cnt;

int moveY[4] = { -1, 1, 0, 0 };
int moveX[4] = { 0, 0, -1, 1 };

void BFS()
{
	while (1)
	{
		memset(visited, false, sizeof(visited));
		queue<pair<int, int>> q;
		q.push({ 0, 0 });
		visited[0][0] = true;
		light[0][0] = true;
		bool flag = false;

		while (!q.empty())
		{
			int curY = q.front().first;
			int curX = q.front().second;
			//cout << "qsize: " << q.size() << " " << curY << " " << curX << "\n";
			q.pop();

			if (!board[curY][curX].empty())
			{
				for (int i = 0; i < board[curY][curX].size(); i++)
				{
					auto tmp = board[curY][curX][i];
					light[tmp.first][tmp.second] = true;
				}
				board[curY][curX].clear();
				flag = true;
			}

			for (int i = 0; i < 4; i++)
			{
				int nextY = curY + moveY[i];
				int nextX = curX + moveX[i];

				if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < N)
				if (light[nextY][nextX] && !visited[nextY][nextX])
				{
					q.push({ nextY, nextX });
					visited[nextY][nextX] = true;
				}
			}
		}
		if (!flag)
			break;
	}
}
int main(int argc, char *argv[])
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c >> d;
		board[a - 1][b - 1].push_back({ c - 1, d - 1 });
	}

	BFS();
	
	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
		if (light[i][j])
			cnt++;
		
		
	cout << cnt << "\n";
	return 0;
}
