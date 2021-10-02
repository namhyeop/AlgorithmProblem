#include<bits/stdc++.h>
#define MAX 55
using namespace std;

int board[MAX][MAX];
int n, m, t;

bool validRest()
{
	vector<pair<int, int>> v;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0)
				continue;
			if (board[i][j] == board[i][(j + 1) % m])
			{
				v.push_back({ i, j });
				v.push_back({ i, (j + 1) % m });
			}
		}
	}

	for (int j = 0; j < m; j++)
	for (int i = 1; i + 1 <= n; i++)
	{
		if (board[i][j] == 0)
			continue;
		if (board[i][j] == board[i + 1][j])
		{
			v.push_back({ i, j });
			v.push_back({ i + 1, j });
		}
	}

	if (v.size() == 0)
		return false;

	int size = v.size();
	for (int i = 0; i < size; i++)
		board[v[i].first][v[i].second] = 0;

	return true;
}

void clockwise(int multiple, int cyclenum)
{
	for (int i = 1; i <= n; i++)
	{
		if (i % multiple == 0)
		{
			for (int k = 0; k < cyclenum; k++)
			{
				int tmp = board[i][m - 1];
				for (int j = m - 1; j - 1 >= 0; j--)
					board[i][j] = board[i][j - 1];
				board[i][0] = tmp;
			}
		}
	}
}

void counterclockwise(int multiple, int cycle)
{
	for (int i = 1; i <= n; i++)
	{
		if (i % multiple == 0)
		{
			for (int k = 0; k < cycle; k++)
			{
				int tmp = board[i][0];
				for (int j = 0; j + 1 < m; j++)
					board[i][j] = board[i][j + 1];
				board[i][m - 1] = tmp;
			}
		}
	}
}

int main()
{
	cin >> n >> m >> t;

	for (int i = 1; i <= n; i++)
	for (int j = 0; j < m; j++)
		cin >> board[i][j];

	for (int i = 0; i < t; i++)
	{
		int x, d, k;
		cin >> x >> d >> k;

		if (d == 0)
			clockwise(x, k);
		else
			counterclockwise(x, k);

		bool flag = validRest();


		if (!flag)//원판에 인접하면서 같은 수가 없으면 평균을 구한다.
		{
			int sum = 0;
			int cnt = 0;
			for (int i = 1; i <= n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (board[i][j] != 0)
					{
						cnt++;
						sum += board[i][j];
					}
				}
			}

			double standard = (double)sum / cnt;

			for (int i = 1; i <= n; i++)
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] == 0)
					continue;
				if (board[i][j] > standard)
					board[i][j]--;
				else if (board[i][j] < standard)
					board[i][j]++;
			}

		}
	}


	int ret = 0;
	for (int i = 1; i <= n; i++)
	for (int j = 0; j < m; j++)
		ret += board[i][j];

	cout << ret << "\n";

	return 0;
}
