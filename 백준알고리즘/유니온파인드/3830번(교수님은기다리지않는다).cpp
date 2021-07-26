#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 1e5 + 1;
int n, m;
int parent[MAX];
ll dist[MAX];

int update(int x)
{
	if (parent[x] == x)
		return x;
	int r = update(parent[x]);
	dist[x] += dist[parent[x]];
	return parent[x] = r;
}

void merge(int a, int b, int diff)
{
	int root_a = parent[a];
	int root_b = parent[b];
	if (root_a == root_b)
		return;

	int newDist = dist[a] + diff;
	int originDist = dist[b];
	
	parent[root_b] = root_a;
	dist[root_b] = newDist - originDist;
}
int main(void)
{
	fastio;

	while (1)
	{
		fill(parent, parent + MAX, 0);
		fill(dist, dist + MAX, 0);
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;

		for (int i = 1; i <= n; i++)
		{
			parent[i] = i;
			dist[i] = 0;
		}

		while (m--)
		{
			int a, b;
			char cmd;
			cin >> cmd;
			cin >> a >> b;
			update(a);
			update(b);
			if (cmd == '!')
			{
				int c;
				cin >> c;
				merge(a, b, c);
			}
			else if (cmd == '?')
			{
				if (parent[a] == parent[b])
					cout << dist[b] - dist[a] << "\n";
				else
				if (parent[a] == parent[b])
					cout << dist[b] - dist[a] << "\n";
				else
					cout << "UNKNOWN" << "\n";
			}
		}
	}
	return 0;
}
