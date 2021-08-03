#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

const int MAX = 1005;
int parent[MAX];
int p, w;
int c, v;

struct info
{
	int start, end,width;
	info(int start, int end, int width) : start(start), end(end),width(width) {};
};

bool operator < (info a, info b)
{
	return a.width > b.width;
}

vector<info> edge;

int find(int c)
{
	if (parent[c] == c)
		return c;
	else
		return parent[c] = find(parent[c]);
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
	
	cin >> p >> w >> c >> v;

	for (int i = 0; i < p; i++)
		parent[i] = i;

	for (int i = 0; i < w; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;
		edge.push_back({ s, e, w });
	}
	sort(edge.begin(), edge.end());

	for (int i = 0; i < w; i++)
	{
		if (merge(edge[i].start, edge[i].end))
		{
			if (find(c) == find(v))
			{
				cout << edge[i].width;
				break;
			}
		}
	}
}
