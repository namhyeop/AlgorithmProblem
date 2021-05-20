#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

int t;

int GCD(int a, int b) //최대 공약수
{
	if (a % b == 0)
		return b;
	return GCD(b, a % b);
}

int LCM(int a, int b)//최소 공배수
{
	return (a * b) / GCD(a , b);
}
int main(void)
{
	fastio;
	cin >> t;

	while (t--)
	{
		int m, n, x, y;
		cin >> m >> n >> x >> y;

		int maxYear = LCM(m,n);
		
		while (1)
		{
			if (x > maxYear || (x - 1) % n + 1 == y)
				break;
			x += m;
		}

		if (x > maxYear)
			cout << -1 << "\n";
		else
			cout << x << "\n";
	}
	return 0;
}
