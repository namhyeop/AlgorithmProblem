#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
char board[15][15];
int ret;

bool range_check(int y, int x, int r)
{
	for (int i = -1; i <= 1; i += 2)
	{
		int nextY = y + r*i;
		int nextX = x + r*i;

		if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m)
			return false;
	}
	return true;
}

int secondCrux()
{
	int ret = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == '.')
				continue;

			int k = 1;

			while (range_check(i, j, k) && board[i + k][j] == '#' && board[i][j + k] == '#'
				&& board[i - k][j] == '#' && board[i][j - k] == '#')
				k++;
			
			ret = max(ret, 1 + (k-1) * 4);
		}
	}
	return ret;
}

int main(int argc, char*argv[])
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
		cin >> board[i][j];

	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	{
		if (board[i][j] == ' ')
			continue;

		int k = 0;
		while (range_check(i, j, k) && board[i + k][j] == '#'
			&& board[i][j + k] == '#' && board[i - k][j] == '#' && board[i][j - k] == '#')
		{
			board[i + k][j] = board[i][j + k] = board[i - k][j] = board[i][j - k] = '.';
			
			int tmp1 = 1 + k * 4;
			int tmp2 = secondCrux();

			ret = max(ret, tmp1 * tmp2);
			k++;
		}
		
		for (int l = 0; l < k; l++)
			board[i + l][j] = board[i][j + l] = board[i - l][j] = board[i][j - l] = '#';
	}

	cout << ret << "\n";

	return 0;
}
