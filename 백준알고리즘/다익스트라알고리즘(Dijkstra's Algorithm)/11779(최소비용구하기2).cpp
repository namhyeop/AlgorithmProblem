#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 1001;
const int INF = 2123002300;
int n,m;
int trace[MAX];
vector<pair<int, int>> board[MAX];
int main(void)
{
	fastio;
	cin >> n >> m;

	auto dijkstra = [&](int start, int endnode) -> vector<int>
	{
		vector<int> dist(n + 1, INF);
		priority_queue<tuple<int, int,string>, vector<tuple<int, int,string>>, greater<tuple<int,int,string>>> pq;
		string info = to_string(start);
		pq.push(mtt( 0, start, info));
		dist[start] = 0;

		while (!pq.empty())
		{
			int cost = get<0>(pq.top());
			int cur = get<1>(pq.top());
			string info = get<2>(pq.top());
			pq.pop();

			if (dist[cur] < cost)
				continue;

			for (auto next : board[cur])
			{
				int neighbor = next.second;;
				int neighborCost = next.first + cost;
				string nextinfo = info + to_string(neighbor);

				if (dist[neighbor] > neighborCost)
				{
					trace[neighbor] = cur;
					dist[neighbor] = neighborCost;
					pq.push(mtt( neighborCost, neighbor, nextinfo));
				}
			}
		}
		return dist;
	};

	for (int i = 0; i < m; i++)
	{
		int stnode, ednode, d;
		cin >> stnode >> ednode >> d;
		board[stnode].push_back({ d, ednode });
	}

	int startNode, endNode;
	cin >> startNode >> endNode;
	vector<int> maxInfo = dijkstra(startNode, endNode);
	cout << maxInfo[endNode] << "\n";
	
	/*string passed; string은 외 안 되?
	int node = endNode;
	while (node)
	{
		passed+=to_string(node);
		node = trace[node];
	}

	cout << route.size() << "\n";
	for (int i = route.size() - 1; i >= 0; i--)
		cout << route[i] << " ";
	cout << "\n";*/

	vector<int> passed;
	int node = endNode;
	while (node)
	{
		passed.push_back(node);
		node = trace[node];
	}
	
	cout << passed.size() << "\n";
	for (int i = passed.size() - 1; i >= 0; i--)
		cout << passed[i] << " ";
	cout << "\n";
}
