#include<bits/stdc++.h>
#define MAX 101
using namespace std;

int n,x,y,d,g;
int moveY[] = { 0, -1, 0, 1 };
int moveX[] = { 1, 0, -1, 0 };

bool board[MAX][MAX];
int main(void)
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y >> d >> g;

		vector<int> dir;
		dir.push_back(d);
		for (int i = 1; i <= g; i++)
		{
			int len = (int)dir.size() - 1;
			for (int j = len; j >= 0; j--)
				dir.push_back((dir[j] + 1) % 4);
		}

		board[y][x] = true;

		for (int i = 0; i < dir.size(); i++)
		{
			y = y + moveY[dir[i]];
			x = x + moveX[dir[i]];
			board[y][x] = true;
		}
	}

	int ret = 0;
	for (int i = 0; i < 100; i++)
	for (int j = 0; j < 100; j++)
	{
		if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1])
			ret++;
	}

	cout << ret << "\n";
}
