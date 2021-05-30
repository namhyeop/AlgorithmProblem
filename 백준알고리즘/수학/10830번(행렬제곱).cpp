#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 6;
ll board[MAX][MAX];
ll tmpboard[MAX][MAX];
ll ret[MAX][MAX];
ll n, b;
int main(void)
{
	fastio;
	cin >> n >> b;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
		ret[i][i] = 1;
	}

	while (b > 0)
	{
		if (b % 2 == 1)
		{
			for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
			{
				tmpboard[k][i] = 0;
				for (int j = 0; j < n; j++)
				{
					tmpboard[k][i] += (ret[k][j] * board[j][i]);
				}
				tmpboard[k][i] %= 1000;
			}
			memcpy(ret, tmpboard, sizeof(tmpboard));
		}

		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				tmpboard[k][i] = 0;
				for (int j = 0; j < n; j++)
				{
					tmpboard[k][i] += (board[k][j] * board[j][i]);
				}
				tmpboard[k][i] %= 1000;
			}
		}
		memcpy(board, tmpboard, sizeof(tmpboard));
		b /= 2;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << ret[i][j] << " ";
		cout << "\n";
	}
}
