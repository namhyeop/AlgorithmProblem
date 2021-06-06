#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

int n;
vector<int> arr;
int main(void)
{
	fastio;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	int mDirector, sDirector;
	cin >> mDirector >> sDirector;

	ll ret = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		int unit = arr[i];
		
		if (arr[i] > 0)
		{
			unit = unit - mDirector;
			ret++;
		}
		if (unit > 0)
		{
			while(unit > sDirector)
			{
				ret += unit / sDirector;
				unit %= sDirector;
			}
			if (unit > 0)
				ret++;
		}
	}
	cout << ret << "\n";
}
