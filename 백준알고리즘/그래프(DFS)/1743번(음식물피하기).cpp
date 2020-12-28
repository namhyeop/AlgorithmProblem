#include<iostream>
#include<algorithm>
using namespace std;

bool board[101][101];
bool visited[101][101];
int height;
int width;
int moveY[] = { 0, 1, 0, -1 };
int moveX[] = { 1, 0, -1, 0 };

int dfs(int y, int x)
{
	int size = 1;
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + moveX[i];
		int ny = y + moveY[i];

		if (ny < 1 || ny > height || nx < 1 || nx > width)
			continue;
		if (!visited[ny][nx] && board[ny][nx])
			size += dfs(ny, nx);
	}
	return size;
}
int main(int argc, char *argv[])
{
	int garbageNum;

	cin >> height >> width >> garbageNum;
	for (int i = 0; i < garbageNum; i++)
	{
		int y;
		int x;
		cin >> y >> x;
		board[y][x] = true;
	}
	
	int ret = 0;
	for (int i = 1; i <= height; i++)
	for (int j = 1; j <= width; j++)
	if (!visited[i][j] && board[i][j])
		ret = max(ret, dfs(i, j));
	
	cout << ret << "\n";

	return 0;
}
