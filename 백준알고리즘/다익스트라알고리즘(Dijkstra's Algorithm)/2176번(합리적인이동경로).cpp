#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int INF = 23002300;
const int MAX = 1001;
int n, m, x;
vector<pair<int, int>> board[MAX];


vector<int> dijkstra(int node)
{
	vector<int> costArr(n+1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, node });
	costArr[node] = 0;

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int curnode = pq.top().second;
		pq.pop();

		if (costArr[curnode] < cost)
			continue;
		for (int i = 0; i < board[curnode].size(); i++)
		{
			int neighbor = board[curnode][i].first;
			int neighborcost = cost + board[curnode][i].second;

			if (costArr[neighbor] > neighborcost)
			{
				costArr[neighbor] = neighborcost;
				pq.push({ neighborcost, neighbor });
			}
		}
	}

	return costArr;
}
int main(void)
{
	fastio;

	cin >> n >> m >> x;

	for (int i = 0; i < m; i++)
	{
		int stnode, ednode, d;
		cin >> stnode >> ednode >> d;
		board[stnode].push_back({ ednode, d });
	}

	int ret = INT_MIN;
	vector<int> back = dijkstra(x);
	for (int i = 1; i <= n; i++)
	{
		vector<int> go = dijkstra(i);
		if (go[x] + back[i] >= INF || go[x] + back[i] < 0)
			continue;
		ret = max(ret, go[x] + back[i]);
	}

	cout << ret << "\n";
}

/*
#include<bits/stdc++.h>
#define MAX 1001
using namespace std;

int N,M;
int dp[MAX];
int cost[MAX];
vector<pair<int, int>> v[MAX];
priority_queue<pair<int, int>> pq;

int main(int argc, char *argv)
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int node1, node2, value;
		cin >> node1 >> node2 >> value;
		v[node1].push_back({ node2, value });
		v[node2].push_back({ node1, value });
	}
	fill(cost + 1, cost + 1 + N, INT_MAX);

	cost[2] = 0;
	dp[2] = 1;
	pq.push({ 0, 2 });

	while (pq.empty())
	{
		//pq의 first는 길이
		//pq의 second는 노드
		int h = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();

		if (cost[h] != distance)
			continue;

		//입력값과 연관
		//idx.first == node
		//idx.second == length
		for (auto idx : v[h])
		{
			int idxDistance = idx.second + distance;
			if (idxDistance < cost[idx.first])
			{
				cost[idx.first] = idxDistance;
				pq.push({ -idxDistance, idx.first });
			}
			if (cost[idx.first] < distance)
				dp[h] += dp[idx.first];
		}
	}

	cout << dp[1] << "\n";

	return 0;
}
*/
