#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

#define INF 1234567899
const int MAXN = 1001;
const int MAXK = 101;
vector<pair<int, int>> edges[MAXN];
int visited[MAXN];
int dist[MAXK][MAXN]; // [i][j] = i번째 최단경로로 j방문하는 길이 

int n, m, k;
int main(void)
{
	fastio;
	cin >> n >> m >> k;
	int discovered = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
			dist[j][i] = INF;
	}

	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edges[u].push_back({ w, v });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, 1 });
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		//문제에서 원하는 k번째 최단경로를 다 구한경우, 2번째를 구해야하는데 이미 3번째까지 구한거면 더 이상의 연산의 의미 X
		if (visited[cur] >= k)
			continue;

		int cnt = ++visited[cur];
		dist[cnt][cur] = cost;
		
		if (cnt == k)
			discovered++;
		if (discovered == n)
			break;
		for (auto next : edges[cur])
		{
			int nextCost = next.first;
			int neighbor = next.second;
			pq.push({ dist[cnt][cur] + nextCost, neighbor });
		}
	}

	for (int i = 1; i <= n; i++)
	{ 
		if (dist[k][i] == INF)
			cout << "-1" << "\n";
		else
			cout << dist[k][i] << "\n";
	}
}
