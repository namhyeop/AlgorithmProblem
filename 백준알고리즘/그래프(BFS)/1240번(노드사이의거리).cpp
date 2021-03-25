#include<bits/stdc++.h>

using namespace std;
const int MAX = 1001;
int n, m;
vector<int> tree[MAX];
int board[MAX][MAX];
bool visited[MAX];
int start, finish;

int search()
{
	queue<pair<int, int>> q;
	q.push({ start, 0 });
	visited[start] = true;

	while (!q.empty())
	{
		int cur = q.front().first;
		int cost = q.front().second;
		q.pop();

		if (cur == finish)
			return cost;

		for (int i = 0; i < tree[cur].size(); i++)
		{
			if (!visited[tree[cur][i]])
			{
				q.push({ tree[cur][i], cost + board[cur][tree[cur][i]] });
				visited[tree[cur][i]] = true;
			}
		}
	}
}
int main()
{
	cin >> n >> m;

	for (int i = 0; i < n - 1; i++)
	{
		int tmp1, tmp2, value;
		cin >> tmp1 >> tmp2 >> value;

		tree[tmp1].push_back(tmp2);
		tree[tmp2].push_back(tmp1);
		board[tmp1][tmp2] = value;
		board[tmp2][tmp1] = value;
	}

	for (int j = 0; j < m; j++)
	{
		cin >> start >> finish;
		memset(visited, false, sizeof(visited));
		cout << search() << "\n";
	}
	return 0;
}
