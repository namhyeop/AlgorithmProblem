#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 101;
int board[MAX];
bool visited[MAX];
int n, m;
int ret;
int main(void)
{
	fastio;
	cin >> n >> m;

	for (int i = 0; i < n + m; i++)
	{
		int start, end;
		cin >> start >> end;
		board[start] = end;
	}

	queue<pair<int, int>> q;
	q.push({ 1, 0 });
	visited[1] = true;

	while (!q.empty())
	{
		int cur = q.front().first;
		int curCnt = q.front().second;
		q.pop();

		if (cur == 100)
		{
			ret = curCnt;
			break;
		}

		for (int i = 1; i <= 6; i++)
		{
			int ntCur = cur + i;
			if (ntCur > 100)
				continue;

			if (board[ntCur] != 0)
			{
				ntCur = board[ntCur];
			}

			if (!visited[ntCur])
			{
				visited[ntCur] = true;
				q.push({ ntCur, curCnt + 1 });
			}
		}
	}
	cout << ret << "\n";
}
