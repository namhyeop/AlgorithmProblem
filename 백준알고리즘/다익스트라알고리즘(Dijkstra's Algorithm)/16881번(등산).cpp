#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 100001;
const ll INF = 2300987654321;
ll height[MAX];
ll point_dist[MAX];
ll univ_dist[MAX];
vector<pair<int, int>> adj[MAX];

int n, m, d, e;
int main(void)
{
	
	fastio;
	cin >> n >> m >> d >> e;
	for (int i = 1; i <= n; i++)
	{
		cin >> height[i];
		point_dist[i] = univ_dist[i] = INF;
	}

	for (int i = 1; i <= m; i++)
	{
		int a, b, n;
		cin >> a >> b >> n;
		adj[a].push_back({ n, b });
		adj[b].push_back({ n, a });
	}

	auto dijkstra = [&](int start, ll visited[])
	{
		priority_queue < pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
		pq.push({ 0, start});
		visited[start] = 0;

		while (!pq.empty())
		{
			ll cost = pq.top().first;
			int cur = pq.top().second;
			pq.pop();

			if (cost > visited[cur])
				continue;

			for (auto next : adj[cur])
			{
				ll nextDist = next.first;
				int neighbor = next.second;

				if (height[cur] >= height[neighbor])
					continue;
				if (visited[neighbor] > cost + nextDist)
				{
					visited[neighbor] = cost + nextDist;
					pq.push({ visited[neighbor], neighbor });
				}
			}	
		}
	};

	dijkstra(1, point_dist);
	dijkstra(n, univ_dist);

	ll ans = -INF;
	for (int i = 2; i < n; i++)
	{
		if (point_dist[i] == INF || univ_dist[i] == INF)
			continue;
		ll cost = height[i] * e - d * (point_dist[i] + univ_dist[i]);
		ans = max(ans, cost);
	}
	if (ans == -INF)
		cout << "Impossible\n";
	else
		cout << ans << "\n";

	return 0;
}
