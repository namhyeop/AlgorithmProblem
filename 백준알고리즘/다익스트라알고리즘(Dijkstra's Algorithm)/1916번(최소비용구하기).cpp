#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const ll INF = LLONG_MAX;
const int MAX = 1001;
vector<ll> DIST;
vector<pair<int, int>> board[MAX];

int n, m;
int main(void)
{
	fastio;
	cin >> n >> m;

	auto dijkstra = [&](int start)
	{
		DIST.resize(n + 1, INF);
		priority_queue < pair<ll, ll>, vector < pair<ll, ll >> , greater<pair<ll, ll>>> pq;
		pq.push({ 0, start });
		DIST[start] = 0;
		
		while (!pq.empty())
		{
			ll cost = pq.top().first;
			ll cur = pq.top().second;
			pq.pop();

			for (auto next : board[cur])
			{
				ll neighborCost = next.first + cost;
				ll neighbor = next.second;

				if (DIST[neighbor] > neighborCost)
				{
					DIST[neighbor] = neighborCost;
					pq.push({ neighborCost, neighbor });
				}
			}
		}
	};

	for (int i = 0; i < m; i++)
	{
		int stnode, ednode, d;
		cin >> stnode >> ednode >> d;
		board[stnode].push_back({ d, ednode });
	}
	
	int s, e;
	cin >> s >> e;
	dijkstra(s);
	cout << DIST[e] << "\n";
}
