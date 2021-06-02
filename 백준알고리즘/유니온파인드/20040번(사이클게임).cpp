#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 5e5 + 1;
int n, m;
int parent[MAX];

int find(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

bool merge(int p, int c)
{
	p = find(p);
	c = find(c);

	if (p == c)
		return false;

	parent[p] = c;

	return true;
}

int main(void)
{
	fastio;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		parent[i] = i;

	bool flag = false;
	for (int i = 0; i < m; i++)
	{
		int p, c;
		cin >> p >> c;

		if (!merge(p, c))
		{
			cout << i + 1 << "\n";
			flag = true;
			break;
		}
	}

	if (!flag)
		cout << "0\n";
	return 0;
}
