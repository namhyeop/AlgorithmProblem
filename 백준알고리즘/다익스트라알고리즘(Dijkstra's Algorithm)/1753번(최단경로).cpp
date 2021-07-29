#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

const int MAX = 1001;
const int INF = 123456789;
vector<pair<int,int>> board[MAX];
vector<int> dist;
int n, m, x;

int main(void)
{
	fastio;
	cin >> n >> m >> x;

	for (int i = 0; i < m; i++)
	{
		int st, ed, c;
		cin >> st >> ed >> c;
		board[st].push_back({ c, ed });
	}

	auto dijkstra = [&](int start) -> vector<int>
	{
		dist.clear();
		dist.resize(n + 1, INF);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		dist[start] = 0;
		pq.push({ 0, start });

		while (!pq.empty())
		{
			int cost = pq.top().first;
			int cur = pq.top().second;
			pq.pop();

			if (dist[cur] < cost)
				continue;

			for (auto next : board[cur])
			{
				int nextCost = next.first + cost;
				int neighbor = next.second;
				if (dist[neighbor] > nextCost)
				{
					dist[neighbor] = nextCost;
					pq.push({ nextCost, neighbor });
				}
			}
		}
		return dist;
	};

	int ret = 0;
	vector<int> back = dijkstra(x);
	for (int i = 1; i <= n; i++)
	{
		if (i == x)
			continue;
		vector<int> go = dijkstra(i);
		ret = max(ret, go[x] + back[i]);
	}
	cout << ret << "\n";
}

/*
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
const int MAX = 20001;
vector<int> DIST;
int V, E, K;
vector<pair<int, int>> board[MAX];

int main(void)
{
	fastio;

	auto dijkstra = [&](int start) -> void
	{
		DIST.resize(V + 1, INF);
		priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({ 0, start });
		DIST[start] = 0;

		while (!pq.empty())
		{
			int cost = pq.top().first;
			int cur = pq.top().second;
			pq.pop();

			for (auto next : board[cur])
			{
				int neighbor = next.second;
				int neighborCost = next.first + cost;

				if (DIST[neighbor] > neighborCost)
				{
					DIST[neighbor] = neighborCost;
					pq.push({ neighborCost, neighbor });
				}
			}
		}
	};

	cin >> V >> E >> K;
	
	for (int i = 0; i < E; i++)
	{
		int stnode, ednode, d;
		cin >> stnode >> ednode >> d;
		board[stnode].push_back({ d, ednode });
	}

	dijkstra(K);

	for (int i = 1; i <= V; i++)
	{
		if (DIST[i] == INF)
		{
			cout << "INF" << "\n";
			continue;
		}
		cout << DIST[i] << "\n";
	}
	return 0;
}
*/
