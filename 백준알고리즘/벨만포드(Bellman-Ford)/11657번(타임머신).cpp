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
const ll INF = 1e19;
int n, m;
vector<pair<int, int>> board[MAX];
ll dist[MAX];
int main(void)
{
	fastio;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		board[a-1].push_back({ c, b-1 });
	}

	bool cycleFlag = false;
	fill(dist, dist + n, INF);
	dist[0] = 0;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		for (auto cur : board[j])
		{
			int cost = cur.first;
			int neighbor = cur.second;
			if (dist[j] != INF && dist[neighbor] > cost + dist[j])
			{
				dist[neighbor] = cost + dist[j];
				
				//순회를 다돌고 한 번더. 즉 N번째 순회에 값이 변경되면 사이클이 존재한다.
				if (i == n - 1)
					cycleFlag = true;
			}
		}
	}


	if (cycleFlag)
		cout << -1 << "\n";
	else
	{
		for (int i = 1; i < n; i++)
		{
			if (dist[i] != INF)
				cout << dist[i] << "\n";
			else
				cout << -1 << "\n";
		}
	}
		
}
/*
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<climits>

using namespace std;

int main(int argc, char *argv[])
{
	int n, m;
	long long dist[500];
	cin >> n >> m;
	vector<pair<int, int>> adj[500];

	for (int i = 0; i < m; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		adj[A - 1].push_back({ B - 1, C });
	}
	bool minusCycle = false;
	fill(dist, dist + n, INT_MAX);
	dist[0] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (auto &p : adj[j])
			{
				int next = p.first;
				int d = p.second;
				if (dist[j] != INT_MAX && dist[next] > dist[j] + d)
				{
					dist[next] = dist[j] + d;
					if (i == n - 1)
						minusCycle = true; //마지막 경우에 사이클이 발생할 경우 
				}
			}
		}
	}
	if (minusCycle)
		cout << "-1" << "\n";
	else
	{
		for (int i = 1; i < n; i++)
		{
			if (dist[i] != INT_MAX)
				cout << dist[i] <<"\n";
			else
				cout << -1 << "\n";
		}
	}
}
*/
