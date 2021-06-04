#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 10001;
const int INF = 23002300;
vector<tuple<int,int,int>> board;
int parent[MAX];

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b)
{
	if (get<2>(a) != get<2>(b))
		return get<2>(a) < get<2>(b);
}

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

	int v, e;
	cin >> v >> e;
	
	for (int i = 1; i <= v; i++)
		parent[i] = i;

	for (int i = 0; i < e; i++)
	{
		int prev, cur, d;
		cin >> prev >> cur >> d;
		board.push_back(mtt(prev, cur, d ));
	}

	sort(board.begin(), board.end(), cmp);

	int ret = 0;
	for (auto cur : board)
	{
		if (merge(get<0>(cur), get<1>(cur)))
		{
			ret += get<2>(cur);
		}
	}
	cout << ret;
}
