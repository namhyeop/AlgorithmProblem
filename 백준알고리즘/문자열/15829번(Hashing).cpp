#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

#define devidenum 1234567891

int main()
{
	fastio;

	ll num;
	cin >> num;
	string str;
	cin >> str;
	
	ll r = 1;
	ll ret = 0;
	for (int i = 0; i < str.length(); i++)
	{
		ret = (ret + (str[i] - 96) * r) % devidenum;
		r = (r * 31) % devidenum;
	}
	cout << ret % devidenum << '\n';
}
