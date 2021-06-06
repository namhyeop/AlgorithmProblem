#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 32001;
int indegree[MAX];
vector<int> board[MAX];
priority_queue<int, vector<int>, greater<int>> first;
int n, m;

int main(void)
{
	fastio;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int prev, cur;
		cin >> prev >> cur;
		board[prev].push_back(cur);
		indegree[cur]++;
	}

	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
			first.push(i);
	}

	while (!first.empty())
	{
		int cur = first.top();
		first.pop();

		cout << cur << "\n";
		for (int next : board[cur])
		{
			if (--indegree[next] == 0)
				first.push(next);
		}
	}
	return 0;
}

