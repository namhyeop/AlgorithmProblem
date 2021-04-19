#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;
const int MAX = 101;
const int INF = 123456789;
int dist[MAX][MAX];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		dist[i][j] = i == j ? 0 : INF;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		dist[a - 1][b - 1] = min(dist[a - 1][b - 1], c);
	}

	for (int k = 0; k < n; k++)
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dist[i][j] >= INF)
				dist[i][j] = 0;
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}

