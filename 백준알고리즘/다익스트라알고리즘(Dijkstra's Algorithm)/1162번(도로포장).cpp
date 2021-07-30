#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()
// [정점][도로포장기회]= 거리
using namespace std;
const int MAX = 10010;
const ll INF = LLONG_MAX;
ll dist[MAX][21];
vector<pair<ll, ll>> v[MAX];
int n, m, k;

int main(void)
{
	fastio;
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ c, b });
		v[b].push_back({ c, a });
	}

	fill(&dist[0][0], &dist[MAX-1][21], INF);

	dist[1][0] = 0;
	priority_queue<pair<pair<ll, ll>, int>, vector<pair<pair<ll, ll>, int>>, greater<pair<pair<ll, ll>, int>>> pq;
	pq.push({ { 0, 1 }, k });

	while (!pq.empty())
	{
		int cur = pq.top().first.second;
		ll cost = pq.top().first.first;
		int chance = pq.top().second;
		pq.pop();

		if (dist[cur][chance] < cost)
			continue;

		for (auto idx : v[cur])
		{
			int next = idx.second;
			ll nextCost = idx.first + cost;

			if (chance > 0)
			{
				if (dist[next][chance - 1] > cost)
				{
					dist[next][chance - 1] = cost;
					pq.push({ { dist[next][chance - 1], next }, chance - 1 });
				}
			}
			if (dist[next][chance] > nextCost)
			{
				dist[next][chance] = nextCost;
				pq.push({ { nextCost, next }, chance });
			}
		}
	}

	ll ret = LLONG_MAX;
	for (int i = 0; i <= k; i++)
	{
		ret = min(ret, dist[n][i]);
	}
	cout << ret << "\n";

	return 0;
}
