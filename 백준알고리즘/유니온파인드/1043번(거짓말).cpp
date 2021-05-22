#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 51;
int parents[MAX];
int n, m, knowNum;
vector<int> v[MAX];

int Find(int x)
{
	if (parents[x] == x)
		return x;
	return x = Find(parents[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	parents[x] = y;
}

int main(void)
{
	fastio;
	cin >> n >> m;
	cin >> knowNum;
	vector<int> knowPep;
	
	for (int i = 0; i < knowNum; i++)
	{
		int tmp;
		cin >> tmp;
		knowPep.push_back(tmp);
	}

	for (int i = 1; i <= n; i++)
		parents[i] = i;

	for (int i = 0; i < m; i++)
	{
		int n;
		cin >> n;
		int prev, num;
		for (int j = 0; j < n; j++)
		{
			if (j >= 1)
			{
				prev = num;
				cin >> num;
				Union(prev, num);
			}
			else
				cin >> num;
			v[i].push_back(num);
		}
	}

	for (auto& list : v)
	{
		bool flag = false;
		for (auto &person : list)
		{
			if (flag)
				break;
			for (auto& t : knowPep)
			{
				if (Find(person) == Find(t))
				{
					flag = true;
					break;
				}
			}
		}
		if (flag)
			m--;
	}
	cout << m << "\n";
	
	return 0;
}
