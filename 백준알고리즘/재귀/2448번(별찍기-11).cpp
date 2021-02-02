#include<iostream>
#include<cstring>
#define MAX 3219
using namespace std;

int n;
char board[MAX][MAX*2];

void create_tree(int y, int x, int idx)
{
	if (idx == 3)
	{
		board[y][x] = '*';
		board[y + 1][x - 1] = '*';
		board[y + 1][x + 1] = '*';
		for (int i = x - 2; i <= x + 2; i++)
			board[y + 2][i] = '*';
		return;
	}

	create_tree(y, x, idx/2);
	create_tree(y + idx/2, x - idx/2, idx/2);
	create_tree(y + idx/2, x + idx/2, idx/2);
}
int main(int argc, char *argv[])
{
	cin >> n;
	memset(board, ' ', sizeof(board));
	create_tree(1, n, n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 2*n-1; j++)
			cout << board[i][j];
		cout << "\n";
	}
}
