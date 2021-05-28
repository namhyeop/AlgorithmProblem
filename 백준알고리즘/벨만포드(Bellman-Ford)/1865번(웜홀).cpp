#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int INF = 2123002300;
const int MAX = 501;
int t,n,m,w;
int dist[MAX];
int main(void)
{
	fastio;
	cin >> t;

	while (t--)
	{
		vector<pair<int, int>> board[MAX];
		bool cycleFlag = false;
		cin >> n >> m >> w;

		for (int i = 0; i < m; i++)
		{
			int stnode, ednode, d;
			cin >> stnode >> ednode >> d;
			board[stnode].push_back({ ednode, d });
			board[ednode].push_back({ stnode, d });
		}

		for (int i = 0; i < w; i++)
		{
			int stnode, ednode, d;
			cin >> stnode >> ednode >> d;
			board[stnode].push_back({ ednode, -1 * d });
		}
		fill(dist, dist + MAX, INF);

		for (int i = 0; i < n; i++)
		for (int j = 1; j <= n; j++)
		{
			for (auto next : board[j])
			{
				int neighbor = next.first;
				int neighborCost = next.second + dist[j];
				if (dist[neighbor] > neighborCost)
				{
					dist[neighbor] = neighborCost;
					if (i == n - 1)
						cycleFlag = true;
				}
			}
		}
		if (cycleFlag)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
}
