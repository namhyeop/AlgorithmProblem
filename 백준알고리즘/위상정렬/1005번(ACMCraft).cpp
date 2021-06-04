#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

const int MAX = 1005;
int t,w;
int timeArr[MAX];
int ret[MAX];
int pre[MAX];

int main(void)
{
	fastio;
	cin >> t;

	while (t--)
	{
		int n, m;
		cin >> n >> m;
		fill(ret, ret + MAX, 0);
		fill(pre, pre + MAX, 0);
		vector<int> board[MAX];
		for (int i = 1; i <= n; i++)
			cin >> timeArr[i];

		for (int i = 0; i < m; i++)
		{
			int p, c;
			cin >> p >> c;
			board[p].push_back(c);
			pre[c]++;
		}
		cin >> w;
		queue<int> q;
		for (int i = 1; i <= n; i++)
		{
			if (!pre[i])
				q.push(i);
		}

		while (pre[w] > 0)
		{
			int cur = q.front();
			q.pop();

			for (int next : board[cur])
			{
				ret[next] = max(ret[next], ret[cur] + timeArr[cur]);
				if (--pre[next] == 0)
					q.push(next);
			}
		}
		cout << ret[w] + timeArr[w] << "\n";
	}
	return 0;
}
