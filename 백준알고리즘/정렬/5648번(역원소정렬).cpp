#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
vector<string> v;
vector<ll> ret;

int main()
{
	cin >> n;

	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		reverse(v[i].begin(), v[i].end());
		ret.push_back(stoll(v[i]));
	}

	sort(ret.begin(), ret.end());

	for (int i = 0; i < n; i++)
		cout << ret[i] << "\n";
	
	return 0;
}
