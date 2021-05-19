#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 101;
int n, m;
vector<vector<int>> board(MAX, vector<int>(MAX, 0));

int ret = INT_MAX;

void floyd()
{
	for (int k = 1; k <= n; k++)
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	{
		if (i == j)
			continue;
		else if (board[i][k] && board[k][j])
		{
			if (board[i][j] == 0)
				board[i][j] = board[i][k] + board[k][j];
			else
				board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
		}
	}
}

int main()
{
	fastio;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		
		board[a][b] = board[b][a] = 1;
	}
	
	floyd();

	int pep;
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			sum += board[i][j];
		}

		if (ret > sum)
		{
			ret = sum;
			pep = i;
		}
	}

	cout << pep << "\n";

	return 0;
}
