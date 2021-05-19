#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

int x, y;
int gcd(int a, int b)
{
	return !b ? a : gcd(b, a%b);
}

int main(void)
{
	fastio;
	cin >> x >> y;

	int m = gcd(x, y);
	int ret = x + y - m;

	cout << ret << "\n";
	return 0;
}
