#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

int testcase;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> testcase;
	
	int n;
	while (testcase--)
	{
		cin >> n;

		if (n == 1)
		{
			cout << 1 << "\n";
			continue;
		}
		if (n == 2)
		{
			cout << -1 << "\n";
			continue;
		}

		vector<vector<int>> v(n, vector<int>(n, 0));

		vector<int> board(n*n, 0);

		int idx = 1;
		for (int i = 0; i < n * n; i += 2)
		{
			board[i] = idx;
			idx++;
		}
		for (int i = 1; i < n * n; i += 2)
		{
			board[i] = idx;
			idx++;
		}

		int cur = 0;
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			v[i][j] = board[cur];
			cur++;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << v[i][j] << " ";
			}
			cout << "\n";
		}
	}
}
