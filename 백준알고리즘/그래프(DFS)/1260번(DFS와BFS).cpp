#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>

using namespace std;
#define MAX 1001
int N;
int M;
int V;
vector<int> adj[MAX];
vector<int> ret;
bool visited[MAX];

void print(void)
{
	for (int i = 0; i < ret.size(); i++)
	{
		if (i != ret.size() - 1)
			cout << ret[i] << " ";
		else
			cout << ret[i];
	}
}

void dfs(int here)
{
	visited[here] = true;
	ret.push_back(here);
	for (int i = 0; i < adj[here].size(); i++)
	{
		int next = adj[here][i];
		if (!visited[next])
			dfs(next);
	}
}

void bfs(int here)
{
	queue<int> q;
	q.push(here);
	visited[here] = true;

	while (!q.empty())
	{
		int node = q.front();
		ret.push_back(node);
		q.pop();

		for (int i = 0; i < adj[node].size(); i++)
		{
			int nextNode = adj[node][i];
			if (!visited[nextNode])
			{
				q.push(nextNode);
				visited[nextNode] = true;
			}
		}
	}
}

int main(int argc, char *argv[])
{
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int node1;
		int node2;
		cin >> node1 >> node2;
		adj[node1].push_back(node2);
		adj[node2].push_back(node1);
	}

	for (int i = 0; i < N + 1; i++)
	{
		sort(adj[i].begin(), adj[i].end());
	}


	dfs(V);
	print();
	cout << "\n";

	memset(visited, false, sizeof(visited));
	ret.clear();

	bfs(V);
	print();
	cout << "\n";

	return 0;
}
