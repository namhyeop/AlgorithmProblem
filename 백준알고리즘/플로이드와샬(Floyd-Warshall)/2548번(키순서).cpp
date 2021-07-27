#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 501;
const int INF = 1e6;
int n, m;
int dist[MAX][MAX];

int main(void)
{
	fastio;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		dist[i][j] = INF;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;
	}

	for (int k = 1; k <= n; k++)
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] != INF || dist[j][i] != INF)
				cnt++;
		}
		if (cnt == n - 1)
			ans++;
	}
	cout << ans << "\n";
}
