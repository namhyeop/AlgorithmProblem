//DFS + 다익스트라 문제
//1.다익스트라로 최단경로를 기록한다.
//2.최단경로들을 지운다.
//3.다익스트라로 가능한 경로 중 가장 빠른 길을 탐색한다.

#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 501;
int dist[MAX];
vector<int> parent[MAX];
bool isShortest[MAX][MAX];
int n, m;
int stNode, edNode;

int main(void)
{
	fastio;
	
	function<void(int, int)> DFS = [&](int start, int end)
	{
		if (start == end)
			return;
		int len = parent[end].size();
		for (int i = 0; i < len; i++)
		{
			int next = parent[end][i];
			if (!isShortest[next][end]) //end지점 부터 최단경로의 노드들을 전부 체크해주는 과정, 이후 다이젝스트라에서 이 경로를 제외하고 최단거리를 구함
			{
				isShortest[next][end] = true;
				DFS(start, next);
			}
		}
	};

	auto dijkstra = [&](vector<pair<int,int>> adjList[], int start, int end)
	{
		fill(dist, dist + MAX, INT_MAX);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		dist[start] = 0;
		pq.push({ 0, start });

		while (!pq.empty())
		{
			int cost = pq.top().first;
			int cur = pq.top().second;
			pq.pop();

			//현재 비교할 노드의 값이 노드의 dist의 값보다 크다면 비교 의미 X, 가지치기 수행 
			if (cost > dist[cur])
				continue;

			for (auto next : adjList[cur])
			{
				int neighborCost = next.first + cost;
				int neighbor = next.second;
			
				//최단경로 간선이면 continue - 2번째 다이젝스트라에서 사용되는 로직
				if (isShortest[cur][neighbor])
					continue;

				//모든 최단경로를 검색해야하므로 충첩되는 최단거리도 추가해준다.
				if (dist[neighbor] == neighborCost)
					parent[neighbor].push_back(cur);
				//cost가 더 작을때 갱신
				else if (dist[neighbor] > neighborCost)
				{
					dist[neighbor] = neighborCost;
					
					//새로운 최단거리의 parent 생겼으므로 초기화
					parent[neighbor].clear();
					parent[neighbor].push_back(cur);
					pq.push({neighborCost, neighbor});
				}
			}
		}
	};

	while (1)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		cin >> stNode >> edNode;
		memset(isShortest, false, sizeof isShortest);
		vector<pair<int, int>> adjList[MAX];
		for (int i = 0; i < MAX; i++)
			parent[i].clear();

		for (int i = 0; i < m; i++)
		{
			int u, v, p;
			cin >> u >> v >> p;
			adjList[u].push_back({ p, v });
		}
		dijkstra(adjList, stNode, edNode);
		DFS(stNode, edNode);
		dijkstra(adjList, stNode, edNode);

		if (dist[edNode] == INT_MAX)
			cout << -1 << "\n";
		else
			cout << dist[edNode] << "\n";
	}
	return 0;
}
