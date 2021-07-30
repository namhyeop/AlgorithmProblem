#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

const int MAX = 102;
const int INF = 987654321;

struct info
{
	int wt;
	int next;
	int cost;
};

//[방문정점][비용] = 소요시간
int dist[MAX][10001];
vector<info> adj[MAX];
int n, m, k;
int testcase;
int main(void)
{
	fastio;
	cin >> testcase;

	while (testcase--)
	{
		auto dijkestra = [&](int start) -> int
		{
			priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
			pq.push(make_tuple(0, start, 0));
			dist[start][0] = 0;

			while (!pq.empty())
			{
				int wt = get<0>(pq.top());
				int cur = get<1>(pq.top());
				int cost = get<2>(pq.top());
				pq.pop();

				if (dist[cur][cost] < wt)
					continue;

				for (auto next : adj[cur])
				{
					int nextWt = next.wt;
					int neighbor = next.next;
					int nextCost = next.cost;

					if (cost + nextCost > m)
						continue;

					int sum = cost + nextCost;
					if (dist[neighbor][sum] > dist[cur][cost] + nextWt)
					{
						dist[neighbor][sum] = dist[cur][cost] + nextWt;
						pq.push(make_tuple(dist[neighbor][sum], neighbor, sum));
					}
				}
			}

			int ret = INT_MAX;
			for (int i = 0; i <= m; i++)
			{
				if (dist[n][i] != INF)
					ret = min(ret, dist[n][i]);
			}
			return ret;
		};
		cin >> n >> m >> k;

		for (int i = 0; i < n + 1; i++)
			adj[i].clear();
		fill(&dist[0][0], &dist[MAX - 1][1001], INF);
		for (int i = 0; i < k; i++)
		{
			int u, v, c, d;
			cin >> u >> v >> c >> d;
			adj[u].push_back({ d, v, c });
		}

		int ret = dijkestra(1);
		if (ret == INT_MAX)
			cout << "Poor KCM\n";
		else
			cout << ret << "\n";
	}
}
