#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 1001;
int n, m, cnt;
char board[MAX][MAX];
bool visited[MAX][MAX], flag;

set<pair<int,int>> s;

void DFS(int y, int x)
{
	auto check = [&](int y, int x) -> bool
	{
		auto iter = s.begin();
		for (; iter != s.end(); iter++)
		{
			pair<int, int> tmp = *iter;
			if (tmp.first == y && tmp.second == x)
				return true;
		}
		return false;
	};

	if (flag == true)
		return;
	
	int curY = y;
	int curX = x;

	visited[curY][curX] = true;
	s.insert({curY, curX});
	if (board[curY][curX] == 'U') curY--;
	else if (board[curY][curX] == 'D') curY++;
	else if (board[curY][curX] == 'L') curX--;
	else if (board[curY][curX] == 'R') curX++;

	if (check(curY, curX))
	{
		cnt++;
		flag = true;
		return;
	}

	if (!visited[curY][curX])
		DFS(curY, curX);
}

int main(void)
{
	fastio;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
		cin >> board[i][j];

	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	{
		if (!visited[i][j])
		{
			flag = false;
			s.clear();
			if (!visited[i][j])
				DFS(i, j);
		}
	}
	cout << cnt << "\n";
}
