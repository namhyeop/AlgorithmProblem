#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> adj;
vector<vector<bool>> visited;
int width; //가로
int height;//세로
int vegetableNum;//배추 수
int moveY[4] = { 1, -1, 0, 0 };
int moveX[4] = { 0, 0, -1, 1 };

void dfs(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + moveY[i];
		int nx = x + moveX[i];

		if (ny < 0 || ny >= height || nx < 0 || nx >= width)
			continue;
		
		if (adj[ny][nx] && !visited[ny][nx])
		{
			visited[ny][nx] = true;
			dfs(ny, nx);
		}
	}
}
int main(int argc, char * argv[])
{
	int Testcase;
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		cin >> width >> height >> vegetableNum;
		adj = vector<vector<int>>(height, vector<int>(width, 0));
		visited = vector<vector<bool>>(height, vector<bool>(width, false));
		
		int x;
		int y;
		int ret = 0;

		for (int i = 0; i < vegetableNum; i++)
		{
			cin >> x >> y;
			adj[y][x] = 1;
		}

		for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
		{
			int there = adj[i][j];
			if (adj[i][j] && !visited[i][j])
			{
				ret++;
				visited[i][j] = true;
				dfs(i, j);
			}
		}
		cout << ret << "\n";
	}
	return 0;
}
