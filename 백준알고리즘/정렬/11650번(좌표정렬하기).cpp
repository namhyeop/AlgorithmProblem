#include<bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first < b.first)
		return true;
	else if (a.first == b.first)
	{
		if (a.second < b.second)
			return true;
	}
	return false;
}

int main(void)
{
	cin >> n;

	v.resize(n, { 0,0});
	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++)
		cout << v[i].first << " " << v[i].second << "\n"; 

}
