#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
#define int int64_t

const int MOD = (int)1e9 + 7;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int minv(int a, int b)
{
	if (a == 0 && b == 1)
		return 0;
	if (a == 1)
		return 1;
	return b - minv(b%a, a) * b / a;
}

int32_t main(void)
{
	fastio;
	int t, ans = 0;
	cin >> t;

	while (t--)
	{
		int a, b;
		cin >> a >> b;
		int g = gcd(a, b);
		a /= g;
		b /= g;
		ans = (ans + b * minv(a, MOD)) % MOD;
	}
	cout << ans << "\n";
}
