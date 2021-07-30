#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 1010;
const int INF = 123456789;
int parent[MAX];
int dist[MAX];
int n, m;
vector<pair<int, int>> v[MAX];

int main(void)
{
	fastio;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ c, b });
		v[b].push_back({ c, a });
	}

	fill(dist, dist + MAX, INF);
	auto dijkstra = [&](int start)
	{
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({ 0, start });
		dist[start] = 0;

		while (!pq.empty())
		{
			int cost = pq.top().first;
			int cur = pq.top().second;
			pq.pop();

			if (dist[cur] < cost)
				continue;

			for (auto idx : v[cur])
			{
				int neighbor = idx.second;
				int nextCost = idx.first;
				
				if (dist[neighbor] > nextCost + cost)
				{
					dist[neighbor] = nextCost + cost;
					parent[neighbor] = cur;
					pq.push({ dist[neighbor], neighbor });
				}
			}
		}
	};

	dijkstra(1);
	cout << n - 1 << "\n";
	for (int i = 2; i <= n; i++)
	{
		cout << parent[i] << " " << i <<"\n";
	}
}
