#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;
const int MAX = 400;
int Testcase;



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		int n;
		cin >> n;
		string board[MAX];
		int y1, y2, x1, x2;
		bool flag = false;
		for (int i = 0; i < n; i++)
		{
			cin >> board[i];
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == '*' && flag == false)
				{
					y1 = i;
					x1 = j;
					flag = true;
				}
				else if(board[i][j] == '*' && flag == true)
				{
					y2 = i;
					x2 = j;
				}
			}
		}

		if (y1 == y2)
		{
			if (y1 - 1 >= 0)
			{
				board[y1 - 1][x1] = '*';
				board[y2 - 1][x2] = '*';
			}
			else
			{
				board[y1 + 1][x1] = '*';
				board[y2 + 1][x2] = '*';
			}
		}
		else if (x1 == x2)
		{
			if (x1 - 1 >= 0)
			{
				board[y1][x1 - 1] = '*';
				board[y2][x2 - 1] = '*';
			}
			else
			{
				board[y1][x1 + 1] = '*';
				board[y2][x2 + 1] = '*';
			}
		}
		else if (y1 < y2 && x1 < x2)
		{
			board[y1][x2] = '*';
			board[y2][x1] = '*';
		}
		else
		{
			board[y1][x2] = '*';
			board[y2][x1] = '*';
		}

		//cout << "\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << board[i][j];
			cout << "\n";
		}
	}
}
