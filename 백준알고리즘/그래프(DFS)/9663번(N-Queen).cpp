#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 15;
int n;
int board[MAX];
int ret;
int main(void)
{
	fastio;
	cin >> n;
	function<void(int)> DFS = [&](int col)
	{
		auto isValid = [&](int col) -> bool
		{
			for (int i = 0; i < col; i++)
			if (board[col] == board[i] || col - i == abs(board[col] - board[i]))
				return false;
			return true;
		};

		if (col == n)
		{
			ret++;
			return;
		}

		for (int i = 0; i < n; i++)
		{
			board[col] = i;
			if (isValid(col))
			{
				DFS(col + 1);
			}
		}
	};
	DFS(0);
	cout << ret << "\n";
}
