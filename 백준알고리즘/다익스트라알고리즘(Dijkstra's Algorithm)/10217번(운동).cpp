#include<bits/stdc++.h>

using namespace std;

#define MAX 111

typedef struct info
{
	int next, money, distance;
}info;

int n, m, k, dist[MAX][10001];
vector<info> v[MAX];

//dist[정점][현재돈], 변수 안의 값은 거리를 의미
int digstra(int start)
{
	for (int i = 0; i < MAX; i++)
	{
		fill(dist[i], dist[i] + 10001, INT_MAX);
	}

	dist[start][0] = 0;
	priority_queue<pair<pair<int, int>, int>> pq;
	pq.push({ { 0, start }, 0 });

	while (!pq.empty())
	{
		int here = pq.top().first.second;
		int distance = -pq.top().first.first;
		int cost = pq.top().second;
		pq.pop();

		for (auto i : v[here])
		{
			int next = i.next;
			int next_cost = i.money;
 			int next_distance = i.distance;

			//주어진 비용보다 더 많은 금액을 쓸경우 X
			if (cost + next_cost > m)
				continue;

			int sum = cost + next_cost;

			if (dist[next][sum] > dist[here][cost] + next_distance)
			{
				dist[next][sum] = dist[here][cost] + next_distance;
				pq.push({ { -dist[next][sum], next }, sum });
			}
		}
	}
	int ret = INT_MAX;

	for (int i = 0; i <= m; i++)
	{
		if (dist[n][i] != INT_MAX)
		{
			ret = min(ret, dist[n][i]);
		}
	}

	return ret;
}

int main(int argc, char *argv[])
{
	int Testcase;
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		// n은 공항의 수,m은 지원비용, k는 티켓정보
		// u는 출발공항, v는 도착공항, c는 비용. d는 소요시간
		for (int i = 0; i < MAX; i++)
			v[i].clear();
	
		int u, gv, c, d;
		cin >> n >> m >> k;

		for (int i = 0; i < k; i++)
		{
			cin >> u >> gv >> c >> d;
			v[u].push_back({ gv, c, d });
		}

		int g = digstra(1);

		if (g == INT_MAX)
			cout << "Poor KCM\n";
		else
			cout << g << "\n";
	}
	return 0;
}
