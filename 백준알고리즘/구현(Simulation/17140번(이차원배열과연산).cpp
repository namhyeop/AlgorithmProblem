#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int r, c, k;
int board[MAX][MAX];

int main(void)
{
	cin >> r >> c >> k;
	r -= 1;
	c -= 1;

	int time = 0;
	bool flag = false;
	for (int i = 0; i < 3; i++)
	for (int j = 0; j < 3; j++)
	{
		int num;
		cin >> num;

		board[i][j] = num;

		//이미 찾을 수 있는 경우
		if (i == r && j == c && num == k)
			flag = true;
	}

	int row = 3;
	int col = 3;

	while (!flag)
	{
		time++;

		if (time > MAX)
		{
			cout << -1 << "\n";
			return 0;
		}
		vector<pair<int, int>> v[MAX];
		if (row >= col)
		{
			for (int i = 0; i < row; i++)
			{
				int cnt[MAX + 1] = { 0, };
				for (int j = 0; j < col; j++)
					cnt[board[i][j]]++;

				for (int j = 1; j <= MAX; j++)
				if (cnt[j])
					v[i].push_back({ cnt[j], j });
			}

			for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				board[i][j] = 0;

			for (int i = 0; i < row; i++)
				sort(v[i].begin(), v[i].end());

			for (int i = 0; i < row; i++)
			{
				int idx = 0;
				for (int j = 0; j < v[i].size(); j++)
				{
					board[i][idx++] = v[i][j].second;
					if (idx == MAX)
						break;
					board[i][idx++] = v[i][j].first;
					if (idx == MAX)
						break;
				}
				col = max(col, idx);
			}
		}
		else
		{
			for (int i = 0; i < col; i++)
			{
				int cnt[MAX + 1] = { 0, };
				for (int j = 0; j < row; j++)
					cnt[board[j][i]]++;

				for (int j = 1; j <= MAX; j++)
				if (cnt[j])
					v[i].push_back({ cnt[j], j });
			}

			for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				board[i][j] = 0;

			for (int i = 0; i < col; i++)
				sort(v[i].begin(), v[i].end());

			for (int i = 0; i < col; i++)
			{
				int idx = 0;
				for (int j = 0; j < v[i].size(); j++)
				{
					board[idx++][i] = v[i][j].second;
					if (idx == MAX)
						break;
					board[idx++][i] = v[i][j].first;
					if (idx == MAX)
						break;
				}
				row = max(row, idx);
			}
		}

		if (board[r][c] == k)
		{
			flag = true;
			break;
		}
	}
	cout << time << "\n";
	return 0;
}
