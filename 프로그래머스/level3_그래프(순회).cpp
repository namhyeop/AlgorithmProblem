#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

int solution(int n, vector<vector<int>> results)
{
	int answer = 0;
	vector<vector<bool>> board(n + 1, vector<bool>(n + 1, false));

	for (auto r : results)
		board[r[0]][r[1]] = true;

	for (int k = 1; k <= n; k++) //i가 k를 이기고 k가 j를 이기면 i는 j를 이긴다.
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	{
		if (board[i][k] && board[k][j])
			board[i][j] = true;
	}

	for (int i = 1; i <= n; i++)
	{
		int count = 0;
		for (int j = 1; j <= n; j++)
		{
			if (board[i][j] || board[j][i])
				count++;
		}
		if (count == n - 1)
			answer++;
	}
	return answer;
}
