#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int INF = 23002300;
const int MAX = 801;
vector<pair<int,int>> board[MAX];
vector<int> dist;
int n, e;
int main(void)
{
	fastio;
	auto dijkstra = [&](int start) -> vector<int>
	{
		vector<int> dist(n + 1, INF);
		dist[start] = 0;
		priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
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
				int nextCost = cost + next.first;
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

	cin >> n >> e;

	for (int i = 0; i < e; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		board[a].push_back({ w, b });
		board[b].push_back({ w, a });
	}
	
	int stnode1, stnode2;
	cin >> stnode1 >> stnode2;
	vector<int> stArr = dijkstra(1); //1에서 출발 할 경우 생기는 최소 거리의 값 배열, starr[node1]은 1에서 출발해서 각 노드들 까지의 최소값 
	vector<int> st1Arr = dijkstra(stnode1);//stnod1에서 출발 할 경우 생기는 최소 거리값 배열,starr1[stnode2]은 stnod2에서 출발하여 각 노드들 까지의 최소값, steArr1[n] == stnode1 -> n을 의미 
	vector<int> st2Arr = dijkstra(stnode2);//stnod2에서 출발 할 경우 생기는 최소 거리값 배열,starr2[b]은 b에서 출발하여 각 노드들 까지의 최소값, steArr2[n] == stnode2 -> n을 의미  
	int ret = min(stArr[stnode1] + st1Arr[stnode2] + st2Arr[n], stArr[stnode2] + st2Arr[stnode1] + st1Arr[n]);
	if (ret >= INF || ret < 0)
		cout << -1 << "\n";
	else
		cout << ret << "\n";
	return 0;
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
*/
