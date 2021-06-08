#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 17;
int n;
int board[MAX][MAX];
int cache[16][1 << 16];


int main(void)
{
	fastio;
	cin >> n;

	function<int(int, int)> tsp = [&](int cur, int visited)
	{
		int result;
		int &ret = cache[cur][visited];
		if (ret != 0)
			return ret;

		if (visited == (1 << n) - 1)
		{
			if (board[cur][0] != 0)
				return board[cur][0];
			return 23002300;
		}
		ret = 23002300;

		for (int i = 0; i < n; i++)
		{
			if ((visited & 1 << i) || board[cur][i] == 0) //이미 방문했거나, 방문하지 못하는 경우
				continue;
			result = tsp(i, (visited | 1 << i)) + board[cur][i];
			if (result < ret)
				ret = result;
		}
		return ret;
	};

	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		cin >> board[i][j];

	cout << tsp(0, 1) << "\n";
}
