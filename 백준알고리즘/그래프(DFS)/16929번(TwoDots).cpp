#include<iostream>
#include<stack>
#include<string>
#include<string.h>

using namespace std;

int height;
int width;
string board[50];
int moveY[4] = {-1, 1, 0, 0};
int moveX[4] = { 0, 0, -1, 1 };
bool visited[50][50];
int cnt;
int startY, startX;
int ret;

int DFS(int y, int x)
{
	stack<pair<int, int>> s;
	s.push({ y, x });
	visited[y][x] = true;
	cnt++;

	for (int i = 0; i < 4; i++)
	{
		int nextY = y + moveY[i];
		int nextX = x + moveX[i];

		if (cnt >= 4 && (startY == nextY) && (startX == nextX))
		{
			ret = 1;
			break;
		}
	}

	while (!s.empty())
	{
		int curY = s.top().first;
		int curX = s.top().second;
		s.pop();

		for (int j = 0; j < 4; j++)
		{
			int nextY = curY + moveY[j];
			int nextX = curX + moveX[j];

			if (nextY >= 0 && nextY < height && nextX >= 0 && nextX < width)
			if (!visited[nextY][nextX] && (board[nextY][nextX] == board[y][x]) && ret != 1)
			{
				s.push({ nextY, nextX });
				DFS(nextY, nextX);
			}
		}
	}

	cnt--;
	return 0;
}

int main(int argc, char *argv[])
{
	cin >> height >> width;
	
	for (int i = 0; i < height; i++)
		cin >> board[i];
	
	for (startY = 0; startY < height; startY++)
	for (startX = 0; startX < width; startX++)
	{
		if (ret == 1)
			break;
		memset(visited, false, sizeof(visited));
		cnt = 0;
		DFS(startY, startX);
		//cout << cnt << "\n";
	}

	ret == 1 ? cout << "Yes" << "\n" : cout << "No" << "\n";
}
