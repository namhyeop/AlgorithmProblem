#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 1001;
int n, m;
int parent[MAX];
vector<pair<int, int>> cost[MAX * 10];
int ret;
bool flag;

int find(int c)
{
	if (parent[c] < 0) 
		return c;
	else
		return parent[c] = find(parent[c]);
}

void merge(int p, int c)
{
	p = find(p);
	c = find(c);
	if (p == c)
		return;
	parent[c] += parent[p];
	parent[p] = c;
}

int main(void)
{
	fastio;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		parent[i] = -1;
	
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		//가중치, 목적지 노드
		cost[c].push_back({ a, b });
	}

	for (int i = 0; i < 10001; i++) //작은 비용부터 돌기에 정렬이 필요없음
	{
		if (flag)
			break;
		if (cost[i].empty())
			continue;
		for (int j = 0; j < cost[i].size(); j++)
		{
			if (flag)
				break;
			int a = cost[i][j].first;
			int b = cost[i][j].second;
			if (find(a) == find(b))
				continue;
			merge(a, b);
			ret += i; //i는 cost를 의미
			if (parent[b] == -n)
				flag = true;
		}
	}
	cout << ret << "\n";
}
