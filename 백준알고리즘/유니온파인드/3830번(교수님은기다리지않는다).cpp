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
int parent[MAX];
ll dist[MAX];

int find(int id)
{
	if (parent[id] == id)
		return id;
	//트리로 만들어져있느 상태에서 위에서 root가 아닐때까지 앞에 있는 pid값(parent[id]))을 구해서 dist를 갱신시킨다. 
	int pid = find(parent[id]);
	dist[id] += dist[parent[id]];
	return parent[id] = pid;
}

void merge(int a, int b, ll diff)
{
	int pa = find(a);
	int pb = find(b);

	if (pa == pb)
		return;
	//parent를 변경하고, 무게 차이를 갱신
	dist[pb] = dist[a] - dist[b] + diff;
	parent[pb] = pa;
	return;
}

int n, m;
int main(void)
{
	fastio;
	while (1)
	{
		fill(dist, dist + MAX, 0);
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		
		for (int i = 1; i <= n; i++)
			parent[i] = i;

		for (int i = 0; i < m; i++)
		{
			char cmd;
			cin >> cmd;

			if (cmd == '!')
			{
				int a, b, c;
				cin >> a >> b >> c;
				merge(a, b, c);
			}
			else if (cmd == '?')
			{
				int a, b;
				cin >> a >> b;
				//무게를 판단할 수 없는 경우
				if (find(a) != find(b))
					cout << "UNKNOWN" << "\n";
				//무게 판단이 가능한 경우
				else
					cout << dist[b] - dist[a] << "\n";
			}
		}
	}
}
/*
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
*/
