#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100

using namespace std;

int n, m;
bool visited[MAX][MAX];
char board[MAX][MAX];
vector<pair<pair<int, int>, int>> ret;
int moveY[4] = { -1, 1, 0, 0 };
int moveX[4] = { 0, 0, -1, 1 };

int main(int argc, char *argv[])
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
		cin >> board[i][j];

	int maxSpread = min(n, m) / 2;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	{
		if (board[i][j] == '*')
		{
			int num = 0;
			vector<pair<int, int>> v; // visited 체크 용도
			v.push_back({ i, j });
			for (int k = 1; k <= maxSpread; k++)
			{
				bool check = true;
				for (int t = 0; t < 4; t++)
				{
					int nextY = i + moveY[t] * k;
					int nextX = j + moveX[t] * k;

					if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < m && board[nextY][nextX] == '*')
						v.push_back({ nextY, nextX });
					else
					{
						check = false;
						break;
					}
				}

				if (check == false)
					break;
				
				num++;
			}

			if (num > 0)
			{
				ret.push_back({ { i, j }, num });
				for (int l = 0; l < v.size(); l++)
					visited[v[l].first][v[l].second] = 1;
			}
		}
	}

	bool flag = true;
	
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	if (board[i][j] == '*' && !visited[i][j])
		flag = false;
	
	if (flag == false)
		cout << -1 << "\n";
	else
	{
		if (ret.size() == 0)
			cout << "-1" << "\n";
		else
		{
			cout << ret.size() << "\n";
			for (int i = 0; i < ret.size(); i++)
				cout << ret[i].first.first + 1 << " " << ret[i].first.second + 1 << " " << ret[i].second << "\n";
		}
	}
	return 0;
}
