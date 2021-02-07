#include<bits/stdc++.h>
#define MAX 101
using namespace std;

int n, m, u, v, w;
int parent[MAX]; //가장 최단거리를 찾고 역추적을 위해 존재하는 배열
int dist[MAX];
vector<int> rev[MAX];//교차점들이 저장되어있는 변수
vector<pair<pair<int, int>, int>> road;
queue<int> q;
bool cycle; //사이클 유무
bool visited[MAX];//마찬가지로 역추적을 위해 존재하는 배열

void solve()
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < road.size(); j++)
		{
			int from = road[j].first.first;
			int to = road[j].first.second;
			int cost = road[j].second;

			if (dist[from] == INT_MAX)
				continue;
			if (dist[to] > dist[from] + cost)
			{
				if (i == n && visited[from])
				{
					cycle = true;
				}

				dist[to] = dist[from] + cost;
				parent[to] = from; //나중의 역추적을 통해 루트를 찾기 위한 체크
			}
		}
	}
}

void find_rout(int s)
{
	if (s == 1)
	{
		cout << s <<" ";
		return;
	}
	find_rout(parent[s]);
	cout << s << " ";
}

int main(int argc, char *argv[])
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		road.push_back({ { u, v }, -w }); //최단 거리를 구하기 위한 음수 표시
		rev[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
		dist[i] = INT_MAX;
	dist[1] = 0;
	parent[1] = 1;

	q.push(n);
	visited[n] = true;
	while (!q.empty())
	{
		int cidx = q.front();
		q.pop();

		for (int i = 0; i < rev[cidx].size(); i++)
		{
			int next = rev[cidx][i]; //n번 교차지점 부터 역추적 시작
			if (!visited[next])
			{
				visited[next] = true;
				q.push(next);
			}
		}
	}

	solve();

	if (cycle)
	{
		cout << -1 << "\n";
		return 0;
	}
	find_rout(n);

	return 0;
}
