#include<bits/stdc++.h>

using namespace std;
char pattern[1025][1025];
void makePattern(int n, char pattern[][1025], int y, int x)
{
	if (n == 0)
	{
		pattern[y][x] = '*';
		return;
	}
	else if (n == 1)
	{
		pattern[y][x] = '*';
		pattern[y][x + 1] = '*';
		pattern[y + 1][x] = '*';
		return;
	}
	else if (n == 2)
	{
		for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (i == 0)
				pattern[y + i][x + j] = '*';
			else if (i == 1)
			{
				if (j % 2 == 0)
					pattern[y + i][x + j] = '*';
			}
			else if (i == 2)
			{
				if (j < 2)
					pattern[y + i][x + j] = '*';
			}
			else
				if (j == 0)
					pattern[y + i][x + j] = '*';
			
		}
		return;
	}

	int subSize = 1 << (n - 1);
	makePattern(n - 1, pattern, y, x);
	makePattern(n - 1, pattern, y, x + subSize);
	makePattern(n - 1, pattern, y+subSize, x);
}
int main()
{	
	int n,size;
	cin >> n;
	size = 1 << n;
	for (int i = 0; i <= size; i++) 
		fill(pattern[i], pattern[i] + size + 1, ' ');
	
	makePattern(n, pattern, 0, 0);
	for (int i = 0; i < size; i++)
	{
		pattern[i][size - i] = 0;
		cout << pattern[i] << '\n';
	}

	return 0;
}
