#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 21;
int visited[MAX];
int t,n,half;
pair<double, double> p[MAX];

double cal()
{
	pair<double, double> pos = { 0, 0 };
	pair<double, double> neg = { 0, 0 };
	for (int i = 0; i < n; i++)
	{
		if (visited[i])
		{
			pos.first += p[i].first;
			pos.second += p[i].second;
		}
		else
		{
			neg.first += p[i].first;
			neg.second += p[i].second;
		}
	}
	double dist_value = sqrt((pos.first - neg.first) * (pos.first - neg.first) + (pos.second - neg.second) * (pos.second - neg.second));
	return dist_value;
}

double dfs(int index, int level)
{
	if (level == half)
	{
		return cal();
	}
	double min_value = 40000000007.0;
	for (int i = index; i < n; i++)
	{
		visited[i] = 1;
		min_value = min(min_value, dfs(i + 1, level + 1));
		visited[i] = 0;
	}
	return min_value;
}

int main(void)
{
	fastio;
	cin >> t;

	cout << fixed;
	cout.precision(7);
	while (t--)
	{
		cin >> n;
		memset(visited, 0, sizeof(visited));
		half = n / 2;
		for (int i = 0; i < n; i++)
		{
			cin >> p[i].first >> p[i].second;
		}
		cout << dfs(0, 0) << "\n";
	}
}
