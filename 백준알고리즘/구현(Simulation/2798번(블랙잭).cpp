#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

int n, m;
int ret = INT_MIN;
vector<int> v;

int main()
{
	fastio;
	cin >> n >> m;
	v.resize(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	for (int i = 0; i < sz(v); i++)
	for (int j = i + 1; j < sz(v); j++)
	for (int k = j + 1; k < sz(v); k++)
	{
		int sum = v[i] + v[j] + v[k];

		if (sum <= m)
		ret = max(ret, sum);
	}
	cout << ret << "\n";
}
