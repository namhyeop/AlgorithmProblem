#include<bits/stdc++.h>

using namespace std;

int n,c;
map<int, int> m;
map<int, int> order;
vector<pair<int,int>> v;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return order[a.second] < order[b.second];
	return a.first > b.first;
}

int main()
{
	cin >> n >> c;
	map<int, int>::iterator it;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		m[tmp]++;
		if (order[tmp] == 0)
			order[tmp] = i + 1;
	}

	for (it = m.begin(); it != m.end(); it++)
		v.push_back({ it->second, it->first });

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].first; j++)
		{
			cout << v[i].second << " ";
		}
	}

	return 0;
}
