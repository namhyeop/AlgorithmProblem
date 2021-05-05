#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
int testcase;
set<int> s;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> testcase;

	ll n;
	while (testcase--)
	{
		cin >> n;

		ll cnt = 0;

		for (int i = 1; i < 10; i++)
		{
			string tmp = "";
			s.clear();
			while (1)
			{
				tmp += to_string(i);
				ll test = stoll(tmp);
				if (test <= n && !s.count(test))
				{
					s.insert(test);
					cnt++;
				}
				else
					break;
			}
		}
		cout << cnt << "\n";
	}
}


