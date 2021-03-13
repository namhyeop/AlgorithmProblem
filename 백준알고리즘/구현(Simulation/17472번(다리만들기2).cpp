#include<bits/stdc++.h>
#define MAX 10
using namespace std;

int moveY[] = { 1, 0, -1, 0 }; /////////////
int moveX[] = { 0, 1, 0, -1 };

typedef struct
{
	int y;
	int x;
	int dir;
}state;

int n, m;
int ret;
int board[MAX][MAX];
vector<pair<int, int>> islands;

bool isAllConnected(int tmpboard[][MAX])
{
	queue<state> q;
	q.push({ islands[0].first, islands[0].second, 0 });

	bool visited[MAX][MAX] = { false, };
	visited[islands[0].first][islands[0].second] = true;

	bool bridgeVisited[MAX][MAX][2] = { false, };

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int dir = q.front().dir;
		q.pop();
		
		//다리일 경우 위에서 정한 방향으로(같은 방향으로) 전진
		if (tmpboard[y][x] >= 2)
		{
			int nextY = y + moveY[dir];
			int nextX = x + moveX[dir];

			//섬이고 이미 방문한 지역일 경우 
			if (visited[nextY][nextX])
				continue;

			//삼항연산자는 가로인지 세로인지 방향을 확인해주기 위한것
			bridgeVisited[nextY][nextX][dir >= 2 ? 3 - dir : dir] = true;
			if (tmpboard[nextY][nextX] == 1)
				visited[nextY][nextX] = true;

			q.push({ nextY, nextX, dir });
			continue;
		}

		//섬일 경우에는 동서남북 다 확인
		for (int k = 0; k < 2; k++)
		{
			for (int j = 0; j < 2; j++)
			{
				//삼항연사자로 상하좌우 다 구분
				int nextY = j == 0 ? y + moveY[k] : y - moveY[k];
				int nextX = j == 0 ? x + moveX[k] : x - moveX[k];

				//board의 범위를 초과할 경우
				if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m)
					continue;

				//바다이거나 이미 방문한 경우
				if (tmpboard[nextY][nextX] == 0 || visited[nextY][nextX])
					continue;

				//다리인데 중간에 방향이 바뀌어져서 짓는 경우
				if (tmpboard[nextY][nextX] >= 2 && (tmpboard[nextY][nextX] & (1 << (k + 1))) == false)
					continue;

				//다리이고 같은 방향이지만 이미 방문한 다리
				if (tmpboard[nextY][nextX] >= 2 && bridgeVisited[nextY][nextX][k])
					continue;

				//위의 예외처리를 다 만족하고 다리인 경우
				if (tmpboard[nextY][nextX] >= 2)
					bridgeVisited[nextY][nextX][k] = true;

				//섬일 경우
				if (tmpboard[nextY][nextX] == 1)
					visited[nextY][nextX] = true;

				q.push({ nextY, nextX, k + j * 2 });
			}
		}
	}

	//주어진 섬을 모두 방문한 경우에만 정답
	for (int i = 0; i < islands.size(); i++)
	{
		if (visited[islands[i].first][islands[i].second] == false)
		{
			return false;
		}
	}

	return true;
}

//입력값 board, 다리를 배치할 순서를 나타내는 인덱스, 배치한 다리 길이
void func(int tmpboard[MAX][MAX], int idx, int bridgeLength)
{
	if (isAllConnected(tmpboard))
	{
		ret = min(ret, bridgeLength);
		return;
	}

	for (int i = idx; i < islands.size(); i++)
	{
		for (int k = 0; k < 2; k++)
		{
			int y = islands[i].first;
			int x = islands[i].second;

			int cnt = 0;
			bool flag = false;

			int temp[MAX][MAX];

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
					temp[i][j] = tmpboard[i][j];
			}

			//섬에서 직진으로 탐색 중 섬이거나 경계를 벗어나는 경우 braek
			while (1)
			{
				int nextY = y + moveY[k];
				int nextX = x + moveX[k];

				if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m)
					break;

				if (temp[nextY][nextX] == 1)
				{
					flag = true;
					break;
				}

				//2는 하 4는 우 6은 중첩되는 방향을 의미
				temp[nextY][nextX] |= (1 << (k + 1));

				y = nextY;
				x = nextX;
				cnt++;
			}

			//다리를 짓다가 섬을 만나고, 다리길이가 2이상인 경우
			if (flag && cnt >= 2)
			{
				func(temp, i + 1, bridgeLength + cnt);
			}
		}

		bool flags[2] = { false, };
		int cnts[2] = { 0, };

		int temp[MAX][MAX];

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				temp[i][j] = tmpboard[i][j];
			}
		}

		for (int k = 0; k < 2; k++)
		{
			int y = islands[i].first;
			int x = islands[i].second;

			flags[k] = false;
			cnts[k] = 0;

			while (1)
			{
				int nextY = y + moveY[k];
				int nextX = x + moveX[k];

				if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m)
					break;

				if (temp[nextY][nextX] == 1)
				{
					flags[k] = true;
					break;
				}

				temp[nextY][nextX] |= (1 << (k + 1));

				y = nextY;
				x = nextX;
				cnts[k]++;
			}

			if ((flags[k] && cnts[k] > 1) == false)
				break;
		}

		if (flags[0] && flags[1] && cnts[0] > 1 && cnts[1] > 1)
		{
			func(temp, i + 1, bridgeLength + cnts[0] + cnts[1]);
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
				islands.push_back({ i, j });
		}
	}

	ret = INT_MAX;

	func(board, 0, 0);

	if (ret == INT_MAX)
		cout << -1 << "\n";
	else
		cout << ret << "\n";

	return 0;
}
