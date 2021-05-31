#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 101;
const int INF = 23002300;
int itemValue[MAX]; 
int n, m, r;
int board[MAX][MAX];
int main(void)
{
	fastio;
	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++)
		cin >> itemValue[i];
	
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	{
		if (i == j)
			board[i][j] = 0;
		else
			board[i][j] = INF;
	}

	for (int i = 0; i < r; i++)
	{
		int stnode, ednode, d;
		cin >> stnode >> ednode >> d;
		board[stnode][ednode] = d;
		board[ednode][stnode] = d;
	}

	for (int j = 1; j <= n; j++)
	for (int i = 1; i <= n; i++)
	for (int k = 1; k <= n; k++)
	{
		if (board[i][j] + board[j][k] < board[i][k])
		{
			board[i][k] = board[i][j] + board[j][k];
		}
	}

	int ret = INT_MIN;
	for (int i = 1; i <= n; i++)
	{
		int tmp = 0;
		for (int j = 1; j <= n; j++)
		{
			if (board[i][j] <= m) 
				tmp += itemValue[j];
		}

		if (ret < tmp)
			ret = tmp;
	}

	cout << ret << "\n";
}
