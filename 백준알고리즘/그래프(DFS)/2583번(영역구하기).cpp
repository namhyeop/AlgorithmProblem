#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int heightSize;
int widthSize;
int moveY[4] = { -1, 1, 0, 0 };
int moveX[4] = { 0, 0, -1, 1 };
int board[100][100];
bool visited[100][100];
int ret;
vector<int> retArr;

void dfs(int y, int x)
{
	visited[y][x] = true;
	ret++;

	for (int i = 0; i < 4; i++)
	{
		int dy = y + moveY[i];
		int dx = x + moveX[i];

		if (dy < 0 || dy >= heightSize || dx < 0 || dx >= widthSize)
			continue;

		if (board[dy][dx] == 0 && !visited[dy][dx])
			dfs(dy, dx);
	}
}
int main(int argc, char *argv[])
{
	
	int cordSize;
	cin >> heightSize >> widthSize >> cordSize;

	for (int i = 0; i < cordSize; i++)
	{
		int x1;
		int y1;
		int x2;
		int y2;

		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++)
		for (int j = x1; j < x2; j++)
			board[i][j] = 1;
	}

	for (int i = 0; i < heightSize; i++)
	for (int j = 0; j < widthSize; j++)
	{
		if (board[i][j] == 0 && !visited[i][j])
		{
			ret = 0;
			dfs(i, j);
			retArr.push_back(ret);
		}
	}
	sort(retArr.begin(), retArr.end());

	cout << retArr.size()<< "\n";
	for (int i = 0; i < retArr.size(); i++)
		cout << retArr[i] << " ";
	cout << "\n";

	return 0;
}
