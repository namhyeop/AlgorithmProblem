#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 1e6 + 1;
int n, m;
int parent[MAX];

int find(int p)
{
	if (parent[p] == p)
		return p;
	else
		return parent[p] = find(parent[p]);
}

void merge(int p, int c)
{
	p = find(p);
	c = find(c);

	parent[c] = p;
}

int main(void)
{
	fastio;
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		parent[i] = i;

	while (m--)
	{
		int cmd, a, b;
		cin >> cmd >> a >> b;
		if (cmd == 0)
		{
			merge(a, b);
		}
		else
		{
			int p1 = find(a);
			int p2 = find(b);
			if (p1 == p2)
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
	}
	return 0;
}
