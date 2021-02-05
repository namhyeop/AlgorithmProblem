#include<bits/stdc++.h>

using namespace std;

int result;
string board[5];
bool visited[5][5];
bool colored[5][5];

int moveY[] = { -1, 1, 0, 0 };
int moveX[] = { 0, 0, -1, 1 };

void color(int y, int x)//연결을 확인하는 함수
{
	for (int k = 0; k < 4; k++)
	{
		int nextY = y + moveY[k];
		int nextX = x + moveX[k];

		if (nextY < 0 || nextY >= 5 | nextX < 0 || nextX >= 5)
			continue;

		if (!visited[nextY][nextX] || colored[nextY][nextX])
			continue;

		colored[nextY][nextX] = true;
		color(nextY, nextX);
	}
}

void func(int y, int x, int S, int Y, int cnt)
{
	if (Y >= 4) //총 7가지중 4가지가s여야하는데 y가 4이면 안되는 문구이므로 return
	{
		return;
	}

	if (cnt == 7 && S >= 4)
	{
		int colorCnt = 0;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (!visited[i][j] || colored[i][j])
					continue;

				
				colored[i][j] = true;
				colorCnt++;

				color(i, j);
			}
		}

		memset(colored, false, sizeof(colored));
		//cout << y << " " << x << " " << S << " " << Y << " " << cnt << "\n";
		result = (colorCnt == 1) ? result + 1 : result;
		
		return;
	}

	for (int i = y; i < 5; i++)
	{
		for (int j = (i == y ? x : 0); j < 5; j++)
		{
			if (visited[i][j])
				continue;

			visited[i][j] = true;

			func(i, j, board[i][j] == 'S' ? S + 1 : S, board[i][j] == 'Y' ? Y + 1 : Y, cnt + 1);
			visited[i][j] = false;
		}
	} 
}

int main(int argc, char *argv[])
{
	for (int i = 0; i < 5; i++)
	{
		cin >> board[i];
	}
	func(0,0,0,0,0);

	cout << result << "\n";

	return 0;
}
