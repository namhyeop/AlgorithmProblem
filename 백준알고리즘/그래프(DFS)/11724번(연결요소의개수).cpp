#include<iostream>
#include<vector>
using namespace std;

const int MAX = 1000 + 1;
vector<int> adj[MAX];
bool visited[MAX];
int m;
int n;

void dfs(int node)
{
	visited[node] = true;
	for (int i = 0; i < adj[node].size(); i++)
	{
		int next = adj[node][i];
		//node에 연결된 다른 정점을 모두 방문
		//이미 방문했다면 방문하지 않는다.
		if (!visited[next])
			dfs(next);
	}
}
int main(int argc, char *argv[])
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u;
		int v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			dfs(i);
			ret++;
		}

	}
	cout << ret << "\n";
	return 0;
}
