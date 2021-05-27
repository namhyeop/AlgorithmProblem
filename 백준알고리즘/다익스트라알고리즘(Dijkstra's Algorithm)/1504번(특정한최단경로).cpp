#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 801;
const int INF = 23002300;
vector<int> dist;
vector<pair<int, int>> board[MAX];
int n, e, esnode1, esnode2;
bool flag1, flag2;

int main(void)
{
	fastio;
	cin >> n >> e;

	auto dijkstra = [&](int start) ->vector<int>
	{
		dist.clear();
		dist.resize(n + 1, INF);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({ 0, start });
		dist[start] = 0;
		while (!pq.empty())
		{
			int cur = pq.top().second;
			int cost = pq.top().first;
			pq.pop();

			for (auto next : board[cur])
			{
				int neighborCost = next.first + cost;
				int neighbor = next.second;

				if (dist[neighbor] > neighborCost)
				{
					dist[neighbor] = neighborCost;
					pq.push({ neighborCost, neighbor });
				}
			}
		}
		return dist;
	};

	for (int i = 0; i < e; i++)
	{
		int stnode, ednode, d;
		cin >> stnode >> ednode >> d;
		board[stnode].push_back({ d, ednode });
		board[ednode].push_back({ d, stnode });
	}
	cin >> esnode1 >> esnode2;
	vector<int> stDj = dijkstra(1);
	vector<int> es1Dj = dijkstra(esnode1);
	vector<int> es2Dj = dijkstra(esnode2);
	
	int ret = min(stDj[esnode1] + es1Dj[esnode2] + es2Dj[n], stDj[esnode2] + es2Dj[esnode1] + es1Dj[n]);
	if (ret >= INF || ret < 0)
		cout << -1 << "\n";
	else
		cout << ret << "\n";
}
