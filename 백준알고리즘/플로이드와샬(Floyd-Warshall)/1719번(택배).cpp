#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 201;
const int INF = 123456789;
int n, m;
int dist[MAX][MAX];
int board[MAX][MAX];

int main(void)
{
	fastio;
	cin >> n >> m;

	fill(&dist[0][0], &dist[MAX][0], INF);
	for (int i = 1; i <= n; i++)
		dist[i][i] = 0;

	for (int i = 0; i < m; i++)
	{
		int node1, node2, value;
		cin >> node1 >> node2 >> value;

		dist[node1][node2] = value;
		dist[node2][node1] = value;
		board[node1][node2] = node2;
		board[node2][node1] = node1;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					board[i][j] = board[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				cout << "-" << " ";
			else
				cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}
