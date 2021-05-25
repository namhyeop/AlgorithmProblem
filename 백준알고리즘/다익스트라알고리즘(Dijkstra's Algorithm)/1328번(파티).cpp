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

vector<int> dijkstra(int start, int vertex)
{
	vector<int> distance(vertex, INF);
	distance[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (distance[cur] < cost) //현재 비용이 저장되어있는 길이보다 크면 갱신할 필요가 없으므로 넘겨준다.
			continue;

		for (int i = 0; i < board[cur].size(); i++) //해당 노드의 인접한 노드들의 거리를 갱신해주는 과정
		{
			int adjacent = board[cur][i].first; 
			int adjacentCost = cost + board[cur][i].second;
			
			if (distance[adjacent] > adjacentCost)
			{
				distance[adjacent] = adjacentCost;
				pq.push({adjacentCost, adjacent});
			}
		}
	}
	return distance;
}

int main(void)
{
	fastio;
	cin >> n >> m >> x;

	for (int i = 0; i < m; i++)
	{
		int stnode, ednode, cost;
		cin >> stnode >> ednode >> cost;
		board[stnode].push_back({ ednode, cost });
	}

	int ret = INT_MIN;

	for (int i = 1; i <= n; i++)
	{

		vector<int> go = dijkstra(i, n + 1);
		vector<int> back = dijkstra(x, n + 1);

		//갈수없는경우
		if (go[x] + back[i] >= INF || go[x] + back[i] < 0)
			continue;

		ret = max(ret, go[x] + back[i]);
	}
	cout << ret << "\n";
	return 0;
}
