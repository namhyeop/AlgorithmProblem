#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

int Testcase;
int main(void)
{
	fastio;
	cin >> Testcase;

	while (Testcase--)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		
		for (int i = 0; i < v.size(); i++)
			cin >> v[i];

		int cnt = 0;
		int minValue = *min_element(v.begin(), v.end());
		for (auto a : v)
		if (a > minValue)
			cnt++;

		cout << cnt << "\n";
	}
}

