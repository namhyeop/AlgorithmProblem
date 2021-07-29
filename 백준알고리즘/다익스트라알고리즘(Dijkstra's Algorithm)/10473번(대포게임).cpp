//거리 = 속도 * 시간
//시간 = 거리 / 속도

#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 101;
const double INF = 123456789.0;
vector<pair<double, int>> adj[MAX];
vector<pair<double, double>> arr;
double dist[MAX];

int main(void)
{
	fastio;
	pair<double, double> start, end;
	cin >> start.first >> start.second;
	cin >> end.first >> end.second;

	int n;
	cin >> n;
	arr.resize(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> arr[i].first >> arr[i].second;

	auto getdist = [&](pair<double, double> a, pair<double, double> b) -> double
	{
		double tmp1 = b.first - a.first;
		double tmp2 = b.second - a.second;
		return sqrt(tmp1 * tmp1 + tmp2 * tmp2);
	};

	//시작점에서 대포 사이와의 간선 연결
	for (int i = 1; i <= n; i++)
	{
		adj[0].push_back({ getdist(start, arr[i]) / 5.0 , i });
	}

	//시작점에서 끝점 과의 간선 열결
	adj[0].push_back({ getdist(start, end) / 5.0 , n + 1 });

	//대포와 대포사이의 간선 연결
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	{
		if (i == j) //
			continue;
		adj[i].push_back({ getdist(arr[i], arr[j]) / 5.0 , j });
		adj[i].push_back({ 2.0 + fabs(getdist(arr[i], arr[j]) - 50.0) / 5.0 , j });
	}

	//대포와 끝점 간선 연결
	for (int i = 1; i <= n; i++)
	{
		adj[i].push_back({ getdist(arr[i], end) / 5.0, n + 1 });
		adj[i].push_back({ 2.0 + fabs(getdist(arr[i], end) - 50.0) / 5.0, n + 1 });
	}

	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
	pq.push({ 0.0, 0 });

	for (int i = 0; i <= n + 1; i++)
		dist[i] = INF;
	
	while (!pq.empty())
	{
		double cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (cost > dist[cur])
			continue;

		for (auto next : adj[cur])
		{
			double neighborCost = cost + next.first;
			int neighbor = next.second;

			if (dist[neighbor] > neighborCost)
			{
				dist[neighbor] = neighborCost;
				pq.push({ neighborCost, neighbor });
			}
		}
	}

	cout << fixed;
	cout.precision(6);
	cout << dist[n + 1] << "\n";
}
