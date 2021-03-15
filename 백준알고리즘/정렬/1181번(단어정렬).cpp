#include<bits/stdc++.h>

using namespace std;

int n;
vector<string> v;

bool cmp(string a, string b)
{
	if (a.size() != b.size())
		return a.size() < b.size();
	return a < b;
}

int main(void)
{
	cin >> n;
	v.resize(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	sort(v.begin(), v.end(), cmp);
	v.resize(unique(v.begin(), v.end())- v.begin());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";

	return 0;
}
