#include<iostream>
#include<algorithm>

using namespace std;

char map[1000][1000];

int ans;
int moveY[] = { 1, -1, 0, 0 };
int moveX[] = { 0, 0, 1, -1 };

int dfs(int i, int j, int k)
{
	int a = 0;
	int b = 0;
	int r = k + (k & 1 ? -1 : 1);
	for (int d = 0; d < 4; d++)
	{
		if(d!= r)
		{
			int my = i + moveY[d];
			int mx = j + moveX[d];

			if (map[my][mx] == '#')
				continue;

			int tmp = dfs(my, mx, d) + 1;
      
      //재귀를 진행할수록 크기가 더 크면 개선 시킨다.
			if (a < tmp)
			{
				b = a;
				a = tmp;
			}
			else if (b < tmp)
				b = tmp;
		}
	}
	ans = max(ans, a + b);

	return a;
}

void sol(int Column, int Row)
{
	for (int i = 0; i < Row; i++)
	for (int j = 0; j < Column; j++)
	if (map[i][j] == '.')
	{
		dfs(i, j, 4);
		return;
	}
}

int main(int argc, char *argv[])
{
	int Testcase;
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		int Column;
		int Row;
		cin >> Column >> Row;

		for (int i = 0; i < Row; i++)
			cin >> map[i];
		ans = 0;
		sol(Column, Row);
		cout << "Maximum rope length is " << ans << ".\n";
	}
	return 0;
}
