#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 1001;
int moveY[] = { -1, 1, 0, 0 };
int moveX[] = { 0, 0, -1, 1 };
char board[MAX][MAX];
bool visited[MAX][MAX];
int ret;
vector<pair<int,int>> v;
bool stop;
int n, m;

bool check(int r, int c)
{
	for (auto &a : v)
	if (a.first == r && a.second == c)
		return true;
	return false;
}

void DFS(int r, int c)
{
	if (stop)
		return;
	visited[r][c] = true;
	v.push_back({ r, c });

	int nextY = r;
	int nextX = c;
	
	if (board[nextY][nextX] == 'U')
		nextY--;
	else if (board[nextY][nextX] == 'D')
		nextY++;
	else if (board[nextY][nextX] == 'L')
		nextX--;
	else if (board[nextY][nextX] == 'R')
		nextX++;
	
	if (check(nextY, nextX))
	{
		stop = true;
		ret++;
		return;
	}
	
	if (!visited[nextY][nextX])
		DFS(nextY, nextX);
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
		stop = false;
		v.clear();
		if (!visited[i][j])
			DFS(i, j);
	}
	cout << ret << "\n";
}
