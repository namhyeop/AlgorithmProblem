#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 1001;
const int MOVE = 31;
int t, w;
int cache[3][MAX][MOVE];
int arr[MAX];

int search(int curTree, int cnt, int moveCnt)
{
	if (cnt == t)
		return 0;

	int &ret = cache[curTree][cnt][moveCnt];

	if (ret != -1)
		return ret;
	if (arr[cnt] == curTree)
	{
		if (moveCnt < w)
			return ret = max(1 + search(curTree, cnt + 1, moveCnt), search(3 - curTree, cnt + 1, moveCnt + 1));
		else
			return ret = 1 + search(curTree, cnt + 1, moveCnt);
	}
	else
	{
		if (moveCnt < w)
			return ret = max(search(curTree, cnt + 1, moveCnt), 1 + search(3 - curTree, cnt + 1, moveCnt + 1));
		else
			return ret = search(curTree, cnt + 1, moveCnt);
	}
}

int main(void)
{
	fastio;
	cin >> t >> w;

	for (int i = 0; i < t; i++)
		cin >> arr[i];
	memset(cache, -1, sizeof(cache));
	cout << search(1, 0, 0);
}

/*
#include<bits/stdc++.h>

using namespace std;
const int MAX = 1001;
int arr[MAX];
int cache[3][MAX][32];


int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m + 1; j++)
	{
		if (arr[i] == 1)
		{
			cache[1][i][j] = max(cache[1][i - 1][j] + 1, cache[2][i - 1][j - 1] + 1);
			cache[2][i][j] = max(cache[1][i - 1][j - 1], cache[2][i - 1][j]);
		}
		else
		{
			if (i == 1 && j == 1)
				continue;

			cache[1][i][j] = max(cache[1][i - 1][j], cache[2][i - 1][j - 1]);
			cache[2][i][j] = max(cache[1][i - 1][j - 1] + 1, cache[2][i - 1][j] + 1);
		}
	}

	int ret = 0;
	for (int i = 1; i <= m + 1; i++)
		ret = max(ret, max(cache[1][n][i], cache[2][n][i]));
	
	cout << ret << "\n";

	return 0;
}
*/
