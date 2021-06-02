#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 1e5 + 1;
int cache[5][5][MAX];
int ret = INT_MAX;
int arr[MAX];
int arrSize;
int main(void)
{
	fastio;
	
	auto getValue = [&](int a, int b) -> int
	{
		int diff = abs(a - b);
		if (a == 0 || b == 0)
			return 2;
		if (diff == 0)
			return 1;
		else if (diff == 1 || diff == 3)
			return 3;
		else if (diff == 2)
			return 4;
	};

	function<int(int,int,int)> dfs = [&](int left, int right, int idx) -> int
	{
		if (idx == arrSize)
			return 0;
		if (cache[left][right][idx] != -1)
			return cache[left][right][idx];

		int tmpleft = dfs(arr[idx], right, idx + 1) + getValue(arr[idx], left);
		int tmpright = dfs(left, arr[idx], idx + 1) + getValue(arr[idx], right);
		return cache[left][right][idx] = min(tmpleft, tmpright);
	};
	int n;
	while (cin >> n)
	{
		if (n == 0)
			break;
		arr[arrSize++] = n;
	}
	memset(cache, -1, sizeof(cache));
	cout << dfs(0, 0, 0);
}
