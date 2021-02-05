#include<bits/stdc++.h>
#define MAX 11
using namespace std;

int n;
int whiteCase, blackCase;
int board[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int,int>> start;

bool is_valid(int y, int x)
{
	int ny = y - 1;
	int nx = x - 1;
	while (ny >= 0 && nx >= 0)
	{
		if (visited[ny][nx])
			return false;
		ny--;
		nx--;
	}

	ny = y - 1;
	nx = x + 1;
	
	while (ny >= 0 && nx < n)
	{
		if (visited[ny][nx])
			return false;
		ny--;
		nx++;
	}
	return true;
}
void search_black(int level, int cnt)
{
	blackCase = max(blackCase, cnt);

	for (int i = level; i < start.size(); i++)
	{
		int y = start[i].first;
		int x = start[i].second;

		if (y % 2 == 0 && x % 2 != 0)
			continue;
		if (y % 2 == 1 && x % 2 != 1)
			continue;

		if (!visited[y][x] && is_valid(y, x))
		{
			visited[y][x] = true;
			search_black(i + 1, cnt + 1);
			visited[y][x] = false;
		}
	}
}

void search_white(int level, int cnt)
{
	whiteCase = max(whiteCase, cnt);

	for (int i = level; i < start.size(); i++)
	{
		int y = start[i].first;
		int x = start[i].second;

		if (y % 2 == 0 && x % 2 != 1)
			continue;
		if (y % 2 == 1 && x % 2 != 0)
			continue;

		if (!visited[y][x] && is_valid(y, x))
		{
			visited[y][x] = true;
			search_white(i + 1, cnt + 1);
			visited[y][x] = false;
		}
	}
}
int main(int argc, char *argv[])
{
	cin >> n;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		cin >> board[i][j];
		if (board[i][j] == 1)
			start.push_back({ i, j });
	}
	
	search_black(0, 0);
	search_white(0, 0);

	cout << whiteCase + blackCase << "\n";

	return 0;
}
