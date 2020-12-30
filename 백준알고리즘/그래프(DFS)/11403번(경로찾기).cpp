#include<iostream>
#include<string.h>
#define MAX 101

using namespace std;

int N;
int board[MAX][MAX];
bool visited[MAX];

void dfs(int here)
{
	for (int i = 0; i < N; i++)
	{
		if (board[here][i] && !visited[i])
		{
			visited[i] = true;
			dfs(i);
		}
	}
}

int main(int argc, char *argv[])
{
	cin >> N;


	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
		cin >> board[i][j];

	for (int i = 0; i < N; i++)
	{
		memset(visited, false, sizeof(visited));
		dfs(i);

		for (int j = 0; j < N; j++)
		{
			if (visited[j])
				board[i][j] = 1;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << board[i][j] << " ";
		cout << "\n";
	}

	return 0;
}
