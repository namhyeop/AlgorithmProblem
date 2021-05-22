#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

int main(void)
{
	fastio;
	int n;
	cin >> n;

	vector<int> v(n);
	
	for (int i = 0; i < n; i++)
		cin >> v[i];

	vector<int> tmpV = v;
	sort(tmpV.begin(), tmpV.end());
	tmpV.erase(unique(tmpV.begin(), tmpV.end()), tmpV.end());
	
	vector<int>::iterator iter;
	for (auto a : v)
	{
		iter = lower_bound(tmpV.begin(), tmpV.end(), a);
		cout << iter - tmpV.begin() << " ";
	}
}
