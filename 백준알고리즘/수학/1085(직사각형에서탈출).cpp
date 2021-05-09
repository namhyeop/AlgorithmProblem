#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int ret = INT_MAX;
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	w = w - x;
	h = h - y;

	if (ret > x)
		ret = x;
	if (ret > y)
		ret = y;
	if (ret > w)
		ret = w;
	if (ret > h)
		ret = h;

	cout << ret << "\n";
}
