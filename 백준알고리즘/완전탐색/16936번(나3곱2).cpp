#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(int argc, char *argv[])
{
	int n, root;
	cin >> n;

	vector <ll> v(n);
	vector <ll> in(n);
	vector <ll> f(n, -1);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		ll x = v[i];
		int idx = lower_bound(v.begin(), v.end(), x * 2) - v.begin(); //곱하기 2값을 찾아준다
		if (idx < n && x * 2 == v[idx])
		{
			f[i] = idx;
			in[idx]++;
		}
		if (x % 3)
			continue;
		idx = lower_bound(v.begin(), v.end(), x / 3) - v.begin();
		if (idx < n && x / 3 == v[idx])
		{
			f[i] = idx;
			in[idx]++;
		}
	}

	for (int i = 0; i < n; i++)
		if (!in[i])
			root = i;
	
	for (; root != -1; root = f[root])
		cout << v[root] << ' ';
	
	return 0;
}
