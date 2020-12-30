#include<iostream>
#include<vector>
#include<string>
#include<string.h>

using namespace std;

int moveY[4] = { -1, 1, 0, 0 };
int moveX[4] = { 0, 0, -1, 1 };
string board[100];
bool visited[100][100];
int N;
int ret;

void dfs(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int dy = y + moveY[i];
		int dx = x + moveX[i];

		if (dy < 0 || dy >= N || dx < 0 || dx >= N)
			continue;
		if (board[y][x] != board[dy][dx] || visited[dy][dx])
			continue;

		visited[dy][dx] = true;
		dfs(dy, dx);
	}
}
int main(int argc, char *argv[])
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> board[i];

	ret = 0;

	//적록색약이 아닌 경우의 깊이 우선 탐색
	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
	if (!visited[i][j])
	{
		visited[i][j] = true;
		dfs(i, j);
		ret++;
	}
	cout << ret << " ";
	
	ret = 0;
	memset(visited, false, sizeof(visited));

	//적록색약인 경우를 위해 board의 값이 그린일 경우 레드로 바꿔준다.
	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
	if (board[i][j] == 'G')
		board[i][j] = 'R';
	
	//적록색약인 경우의 깊이 우선 탐색
	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
	if (!visited[i][j])
	{
		visited[i][j] = true;
		dfs(i, j);
		ret++;
	}

	cout << ret << "\n";

	return 0;
}
