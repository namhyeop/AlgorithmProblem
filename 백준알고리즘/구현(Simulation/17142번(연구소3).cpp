#include<bits/stdc++.h>
#define MAX 50
using namespace std;

int N, M;
int ret = INT_MAX;
int flag;
int board[MAX][MAX];
int tmpboard[MAX][MAX];
vector<pair<int, int>> virus;
vector<int> tmp;

int moveY[] = { -1, 1, 0, 0 };
int moveX[] = { 0, 0, -1, 1 };

void DFS(int cnt)
{
	memcpy(tmpboard, board, sizeof(tmpboard));

	queue<pair<int, int>> q;
	for (int i = 0; i < tmp.size(); i++)
	if (tmp[i])
	{
		q.push(virus[i]);
		tmpboard[virus[i].first][virus[i].second] = 3;
	}
	int time = 0;

	while (!q.empty())
	{
		int size = q.size();
	
		if (!cnt)
		{
			flag = true;
			ret = min(ret, time);
			break;
		}

		time++;
		for (int i = 0; i < size; i++)
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++)
			{
				int nextY = y + moveY[j];
				int nextX = x + moveX[j];

				if (0 <= nextY && nextY < N && 0 <= nextX && nextX < N)
				if (tmpboard[nextY][nextX] == 0 || tmpboard[nextY][nextX] == 2)
				{
					if (tmpboard[nextY][nextX] == 0)
						cnt--;
					tmpboard[nextY][nextX] = 3;
					q.push({ nextY, nextX });
				}
			}
		}
	}
	return;
}

int main(void)
{
	cin >> N >> M;

	int cnt = 0;
	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
	{
		cin >> board[i][j];
		if (board[i][j] == 0)
			cnt++;
		if (board[i][j] == 2)
			virus.push_back({ i, j });
	}

	tmp.resize(virus.size());
	for (int i = 0; i < tmp.size(); i++)
		tmp[i] = 0;
	for (int i = 0; i < M; i++)
		tmp[i] = 1;

	sort(tmp.begin(), tmp.end()); 

	do
	{
		DFS(cnt);
	} while (next_permutation(tmp.begin(), tmp.end()));

	if (!flag)
		cout << -1 << "\n";
	else
		cout << ret << "\n";
	
	return 0;
}
