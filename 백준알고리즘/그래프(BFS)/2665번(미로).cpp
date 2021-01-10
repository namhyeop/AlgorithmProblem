#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<map>
#define MAX 50

typedef struct
{
	int y;
	int x;
	int changeCnt;
}State;

struct cmp
{
	bool operator()(State a, State b)
	{
		return a.changeCnt > b.changeCnt;
	}
};

using namespace std;
int board[MAX][MAX];
int visited[MAX][MAX][2500];
int moveY[4] = { -1, 1, 0, 0 };
int moveX[4] = { 0, 0, -1, 1 };
int N;

void BFS()
{
	priority_queue<State, vector<State>, cmp> pq;
	pq.push({0, 0, 0 });

	visited[0][0][0] = true;

	while (!pq.empty())
	{
		int y = pq.top().y;
		int x = pq.top().x;
		int cnt = pq.top().changeCnt;
		pq.pop();
		
		if (y == N - 1 && x == N - 1)
		{
			cout << cnt << "\n";
			return ;
		}

		for (int i = 0; i < 4; i++)
		{
			int dy = y + moveY[i];
			int dx = x + moveX[i];

			if (dy >= 0 && dy < N && dx >= 0 && dx < N)
			{
				int tempCnt = cnt;

				if (board[dy][dx] == 0)
				{
					tempCnt++;
				}

				if (visited[dy][dx][tempCnt])
				{
					continue;
				}
				visited[dy][dx][tempCnt] = true;
				pq.push({ dy, dx, tempCnt });
			}
		}
	}
}

int main(int argc, char *argv[])
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < N; j++)
			board[i][j] = tmp[j] - '0';
	}

	BFS();
}
