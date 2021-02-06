#include<bits/stdc++.h>
#define MAX 51
#define GREEN 3
#define RED 4
#define STAND_GREEN 5
#define STAND_RED 6
#define FLOWER 100

using namespace std;

int n, m, g, r;
int moveY[] = { -1, 1, 0, 0 };
int moveX[] = { 0, 0, 1, -1 };
bool visited[MAX][MAX];
int board[MAX][MAX];
int flowerValue = INT_MIN;
vector<pair<int, int>> candi;
vector<int> color;
vector<int> combination;

void search()
{
	int tmpboard[MAX][MAX];
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
		tmpboard[i][j] = board[i][j];

	do
	{
		vector<pair<int, int>> p_land;
		for (int i = 0; i < combination.size(); i++)
		{
			if (combination[i] == 1)
				p_land.push_back(candi[i]);
		}

		do
		{
			int flower = 0;
			queue<pair<int, int>> q;

			for (int i = 0; i < p_land.size(); i++)
			{
				pair<int, int> p = p_land[i];
				board[p.first][p.second] = color[i];

				visited[p.first][p.second] = true;
				q.push({ p.first, p.second });
			}

			while (1)
			{
				vector<pair<int, int>> now;
				bool flag = false;

				while (!q.empty())
				{
					int y, x;
					y = q.front().first;
					x = q.front().second;
					q.pop();

					for (int i = 0; i < 4; i++)
					{
						int nextY = y + moveY[i];
						int nextX = x + moveX[i];

						if (nextY >= 0 && nextY < n
							&& nextX >= 0 && nextX < m
							&& board[nextY][nextX] != FLOWER
							&& !visited[nextY][nextX]
							&& board[nextY][nextX] != 0)
						{
						if ((board[y][x] == RED && board[nextY][nextX] == STAND_GREEN)
							|| (board[y][x] == GREEN && board[nextY][nextX] == STAND_RED))
						{
							board[nextY][nextX] = FLOWER;
							flower++;
						}
						else
						{
							flag = true;
							board[nextY][nextX] = board[y][x] + 2;
							now.push_back({ nextY, nextX });
						}
					}
				}
			}
				if (!flag)
				{
					flowerValue = max(flowerValue, flower);
					break;
				}

				for (int k = 0; k < now.size(); k++)
				{
					int y = now[k].first;
					int x = now[k].second;
					visited[y][x] = true;

					if (board[y][x] != FLOWER && (board[y][x] == STAND_GREEN || board[y][x] == STAND_RED))
					{
						board[y][x] -= 2;
						q.push({ y, x });
					}
				}
			}

			for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				board[i][j] = tmpboard[i][j];
				visited[i][j] = false;
			}

		} while (next_permutation(color.begin(), color.end()));
	} while (next_permutation(combination.begin(), combination.end()));
}

int main(int argc, char *argv[])
{
	cin >> n >> m >> g >> r;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	{
		cin >> board[i][j];
		if (board[i][j] == 2)
			candi.push_back({ i, j });
	}

	for (int i = 0; i < g + r; i++)
		combination.push_back(1);
	for (int j = 0; j < candi.size() - (g + r); j++)
		combination.push_back(0);
	sort(combination.begin(), combination.end());

	for (int i = 0; i < r; i++)
		color.push_back(RED);
	for (int j = 0; j < g; j++)
		color.push_back(GREEN);
	sort(color.begin(), color.end());

	search();

	cout << flowerValue << "\n";
	return 0;
}
