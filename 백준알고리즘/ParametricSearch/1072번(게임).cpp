#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

long long x, y;
int main(void)
{
	fastio;
	cin >> x >> y;

	long long z = 100 * y / x;

	if (z >= 99)
		cout << -1 << "\n";
	else
	{
		long long start = 0;
		long long end = x;

		while (start < end)
		{
			ll mid = (start + end) / 2;
			ll newRate = (100 * (y + mid) / (x + mid));
			if (newRate == z)
			{
				start = mid + 1;
			}
			else
			{
				end = mid;
			}
		}
		cout << end << "\n";
	}
}
