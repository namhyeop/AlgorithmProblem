#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 222;
int n, m;
int parent[MAX];
int path[1111];

int find(int c)
{
	if (parent[c] == c)
		return c;
	else
		return parent[c] = find(parent[c]);
}

void merge(int p, int c)
{
	p = find(p);
	c = find(c);

	if (p > c)
	{
		parent[c] = p;
	}
	else
	{
		parent[p] = c;
	}
}
int main(void)
{
	fastio;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	{
		int cmd;
		cin >> cmd;
		if (cmd)
		{
			merge(i, j);
		}
	}

	for (int i = 1; i <= m; i++)
		cin >> path[i];

	bool Flag = false;
	for (int i = 1; i < m; i++)
	{
		if (find(path[i]) != find(path[i + 1]))
		{
			Flag = true;
			break;
		}
	}

	if (!Flag)
		cout << "YES" << "\n";
	else
		cout << "NO" << "\n";
}
