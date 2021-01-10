#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<map>
#define MAX 50

/*
정말 많은 깨달음을 준 문제
이런식으로 move값을 준 상태에서 BFS를 돌리면 당연히 작성한 board에서 퍼져나가는 형식으로 탐색을 하는데 어차피 최단 경로를 찾을 것이면 DFS나 BFS를 쓰는것이 맞고 
추가적인 조건으로 가장 적은 벽돌을 뚫는 경우를 찾는것이니 우선순위큐로 오름차순 조건을 만들면 가장 적은 벽돌을 뚫은 경우를 찾을 수 있는것을 알게 해준 문제. 
이론적으로 최단경로를 찾는것은 알고 있었지만 머리에서는 자꾸 전체 경로를 찾으려고 시도했기 때문에 오류가 많이 났던 문제였다.
이 문제를 통해 BFS의 전체적인 감을 잡은거 같다.
*/
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
