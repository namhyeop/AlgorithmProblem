#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

int n, m;
int ret = 0;
vector<int> v;

int main(void)
{
	fastio;
	cin >> n >> m;

	vector<int> pnum, snum;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		if (tmp > 0)
			pnum.push_back(tmp);
		else
			snum.push_back(-tmp);
	}

	sort(pnum.begin(), pnum.end());
	sort(snum.begin(), snum.end());

	for (int i = sz(pnum) - 1; i >= 0; i -= m)
		ret += pnum[i] * 2;

	for (int j = sz(snum) - 1; j >= 0; j -= m)
		ret += snum[j] * 2;

	ret -= max(sz(pnum) ? pnum.back() : 0, sz(snum) ? snum.back() : 0);
	cout << ret << "\n";

}
