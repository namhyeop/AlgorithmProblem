#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<climits>

using namespace std;

int main(int argc, char *argv[])
{
	int n, m;
	long long dist[500];
	cin >> n >> m;
	vector<pair<int, int>> adj[500];

	for (int i = 0; i < m; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		adj[A - 1].push_back({ B - 1, C });
	}
	bool minusCycle = false;
	fill(dist, dist + n, INT_MAX);
	dist[0] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (auto &p : adj[j])
			{
				int next = p.first;
				int d = p.second;
				if (dist[j] != INT_MAX && dist[next] > dist[j] + d)
				{
					dist[next] = dist[j] + d;
					if (i == n - 1)
						minusCycle = true; //마지막 경우에 사이클이 발생할 경우 
				}
			}
		}
	}
	if (minusCycle)
		cout << "-1" << "\n";
	else
	{
		for (int i = 1; i < n; i++)
		{
			if (dist[i] != INT_MAX)
				cout << dist[i] <<"\n";
			else
				cout << -1 << "\n";
		}
	}
}
