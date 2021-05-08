#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

int t;
ll a, b;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--)
	{
		cin >> a >> b;

		if (b == 1)
			cout << "NO" << "\n";
		else
		{
			cout << "YES" << "\n";
			
			if (b == 2)
				cout << a << ' ' << a * b * 2 << ' ' << a * (b * 2 + 1) << "\n";
			else
				cout << a << ' ' << a * (b - 1) << ' ' << a * b << "\n";
		}
	}
}
