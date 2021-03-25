#include<bits/stdc++.h>

using namespace std;
const int MAX = 1001;
bool visited[MAX];

void DFS(int n, vector<int> tree[])
{
	visited[n] = true;

	for (int i = 0; i < tree[n].size(); i++)
	{
		int next = tree[n][i];
		if (!visited[next])
		{	
			DFS(next, tree);
		}
	}
}

int main()
{
	int Testcase;
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		fill(visited, visited + MAX, 0);
		vector<int> tree[MAX];
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			int tmp;
			cin >> tmp;
			tree[i].push_back(tmp);
		}

		int ret = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
			{
				DFS(i, tree);
				ret++;
			}
		}
		cout << ret << "\n";
	}
}
