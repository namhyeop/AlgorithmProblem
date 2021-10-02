#include<bits/stdc++.h>

using namespace std;

int n, m, k;
int r, c;
int note[12][12];
int board[42][42];

bool isvalid(int y, int x)
{
	for (int i = 0; i < r; i++)
	for (int j = 0; j < c; j++)
	{
		if (board[y + i][x + j] == 1 && note[i][j] == 1)
			return false;
	}

	for (int i = 0; i < r; i++)
	for (int j = 0; j < c; j++)
	{
		if (note[i][j] == 1)
			board[y + i][x + j] = 1;
	}
	return true;
}

void rotate()
{
	int tmpboard[12][12];

	for (int i = 0; i < r; i++)
	for (int j = 0; j < c; j++)
	{
		tmpboard[i][j] = note[i][j];
	}

	for (int i = 0; i < c; i++)
	for (int j = 0; j < r; j++)
	{
		note[i][j] = tmpboard[r - 1 - j][i];
	}
	swap(r, c);
}
int main(void)
{
	cin >> n >> m >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> r >> c;
		for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> note[i][j];

	
		for (int rot = 0; rot < 4; rot++)
		{
			bool ispaste = false;
			for (int y = 0; y <= n - r; y++)
			{
				if (ispaste)
					break;
				for (int x = 0; x <= m - c; x++)
				{
					if (isvalid(y, x))
					{
						ispaste = true;
						break;
					}
				}
			}
			if (ispaste)
				break;
			rotate();
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m;  j++)
	if (board[i][j] == 1)
		cnt++;

	cout << cnt << "\n";
	return 0;
}
